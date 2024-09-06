#include "someip_communicator.hpp"
#include <vsomeip/vsomeip.hpp>
#include <vector>
#include <cstring>  // For std::memcpy
#include <thread>   // Include for std::thread
#include <iostream> // For std::cerr

SomeIpCommunicator::SomeIpCommunicator() {
    app_ = vsomeip::runtime::get()->create_application("VehicleSimulatorApp");
}

void SomeIpCommunicator::initialize() {
    if (!app_->init()) {
        std::cerr << "Failed to initialize vsomeip application." << std::endl;
        return;
    }

    vsomeip::service_t service_id = 0x1234;
    vsomeip::instance_t instance_id = 0x5678;

    // Register handlers for incoming requests
    app_->register_message_handler(service_id, instance_id, 0x0421, [this](const std::shared_ptr<vsomeip::message>& msg) {
        handleMessage(msg, 0x0421);
    });

    app_->register_message_handler(service_id, instance_id, 0x0422, [this](const std::shared_ptr<vsomeip::message>& msg) {
        handleMessage(msg, 0x0422);
    });

    app_->register_message_handler(service_id, instance_id, 0x0423, [this](const std::shared_ptr<vsomeip::message>& msg) {
        handleMessage(msg, 0x0423);
    });

    app_->offer_service(service_id, instance_id);

    std::thread([this]() {
        try {
            app_->start();
        } catch (const std::exception& e) {
            std::cerr << "Exception during vsomeip application start: " << e.what() << std::endl;
        }
    }).detach();
}

void SomeIpCommunicator::sendSpeed(int speed) {
    sendData(0x0421, speed);
}

void SomeIpCommunicator::sendRpm(int rpm) {
    sendData(0x0422, rpm);
}

void SomeIpCommunicator::sendTemperature(int temperature) {
    sendData(0x0423, temperature);
}

void SomeIpCommunicator::sendData(uint16_t method_id, int value) {
    auto msg = vsomeip::runtime::get()->create_request();
    msg->set_service(0x1234);
    msg->set_instance(0x5678);
    msg->set_method(method_id);

    auto payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> data(sizeof(int));
    std::memcpy(data.data(), &value, sizeof(int));
    payload->set_data(data);
    msg->set_payload(payload);

    app_->send(msg);
}

void SomeIpCommunicator::handleMessage(const std::shared_ptr<vsomeip::message>& msg, uint16_t method_id) {
    // Handle incoming messages if needed
}

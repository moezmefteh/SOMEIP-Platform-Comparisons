#include "someip_dashboard_communicator.hpp"
#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <thread>
#include <cstring>  // For std::memcpy

SomeIpDashboardCommunicator::SomeIpDashboardCommunicator() {
    app_ = vsomeip::runtime::get()->create_application("DashboardApp");
}

void SomeIpDashboardCommunicator::initialize() {
    if (!app_->init()) {
        std::cerr << "Failed to initialize vsomeip application." << std::endl;
        return;
    }

    vsomeip::service_t service_id = 0x1234;
    vsomeip::instance_t instance_id = 0x5678;

    // Register handlers for incoming messages
    app_->register_message_handler(service_id, instance_id, 0x0421, [this](const std::shared_ptr<vsomeip::message>& msg) {
        handleMessage(msg, "Speed");
    });

    app_->register_message_handler(service_id, instance_id, 0x0422, [this](const std::shared_ptr<vsomeip::message>& msg) {
        handleMessage(msg, "RPM");
    });

    app_->register_message_handler(service_id, instance_id, 0x0423, [this](const std::shared_ptr<vsomeip::message>& msg) {
        handleMessage(msg, "Temperature");
    });

    app_->request_service(service_id, instance_id);

    std::thread([this]() {
        try {
            app_->start();
        } catch (const std::exception& e) {
            std::cerr << "Exception during vsomeip application start: " << e.what() << std::endl;
        }
    }).detach();
}

void SomeIpDashboardCommunicator::handleMessage(const std::shared_ptr<vsomeip::message>& msg, const std::string& type) {
    auto payload = msg->get_payload();
    if (payload) {
        // Assuming payload->get_data() returns a pointer to the raw data
        const std::vector<vsomeip::byte_t> data(payload->get_data(), payload->get_data() + payload->get_length());

        if (data.size() == sizeof(int)) {
            int value;
            std::memcpy(&value, data.data(), sizeof(int));
            updateDisplay(type, value);
        } else {
            std::cerr << "Unexpected payload size." << std::endl;
        }
    } else {
        std::cerr << "No payload found in message." << std::endl;
    }
}
void SomeIpDashboardCommunicator::updateDisplay(const std::string& type, int value) {
    // Implementation code here
}

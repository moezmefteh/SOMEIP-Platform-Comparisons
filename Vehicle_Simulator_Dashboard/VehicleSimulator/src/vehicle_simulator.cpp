#include "vehicle_simulator.hpp"
#include "ui_vehicle_simulator.h"
#include <thread>
#include <cstring>
#include <vsomeip/vsomeip.hpp> // Include vSomeIP header

VehicleSimulator::VehicleSimulator(QWidget *parent)
    : QWidget(parent), ui(new Ui::VehicleSimulator), app_(vsomeip::runtime::get()->create_application("VehicleSimulator")) {
    ui->setupUi(this);

    connect(ui->speedSlider, &QSlider::valueChanged, this, &VehicleSimulator::speedChanged);
    connect(ui->rpmSlider, &QSlider::valueChanged, this, &VehicleSimulator::rpmChanged);
    connect(ui->temperatureSlider, &QSlider::valueChanged, this, &VehicleSimulator::temperatureChanged);

    setupSomeIP(); // Setup SOME/IP service
}

VehicleSimulator::~VehicleSimulator() {
    delete ui;
}

void VehicleSimulator::setupSomeIP() {
    app_->init();

    vsomeip::service_t service_id = 0x1234;
    vsomeip::instance_t instance_id = 0x5678;
    vsomeip::eventgroup_t eventgroup_id = 0x4242;

    app_->register_message_handler(service_id, instance_id, 0x0421, [](const std::shared_ptr<vsomeip::message>& msg) {
        // Handle incoming messages
    });

    app_->offer_service(service_id, instance_id);

    std::thread([this]() {
        app_->start();
    }).detach();
}

void VehicleSimulator::speedChanged(int value) {
    std::shared_ptr<vsomeip::message> msg = vsomeip::runtime::get()->create_request();
    msg->set_service(0x1234);
    msg->set_instance(0x5678);
    msg->set_method(0x0421);

    std::shared_ptr<vsomeip::payload> pl = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> payload_data(sizeof(int));
    std::memcpy(payload_data.data(), &value, sizeof(int));
    pl->set_data(payload_data);
    msg->set_payload(pl);

    app_->send(msg);
}

void VehicleSimulator::rpmChanged(int value) {
    // TODO: Implement code to handle RPM changes
}

void VehicleSimulator::temperatureChanged(int value) {
    // TODO: Implement code to handle temperature changes
}

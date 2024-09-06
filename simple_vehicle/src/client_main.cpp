#include "speed_client.hpp"
#include <iostream>
#include <thread>

SpeedClient::SpeedClient() : app_(vsomeip::runtime::get()->create_application("SpeedClient")) {}

void SpeedClient::init() {
    app_->init();
    app_->request_service(SERVICE_ID, INSTANCE_ID);
    app_->subscribe(SERVICE_ID, INSTANCE_ID, EVENTGROUP_ID);
    app_->register_message_handler(SERVICE_ID, INSTANCE_ID, EVENT_ID,
                                   std::bind(&SpeedClient::on_speed_received, this, std::placeholders::_1));
    app_->start();
}

void SpeedClient::on_speed_received(const std::shared_ptr<vsomeip::message>& msg) {
    auto payload = msg->get_payload();
    const vsomeip::byte_t* data = payload->get_data();
    int speed = static_cast<int>(data[0]);

    std::cout << "Received speed: " << speed << std::endl;
}

int main() {
    SpeedClient client;
    client.init();

    // Keep the main thread alive to process incoming messages
    std::this_thread::sleep_for(std::chrono::hours(1));

    return 0;
}

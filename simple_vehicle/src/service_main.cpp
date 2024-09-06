#include "speed_service.hpp"
#include <iostream>
#include <string>
#include <thread>

SpeedService::SpeedService() : app_(vsomeip::runtime::get()->create_application("SpeedService")) {}

void SpeedService::init() {
    app_->init();
    app_->offer_service(SERVICE_ID, INSTANCE_ID);
    app_->offer_event(SERVICE_ID, INSTANCE_ID, EVENT_ID, {EVENTGROUP_ID});
    app_->start();
}

void SpeedService::send_speed() {
    std::string input;
    while (true) {
        std::cout << "Enter speed: ";
        std::getline(std::cin, input);

        int speed = std::stoi(input);

        std::shared_ptr<vsomeip::payload> payload = vsomeip::runtime::get()->create_payload();
        std::vector<vsomeip::byte_t> data;
        data.push_back(static_cast<vsomeip::byte_t>(speed));
        payload->set_data(data);

        // Correct notify call with required parameters
        app_->notify(SERVICE_ID, INSTANCE_ID, EVENT_ID, payload, true);
    }
}

int main() {
    SpeedService service;
    service.init();

    // Run send_speed in a separate thread
    std::thread speed_thread(&SpeedService::send_speed, &service);
    speed_thread.join(); // Wait for the thread to finish (which it won't)

    return 0;
}

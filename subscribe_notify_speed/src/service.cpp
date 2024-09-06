// service.cpp
#include "service.hpp"
#include <iostream>
#include <cstring>  
#include <thread>

#define SERVICE_ID      0x1234
#define INSTANCE_ID     0x5678
#define EVENTGROUP_ID   0x5678
#define EVENT_ID        0x5678

SomeIPService::SomeIPService() 
    : app_(vsomeip::runtime::get()->create_application("service")),
      speed_(0),
      running_(true) {}

void SomeIPService::start() {
    app_->init();
    std::cout << "[SERVICE] Application initialized" << std::endl;

    // Register event group and event with correct parameters
    std::set<vsomeip::eventgroup_t> event_groups = {EVENTGROUP_ID};
    app_->offer_event(SERVICE_ID, INSTANCE_ID, EVENT_ID, event_groups, vsomeip::event_type_e::ET_FIELD, std::chrono::milliseconds::zero(), true, false);
    std::cout << "[SERVICE] Offered event group " << std::hex << EVENTGROUP_ID << " for service " << SERVICE_ID << std::endl;

    // Start the application
    std::cout << "[SERVICE] Application started" << std::endl;
    app_->start();

    notify_thread_ = std::thread(&SomeIPService::notify_speed, this);
    std::cout << "[SERVICE] Notify thread started" << std::endl;
}

void SomeIPService::stop() {
    running_ = false;
    if (notify_thread_.joinable()) {
        notify_thread_.join();
    }
    app_->stop();
}

void SomeIPService::notify_speed() {
    std::cout << "[SERVICE] Starting to notify speed..." << std::endl;
    while (running_) {
        // Simulate speed change
        speed_ += 10;
        if (speed_ > 100) speed_ = 0;

        // Create message to send the updated speed
        std::shared_ptr<vsomeip::payload> pl = vsomeip::runtime::get()->create_payload();
        std::vector<vsomeip::byte_t> payload_data(sizeof(int));
        std::memcpy(payload_data.data(), &speed_, sizeof(int));
        pl->set_data(payload_data);
        
        // Notify clients with extracted constants
        app_->notify(SERVICE_ID, INSTANCE_ID, EVENT_ID, pl, true);
        std::cout << "[SERVICE] Sent speed update: " << speed_ << std::endl;
        
        // Log the current state
        std::cout << "[SERVICE] Current speed value: " << speed_ << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "[SERVICE] Stopped notifying speed." << std::endl;
}

int main() {
    SomeIPService service;
    service.start();
    std::this_thread::sleep_for(std::chrono::seconds(30)); // Run for 30 seconds
    service.stop();
    return 0;
}

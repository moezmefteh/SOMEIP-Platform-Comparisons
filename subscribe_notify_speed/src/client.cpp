// client.cpp
#include "client.hpp"
#include <iostream>
#include <cstring>
#include <thread>

#define SERVICE_ID      0x1234
#define INSTANCE_ID     0x5678
#define EVENTGROUP_ID   0x5678
#define EVENT_ID        0x5678
#define MAJOR_VERSION   1
#define EVENT_HANDLE    0x0001

SomeIPClient::SomeIPClient() 
    : app_(vsomeip::runtime::get()->create_application("client")) {}

void SomeIPClient::start() {
    app_->init();
    std::cout << "[CLIENT] Application initialized" << std::endl;

    // Register the event handler
    app_->register_message_handler(SERVICE_ID, INSTANCE_ID, EVENT_ID,
        std::bind(&SomeIPClient::on_speed_event, this, std::placeholders::_1));
    std::cout << "[CLIENT] Registered message handler for service " << std::hex << SERVICE_ID << ", event group " << EVENTGROUP_ID << std::endl;

    // Subscribe to the speed event
    app_->subscribe(SERVICE_ID, INSTANCE_ID, EVENTGROUP_ID, MAJOR_VERSION, EVENT_ID);
    std::cout << "[CLIENT] Subscribed to speed event for service " << SERVICE_ID << ", event group " << EVENTGROUP_ID << std::endl;

    // Start the client
    std::cout << "[CLIENT] Application started" << std::endl;
    app_->start();
}

void SomeIPClient::on_speed_event(const std::shared_ptr<vsomeip::message>& msg) {
    std::shared_ptr<vsomeip::payload> pl = msg->get_payload();
    int speed;
    std::memcpy(&speed, pl->get_data(), sizeof(int));
    std::cout << "[CLIENT] Received speed update: " << speed << std::endl;}

int main() {
    SomeIPClient client;
    client.start();
    std::this_thread::sleep_for(std::chrono::seconds(30)); // Run for 30 seconds
    return 0;
}

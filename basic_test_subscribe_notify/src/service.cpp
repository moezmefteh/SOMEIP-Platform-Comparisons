#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include <vsomeip/vsomeip.hpp>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421
#define SAMPLE_EVENTGROUP_ID 0x4465
#define SAMPLE_EVENT_ID 0x8778

std::shared_ptr<vsomeip::payload> payload;
std::shared_ptr<vsomeip::application> app;

void on_message(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();

    std::cout << "SERVICE: Receiving response" << std::endl;

    // Get payload
    std::stringstream ss;
    for (vsomeip::length_t i = 0; i < l; i++) {
        ss << std::setw(2) << std::setfill('0') << std::hex
           << (int)*(its_payload->get_data() + i) << " ";
    }

    std::cout << "SERVICE: Received message with Client/Session ["
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_client() << "/"
              << std::setw(4) << std::setfill('0') << std::hex << _request->get_session() << "] "
              << ss.str() << std::endl;

    // Create response
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    for (int i = 9; i >= 0; i--) {
        its_payload_data.push_back(i % 256);
    }
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
}

void notify_event() {
    const vsomeip::byte_t its_data[] = {0x10};
    payload = vsomeip::runtime::get()->create_payload();
    payload->set_data(its_data, sizeof(its_data));

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Periodic notification every 2 seconds
        app->notify(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENT_ID, payload);
        std::cout << "SERVICE: Notifying event..." << std::endl;
    }
}

int main() {
    app = vsomeip::runtime::get()->create_application("hello_world_service");
    app->init();
    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID, on_message);
    app->offer_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);

    std::set<vsomeip::eventgroup_t> its_groups;
    its_groups.insert(SAMPLE_EVENTGROUP_ID);
    app->offer_event(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENT_ID, its_groups);

    std::thread notify_thread(notify_event); // Start notification thread

    app->start();

    notify_thread.join(); // Wait for the notification thread to finish (in case of termination)
}

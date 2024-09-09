#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include <condition_variable>
#include <vsomeip/vsomeip.hpp>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421
#define SAMPLE_EVENTGROUP_ID 0x4465
#define SAMPLE_EVENT_ID 0x8778

std::shared_ptr<vsomeip::application> app;
std::mutex mutex;
std::condition_variable condition;

void on_event(const std::shared_ptr<vsomeip::message> &_notification) {
    std::stringstream its_message;
    its_message << "CLIENT: received a notification for event ["
                << std::setw(4) << std::setfill('0') << std::hex
                << _notification->get_service() << "."
                << std::setw(4) << std::setfill('0') << std::hex
                << _notification->get_instance() << "."
                << std::setw(4) << std::setfill('0') << std::hex
                << _notification->get_method() << "] to Client/Session ["
                << std::setw(4) << std::setfill('0') << std::hex
                << _notification->get_client() << "/"
                << std::setw(4) << std::setfill('0') << std::hex
                << _notification->get_session() << "] = ";
    std::shared_ptr<vsomeip::payload> its_payload = _notification->get_payload();
    its_message << "(" << std::dec << its_payload->get_length() << ") ";
    for (uint32_t i = 0; i < its_payload->get_length(); ++i)
        its_message << std::hex << std::setw(2) << std::setfill('0')
                    << (int)its_payload->get_data()[i] << " ";
    std::cout << its_message.str() << std::endl;
}

void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
    std::cout << "CLIENT: Service ["
              << std::setw(4) << std::setfill('0') << std::hex << _service << "." << _instance
              << "] is "
              << (_is_available ? "available." : "NOT available.")
              << std::endl;
    if (_is_available) {
        app->subscribe(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENTGROUP_ID);
    }
    condition.notify_one();
}

int main() {
    app = vsomeip::runtime::get()->create_application("hello_world_client");
    app->init();
    std::cout << "CLIENT: Application initialized." << std::endl;

    app->register_availability_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, on_availability);
    app->request_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);

    app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_EVENT_ID, on_event);

    // Corrected subscription handling
    std::cout << "CLIENT: Client subscribed." << std::endl;

    // Start the application event loop
    app->start();

    std::thread sender([] {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock);
    });

    sender.join(); // Wait for the sender thread to complete
}

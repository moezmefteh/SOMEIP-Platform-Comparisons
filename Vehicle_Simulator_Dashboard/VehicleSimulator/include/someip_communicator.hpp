#ifndef SOMEIP_COMMUNICATOR_HPP
#define SOMEIP_COMMUNICATOR_HPP

#include <vsomeip/vsomeip.hpp> // Include vSomeIP header

class SomeIpCommunicator {
public:
    SomeIpCommunicator();
    void initialize();
    void sendSpeed(int speed);
    void sendRpm(int rpm);
    void sendTemperature(int temperature);

private:
    std::shared_ptr<vsomeip::application> app_;
    void sendData(uint16_t method_id, int value); // Declare sendData function
    void handleMessage(const std::shared_ptr<vsomeip::message>& msg, uint16_t method_id); // Declare handleMessage function
};

#endif // SOMEIP_COMMUNICATOR_HPP

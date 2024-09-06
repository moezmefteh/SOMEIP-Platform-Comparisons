// include/speed_client.hpp
#ifndef SPEED_CLIENT_HPP
#define SPEED_CLIENT_HPP

#include <vsomeip/vsomeip.hpp>

#define SERVICE_ID 0x1234
#define INSTANCE_ID 0x5678
#define EVENT_ID 0x4321
#define EVENTGROUP_ID 0x8765

class SpeedClient {
public:
    SpeedClient();
    void init();
    void on_speed_received(const std::shared_ptr<vsomeip::message>& msg);

private:
    std::shared_ptr<vsomeip::application> app_;
};

#endif // SPEED_CLIENT_HPP

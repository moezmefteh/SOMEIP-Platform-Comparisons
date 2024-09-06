// include/speed_service.hpp
#ifndef SPEED_SERVICE_HPP
#define SPEED_SERVICE_HPP

#include <vsomeip/vsomeip.hpp>

#define SERVICE_ID 0x1234
#define INSTANCE_ID 0x5678
#define EVENT_ID 0x4321
#define EVENTGROUP_ID 0x8765

class SpeedService {
public:
    SpeedService();
    void init();
    void send_speed();

private:
    std::shared_ptr<vsomeip::application> app_;
};

#endif // SPEED_SERVICE_HPP

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <vsomeip/vsomeip.hpp>

class SomeIPClient {
public:
    SomeIPClient();
    void start();
    void on_speed_event(const std::shared_ptr<vsomeip::message>& msg);

private:
    std::shared_ptr<vsomeip::application> app_;
};

#endif // CLIENT_HPP

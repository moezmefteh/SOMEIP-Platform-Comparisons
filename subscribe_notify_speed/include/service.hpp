#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <vsomeip/vsomeip.hpp>
#include <thread>
#include <atomic>

class SomeIPService {
public:
    SomeIPService();
    void start();
    void stop();
    void notify_speed();

private:
    std::shared_ptr<vsomeip::application> app_;
    std::atomic<int> speed_;
    std::thread notify_thread_;
    bool running_;
};

#endif // SERVICE_HPP

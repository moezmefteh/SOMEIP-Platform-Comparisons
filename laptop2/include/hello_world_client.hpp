#ifndef HELLO_WORLD_CLIENT_HPP
#define HELLO_WORLD_CLIENT_HPP

#include <vsomeip/vsomeip.hpp>
#include "HelloWorld.hpp"

class HelloWorldClient {
public:
    HelloWorldClient();
    virtual ~HelloWorldClient();

    bool init();
    void start();
    void stop();

private:
    void on_response(const std::string &response);
    std::shared_ptr<vsomeip::application> app_;
    std::shared_ptr<vsomeip::client> client_;
};

#endif // HELLO_WORLD_CLIENT_HPP

#ifndef HELLO_WORLD_SERVICE_HPP
#define HELLO_WORLD_SERVICE_HPP

#include <vsomeip/vsomeip.hpp>
#include "HelloWorld.hpp" // Ensure this matches the generated file

class HelloWorldService : public example::HelloWorld {
public:
    HelloWorldService();
    virtual ~HelloWorldService();
    
    bool init();
    void start();
    void terminate();

private:
    void on_request(const std::shared_ptr<example::HelloWorld> &request);

    std::shared_ptr<vsomeip::service> service_;
};

#endif // HELLO_WORLD_SERVICE_HPP

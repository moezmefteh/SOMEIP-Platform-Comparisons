#include <iostream> // For std::cout and std::endl
#include <vsomeip/vsomeip.hpp> // Include VSOME/IP headers
#include "HelloWorld.hpp"

// Implement the HelloWorldService class
class HelloWorldService : public v1::com::example::helloworld::HelloWorld {
public:
    HelloWorldService() {}

    void sayHello() override {
        // Implementation of the sayHello method
        std::cout << "Hello World from Service!" << std::endl;
    }
};

int main(int argc, char** argv) {
    // Create and initialize a VSOME/IP application
    vsomeip::runtime::init(argc, argv);

    // Create an instance of the service
    HelloWorldService service;

    // Create a VSOME/IP application object and offer the service
    vsomeip::application application("HelloWorldService");
    application.init();
    application.offer_service(1, 1, 1, 1); // Parameters might need to be adjusted
    application.start();

    return 0;
}

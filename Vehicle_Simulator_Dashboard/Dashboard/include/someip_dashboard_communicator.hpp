#ifndef SOMEIP_DASHBOARD_COMMUNICATOR_HPP
#define SOMEIP_DASHBOARD_COMMUNICATOR_HPP

#include <vsomeip/vsomeip.hpp>
#include <memory>
#include <vector>

class SomeIpDashboardCommunicator {
public:
    SomeIpDashboardCommunicator();
    void initialize();

private:
    void handleMessage(const std::shared_ptr<vsomeip::message>& msg, const std::string& type);
    void updateDisplay(const std::string& type, int value);

    std::shared_ptr<vsomeip::application> app_;
};

#endif // SOMEIP_DASHBOARD_COMMUNICATOR_HPP

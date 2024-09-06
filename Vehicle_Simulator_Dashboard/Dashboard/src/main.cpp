#include <QApplication>
#include "dashboard.hpp"
#include "someip_dashboard_communicator.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Dashboard window;
    window.show();

    SomeIpDashboardCommunicator someIpCommunicator;
    someIpCommunicator.initialize();

    return app.exec();
}

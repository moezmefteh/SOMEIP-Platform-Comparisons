#include <QApplication>
#include "dashboard.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Dashboard dashboard;
    dashboard.show();

    // Connect SOME/IP communication to update dashboard
    // Example: connect(someIpReceiver, &SomeIpReceiver::speedReceived, &dashboard, &Dashboard::updateSpeed);

    return a.exec();
}

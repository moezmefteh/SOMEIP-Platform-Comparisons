#include <QApplication>
#include <iostream>
#include "someip_communicator.hpp"

int main(int argc, char *argv[]) {
    // Initialize the SOME/IP communicator
    SomeIpCommunicator someIpCommunicator;
    someIpCommunicator.initialize();

    // Variables to store user input
    int speed, rpm, temperature;

    while (true) {
        std::cout << "Enter speed (or -1 to exit): ";
        std::cin >> speed;
        if (speed == -1) break; // Exit condition for the loop
        someIpCommunicator.sendSpeed(speed);

        std::cout << "Enter RPM: ";
        std::cin >> rpm;
        someIpCommunicator.sendRpm(rpm);

        std::cout << "Enter temperature: ";
        std::cin >> temperature;
        someIpCommunicator.sendTemperature(temperature);
    }

    return 0;
}

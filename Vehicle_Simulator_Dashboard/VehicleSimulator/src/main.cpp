#include <QApplication>
#include <QWidget>
#include "ui_vehicle_simulator.h"  // Include the generated UI header
#include "vehicle_simulator.hpp"   // Include your own header

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  // Create QApplication object

    QWidget window;                // Create a QWidget
    Ui::VehicleSimulator ui;       // Create a UI object
    ui.setupUi(&window);           // Set up the UI

    // Connect UI signals to slots
    QObject::connect(ui.speedSlider, &QSlider::valueChanged, [&](int value) {
        // Your code here to handle speedSlider value changes
    });

    QObject::connect(ui.rpmSlider, &QSlider::valueChanged, [&](int value) {
        // Your code here to handle rpmSlider value changes
    });

    QObject::connect(ui.temperatureSlider, &QSlider::valueChanged, [&](int value) {
        // Your code here to handle temperatureSlider value changes
    });

    window.show();                 // Show the main window

    return app.exec();             // Enter the event loop
}

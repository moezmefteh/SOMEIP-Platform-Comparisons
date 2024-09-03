#include "vehicle_simulator.hpp"  // Include the header file for the VehicleSimulator class
#include "ui_vehicle_simulator.h" // Include the header file for the generated UI components

// Constructor definition
VehicleSimulator::VehicleSimulator(QWidget *parent)
    : QWidget(parent), ui(new Ui::VehicleSimulator) { // Initialize the QWidget base class and create a new UI object
    ui->setupUi(this); // Set up the UI components using the `ui` pointer

    // Connect the valueChanged signal of the sliders to the corresponding slot functions
    connect(ui->speedSlider, &QSlider::valueChanged, this, &VehicleSimulator::speedChanged);
    connect(ui->rpmSlider, &QSlider::valueChanged, this, &VehicleSimulator::rpmChanged);
    connect(ui->temperatureSlider, &QSlider::valueChanged, this, &VehicleSimulator::temperatureChanged);
}

// Destructor definition
VehicleSimulator::~VehicleSimulator() {
    delete ui; // Clean up the UI object to free memory
}

// Slot function to handle changes in the speed slider
void VehicleSimulator::speedChanged(int value) {
    // TODO: Implement code to handle speed changes
}

// Slot function to handle changes in the RPM slider
void VehicleSimulator::rpmChanged(int value) {
    // TODO: Implement code to handle RPM changes
}

// Slot function to handle changes in the temperature slider
void VehicleSimulator::temperatureChanged(int value) {
    // TODO: Implement code to handle temperature changes
}

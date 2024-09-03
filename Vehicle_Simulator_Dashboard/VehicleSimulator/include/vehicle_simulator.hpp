#ifndef VEHICLE_SIMULATOR_HPP
#define VEHICLE_SIMULATOR_HPP

#include <QWidget> // Include the QWidget class from Qt for creating GUI components

QT_BEGIN_NAMESPACE
namespace Ui { class VehicleSimulator; } // Forward declaration of the Ui namespace and VehicleSimulator class
QT_END_NAMESPACE

// Define the VehicleSimulator class, which inherits from QWidget
class VehicleSimulator : public QWidget {
    Q_OBJECT // This macro is necessary for any class that uses Qt's signals and slots mechanism

public:
    // Constructor with an optional parent widget
    explicit VehicleSimulator(QWidget *parent = nullptr);
    
    // Destructor
    ~VehicleSimulator();

private slots:
    // Slots that will be connected to signals from the UI components
    void speedChanged(int value); // Slot for handling changes in speed slider
    void rpmChanged(int value);   // Slot for handling changes in RPM slider
    void temperatureChanged(int value); // Slot for handling changes in temperature slider

private:
    Ui::VehicleSimulator *ui; // Pointer to the UI components
};

#endif // VEHICLE_SIMULATOR_HPP

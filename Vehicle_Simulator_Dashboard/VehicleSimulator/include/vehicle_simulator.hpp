#ifndef VEHICLE_SIMULATOR_HPP
#define VEHICLE_SIMULATOR_HPP

#include <QWidget>
#include <vsomeip/vsomeip.hpp> // Include vSomeIP header

QT_BEGIN_NAMESPACE
namespace Ui { class VehicleSimulator; }
QT_END_NAMESPACE

class VehicleSimulator : public QWidget {
    Q_OBJECT

public:
    explicit VehicleSimulator(QWidget *parent = nullptr);
    ~VehicleSimulator();

public slots:
    void speedChanged(int value);
    void rpmChanged(int value);
    void temperatureChanged(int value);

private:
    Ui::VehicleSimulator *ui;
    std::shared_ptr<vsomeip::application> app_; // Declare app_ as a member variable
    void setupSomeIP();
};

#endif // VEHICLE_SIMULATOR_HPP

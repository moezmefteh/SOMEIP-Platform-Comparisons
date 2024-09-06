#ifndef DASHBOARD_HPP
#define DASHBOARD_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <vsomeip/vsomeip.hpp> // Include vSomeIP library

class Dashboard : public QWidget {
    Q_OBJECT

public:
    Dashboard(QWidget *parent = nullptr);

public slots:
    void updateSpeed(int speed);
    void updateRpm(int rpm);
    void updateTemperature(int temperature);

private:
    QLabel *m_speedLabel;
    QLabel *m_rpmLabel;
    QLabel *m_temperatureLabel;

    void initializeSomeIP(); // Method to initialize SOME/IP client
    std::shared_ptr<vsomeip::application> app; // SOME/IP application instance
    
};

#endif // DASHBOARD_HPP

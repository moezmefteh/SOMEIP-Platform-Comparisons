#ifndef DASHBOARD_HPP
#define DASHBOARD_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

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
};

#endif // DASHBOARD_HPP

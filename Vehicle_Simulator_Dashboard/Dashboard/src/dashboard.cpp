#include "dashboard.hpp"

Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent) {
    m_speedLabel = new QLabel("Speed: 0", this);
    m_rpmLabel = new QLabel("RPM: 0", this);
    m_temperatureLabel = new QLabel("Temperature: 0", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_speedLabel);
    layout->addWidget(m_rpmLabel);
    layout->addWidget(m_temperatureLabel);
    setLayout(layout);
}

void Dashboard::updateSpeed(int speed) {
    m_speedLabel->setText("Speed: " + QString::number(speed));
}

void Dashboard::updateRpm(int rpm) {
    m_rpmLabel->setText("RPM: " + QString::number(rpm));
}

void Dashboard::updateTemperature(int temperature) {
    m_temperatureLabel->setText("Temperature: " + QString::number(temperature));
}

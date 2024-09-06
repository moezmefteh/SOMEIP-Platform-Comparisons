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

    initializeSomeIP(); // Initialize SOME/IP communication
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
void Dashboard::initializeSomeIP() {
    // Create and initialize the SOME/IP application
    app = vsomeip::runtime::get()->create_application("DashboardApp");

    app->init();

    // Define the service, instance, and method IDs
    const vsomeip::service_t service_id = 0x1234;
    const vsomeip::instance_t instance_id = 0x5678;
    const vsomeip::method_t method_id = 0x0421;

    // Register a message handler for receiving SOME/IP messages
    app->register_message_handler(
        service_id, instance_id, method_id,
        [this](std::shared_ptr<vsomeip::message> msg) {
            // Assuming the payload contains the speed, RPM, and temperature in order
            auto payload = msg->get_payload();
            vsomeip::length_t length = payload->get_length();
            if (length >= 3 * sizeof(int)) {
                const int* data = reinterpret_cast<const int*>(payload->get_data());

                // Update the dashboard with received values
                updateSpeed(data[0]);
                updateRpm(data[1]);
                updateTemperature(data[2]);
            }
        }
    );

    // Start the application
    app->start();
}
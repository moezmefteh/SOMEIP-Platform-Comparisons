/********************************************************************************
** Form generated from reading UI file 'VehicleSimulator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHICLE_SIMULATOR_H
#define UI_VEHICLE_SIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VehicleSimulator
{
public:
    QVBoxLayout *verticalLayout;
    QSlider *rpmSlider;
    QSlider *speedSlider;
    QSlider *temperatureSlider;
    QSlider *fuelSlider;
    QPushButton *leftIndicatorButton;
    QPushButton *rightIndicatorButton;

    void setupUi(QWidget *VehicleSimulator)
    {
        if (VehicleSimulator->objectName().isEmpty())
            VehicleSimulator->setObjectName(QString::fromUtf8("VehicleSimulator"));
        VehicleSimulator->resize(600, 400);
        verticalLayout = new QVBoxLayout(VehicleSimulator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rpmSlider = new QSlider(VehicleSimulator);
        rpmSlider->setObjectName(QString::fromUtf8("rpmSlider"));
        rpmSlider->setOrientation(Qt::Horizontal);
        rpmSlider->setMinimum(0);
        rpmSlider->setMaximum(100);

        verticalLayout->addWidget(rpmSlider);

        speedSlider = new QSlider(VehicleSimulator);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setOrientation(Qt::Horizontal);
        speedSlider->setMinimum(0);
        speedSlider->setMaximum(240);

        verticalLayout->addWidget(speedSlider);

        temperatureSlider = new QSlider(VehicleSimulator);
        temperatureSlider->setObjectName(QString::fromUtf8("temperatureSlider"));
        temperatureSlider->setOrientation(Qt::Horizontal);
        temperatureSlider->setMinimum(0);
        temperatureSlider->setMaximum(100);

        verticalLayout->addWidget(temperatureSlider);

        fuelSlider = new QSlider(VehicleSimulator);
        fuelSlider->setObjectName(QString::fromUtf8("fuelSlider"));
        fuelSlider->setOrientation(Qt::Horizontal);
        fuelSlider->setMinimum(0);
        fuelSlider->setMaximum(100);

        verticalLayout->addWidget(fuelSlider);

        leftIndicatorButton = new QPushButton(VehicleSimulator);
        leftIndicatorButton->setObjectName(QString::fromUtf8("leftIndicatorButton"));

        verticalLayout->addWidget(leftIndicatorButton);

        rightIndicatorButton = new QPushButton(VehicleSimulator);
        rightIndicatorButton->setObjectName(QString::fromUtf8("rightIndicatorButton"));

        verticalLayout->addWidget(rightIndicatorButton);


        retranslateUi(VehicleSimulator);

        QMetaObject::connectSlotsByName(VehicleSimulator);
    } // setupUi

    void retranslateUi(QWidget *VehicleSimulator)
    {
        VehicleSimulator->setWindowTitle(QCoreApplication::translate("VehicleSimulator", "Vehicle Simulator", nullptr));
        leftIndicatorButton->setText(QCoreApplication::translate("VehicleSimulator", "Left Indicator", nullptr));
        rightIndicatorButton->setText(QCoreApplication::translate("VehicleSimulator", "Right Indicator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VehicleSimulator: public Ui_VehicleSimulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICLE_SIMULATOR_H

/********************************************************************************
** Form generated from reading UI file 'Dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QGridLayout *gridLayout;
    QLabel *speedLabel;
    QLabel *speedGauge;
    QLabel *rpmLabel;
    QLabel *rpmGauge;
    QLabel *tempLabel;
    QLabel *tempGauge;
    QLabel *fuelLabel;
    QLabel *fuelGauge;
    QLabel *leftIndicator;
    QLabel *rightIndicator;

    void setupUi(QWidget *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName(QString::fromUtf8("Dashboard"));
        Dashboard->resize(500, 400);
        gridLayout = new QGridLayout(Dashboard);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        speedLabel = new QLabel(Dashboard);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        speedLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(speedLabel, 0, 1, 1, 1);

        speedGauge = new QLabel(Dashboard);
        speedGauge->setObjectName(QString::fromUtf8("speedGauge"));
        speedGauge->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(speedGauge, 1, 1, 1, 1);

        rpmLabel = new QLabel(Dashboard);
        rpmLabel->setObjectName(QString::fromUtf8("rpmLabel"));
        rpmLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(rpmLabel, 0, 0, 1, 1);

        rpmGauge = new QLabel(Dashboard);
        rpmGauge->setObjectName(QString::fromUtf8("rpmGauge"));
        rpmGauge->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(rpmGauge, 1, 0, 1, 1);

        tempLabel = new QLabel(Dashboard);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));
        tempLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(tempLabel, 0, 2, 1, 1);

        tempGauge = new QLabel(Dashboard);
        tempGauge->setObjectName(QString::fromUtf8("tempGauge"));
        tempGauge->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(tempGauge, 1, 2, 1, 1);

        fuelLabel = new QLabel(Dashboard);
        fuelLabel->setObjectName(QString::fromUtf8("fuelLabel"));
        fuelLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(fuelLabel, 0, 3, 1, 1);

        fuelGauge = new QLabel(Dashboard);
        fuelGauge->setObjectName(QString::fromUtf8("fuelGauge"));
        fuelGauge->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(fuelGauge, 1, 3, 1, 1);

        leftIndicator = new QLabel(Dashboard);
        leftIndicator->setObjectName(QString::fromUtf8("leftIndicator"));
        leftIndicator->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(leftIndicator, 2, 1, 1, 1);

        rightIndicator = new QLabel(Dashboard);
        rightIndicator->setObjectName(QString::fromUtf8("rightIndicator"));
        rightIndicator->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(rightIndicator, 2, 2, 1, 1);


        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QWidget *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dashboard", nullptr));
        speedLabel->setText(QCoreApplication::translate("Dashboard", "Speed", nullptr));
        speedGauge->setText(QCoreApplication::translate("Dashboard", "0 km/h", nullptr));
        rpmLabel->setText(QCoreApplication::translate("Dashboard", "RPM", nullptr));
        rpmGauge->setText(QCoreApplication::translate("Dashboard", "0", nullptr));
        tempLabel->setText(QCoreApplication::translate("Dashboard", "Temp", nullptr));
        tempGauge->setText(QCoreApplication::translate("Dashboard", "C", nullptr));
        fuelLabel->setText(QCoreApplication::translate("Dashboard", "Fuel", nullptr));
        fuelGauge->setText(QCoreApplication::translate("Dashboard", "E", nullptr));
        leftIndicator->setText(QCoreApplication::translate("Dashboard", "LEFT", nullptr));
        rightIndicator->setText(QCoreApplication::translate("Dashboard", "RIGHT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DASHBOARD_H

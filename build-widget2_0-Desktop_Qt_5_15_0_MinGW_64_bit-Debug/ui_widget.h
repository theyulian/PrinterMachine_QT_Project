/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QComboBox *comboPuerto;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *EnviarPushButton;
    QLineEdit *lineEdit;
    QSlider *PWMSlider;
    QLabel *labelSlider;
    QLabel *label_2;
    QLabel *label_llegada;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_max;
    QLabel *label_Min;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        comboPuerto = new QComboBox(Widget);
        comboPuerto->setObjectName(QString::fromUtf8("comboPuerto"));
        comboPuerto->setGeometry(QRect(190, 150, 69, 22));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 120, 49, 16));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 150, 75, 24));
        EnviarPushButton = new QPushButton(Widget);
        EnviarPushButton->setObjectName(QString::fromUtf8("EnviarPushButton"));
        EnviarPushButton->setGeometry(QRect(290, 200, 75, 24));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 200, 113, 22));
        PWMSlider = new QSlider(Widget);
        PWMSlider->setObjectName(QString::fromUtf8("PWMSlider"));
        PWMSlider->setGeometry(QRect(160, 250, 301, 16));
        PWMSlider->setMaximum(100);
        PWMSlider->setOrientation(Qt::Horizontal);
        labelSlider = new QLabel(Widget);
        labelSlider->setObjectName(QString::fromUtf8("labelSlider"));
        labelSlider->setGeometry(QRect(290, 280, 49, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 380, 111, 16));
        label_llegada = new QLabel(Widget);
        label_llegada->setObjectName(QString::fromUtf8("label_llegada"));
        label_llegada->setGeometry(QRect(200, 400, 49, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 380, 61, 16));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 380, 61, 16));
        label_max = new QLabel(Widget);
        label_max->setObjectName(QString::fromUtf8("label_max"));
        label_max->setGeometry(QRect(380, 400, 49, 16));
        label_Min = new QLabel(Widget);
        label_Min->setObjectName(QString::fromUtf8("label_Min"));
        label_Min->setGeometry(QRect(480, 400, 49, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Puerto:", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Abrir", nullptr));
        EnviarPushButton->setText(QCoreApplication::translate("Widget", "Enviar", nullptr));
        labelSlider->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "RPM desde STM32", nullptr));
        label_llegada->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "RPM Max", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "RPM Min", nullptr));
        label_max->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_Min->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

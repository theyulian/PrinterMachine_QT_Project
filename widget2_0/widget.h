#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer *timer;

private slots:
    void on_pushButton_clicked();
    void readSerial();

    void on_PWMSlider_sliderMoved(int position);

    void on_EnviarPushButton_clicked();
    void DatatoSend(QString Data);
    void MyTimerSlot();


private:
    Ui::Widget *ui;
    QSerialPort *ttl;
    int max=0;
    int min=50000;
};
#endif // WIDGET_H

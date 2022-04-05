#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QSerialPort>
#include <QSerialPortInfo>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"programa iniciado";

    ttl = new QSerialPort(this);

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        QString pname = serialPortInfo.portName();
        qDebug() << pname;
        ui->comboPuerto->addItem(pname);
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));
    timer->start(100);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::MyTimerSlot()
{
    QString a_="a";
    QByteArray a=a_.toUtf8();
    ttl->write(a);

}


void Widget::on_pushButton_clicked()
{
    QString ttl_port_name = ui->comboPuerto->currentText();
    if(ui->pushButton->text()=="Abrir"){
        ttl->setPortName(ttl_port_name);
        ttl->setBaudRate(QSerialPort::Baud115200);
        ttl->setDataBits(QSerialPort::Data8);
        ttl->setParity(QSerialPort::NoParity);
        ttl->setFlowControl(QSerialPort::NoFlowControl);
        ttl->setStopBits(QSerialPort::OneStop);
        ttl->open(QSerialPort::ReadWrite);
        QObject::connect(ttl,SIGNAL(readyRead()), this, SLOT(readSerial()));

        ui->pushButton->setText("Cerrar");
    }
    else{
        ttl->close();
        QObject::disconnect(ttl,SIGNAL(readyRead()), this, SLOT(readSerial()));
        ui->pushButton->setText("Abrir");
    }
}


void Widget::on_EnviarPushButton_clicked()
{
    if(ttl->isOpen()){
        QString texto = ui->lineEdit->text();
        QByteArray datos = texto.toUtf8();
        qDebug()<<"texto "<<texto;
        qDebug()<<"ba "<<datos;
        DatatoSend(texto);
        //ttl->write(datos);
        int valor = texto.toInt();
        ui->PWMSlider->setValue(valor);
        ui->labelSlider->setText(texto);
    }
    else{
        QMessageBox msg;
        msg.setText("Puerto cerrado");
        msg.exec();
    }
}

void Widget::readSerial()
{
    int i =0,Data,dat1,dat2,dat3,dat4;

        QByteArray buffer = ttl->readAll();

        if(buffer.at(0)==02){
            qDebug() <<"Inicio de Protocolo";
            qDebug() <<"Tamaño:"<<buffer.at(1);
            dat1=buffer.at(2)<<24;
            dat2=buffer.at(3)<<16;
            dat3=buffer.at(4)<<8;
            dat4=buffer.at(5);
            Data=dat1+dat2+dat3+dat4;
            qDebug() <<"Datos:"<< Data;

            QString Datos=QString::number(Data);
            ui->label_llegada->setText(Datos);
            if(Data>max){
                max=Data;
                QString maxi=QString::number(max);
                ui->label_max->setText(maxi);
            }
            else if(Data<min && Data>0){
                min=Data;
                QString mini=QString::number(min);
                ui->label_Min->setText(mini);
            }

            i=buffer.at(2)+buffer.at(3)+buffer.at(4)+buffer.at(5)+3+2;
            if(buffer.at(6)==i){
                qDebug() <<"CRC"<<buffer.at(6);
            }else{
                qDebug()<<"CRC mal";
            }
            if(buffer.at(7)==3){
                qDebug()<<"Fin protocolo";
            }else{
                qDebug()<<"Algo Salio Mal";
            }
        }
   /* QByteArray buffer = ttl->readAll();
    qDebug()<<buffer;
    if(buffer.at(0)=='2'){
        qDebug()<<"Inicio de Protocolo";
    }*/
}


void Widget::on_PWMSlider_sliderMoved(int position)
{
    if(ttl->isOpen()){
        QString texto = QString::number(position);
        QByteArray datos = texto.toUtf8();

        //ttl->write(datos);
        ui->labelSlider->setText(texto);


    }
    else{
        QMessageBox msg;
        msg.setText("Puerto cerrado");
        msg.exec();
    }
}
void Widget::DatatoSend(QString data){
    QString ini = "2";
    QString end = "3";
    int iniaux=ini.toInt();
    int dataaux=data.toInt();
    int endaux=end.toInt();
    int pariaux=iniaux+dataaux+endaux;
    QString pari=QString::number(pariaux);
    int tamaux=1+3+data.length()+pari.length()+1;

    QString tam=QString::number(tamaux);
    QString aux="0";
    if(tamaux<10){
        tam=aux+aux+tam;
    }
    else if(tamaux<100){
        tam=aux+tam;
    }
    QString packet=ini+tam+data+pari+end;

    QByteArray datotosend=packet.toUtf8();
    qDebug()<<packet;
    ttl->write(datotosend);

}

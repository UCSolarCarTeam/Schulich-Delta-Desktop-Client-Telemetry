#pragma once

#include "I_ConnectionService.h"
#include <QObject>
#include <QSerialPort>
#include <QString>
#include <QTime>

class SerialPortConnectionService : public I_ConnectionService
{
   Q_OBJECT
public:
   SerialPortConnectionService();
   SerialPortConnectionService(QString portName, int baudrate);
   QString checkStatus();
   bool communicateWithPort(QString message,
                            QString expectedResponse,
                            int maxWaitTime); //in milliseconds

public slots:
   bool connectDataSource();
   void disconnectDataSource();

private:
   QSerialPort serialPort_ = new QSerialPort();
   QString status_;
   void setStatus(QString);
   QString failed();
   void succeeded();
};


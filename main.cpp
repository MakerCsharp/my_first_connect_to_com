#include <QCoreApplication>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Available serial ports:";
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            qDebug() << "Port:" << info.portName();
            qDebug() << "Description:" << info.description();
            qDebug() << "Manufacturer:" << info.manufacturer();
            qDebug() << "Serial number:" << info.serialNumber();
            qDebug() << "System location:" << info.systemLocation();
            qDebug() << "Vendor ID:" << info.vendorIdentifier();
            qDebug() << "Product ID:" << info.productIdentifier();
            qDebug() << "Busy:" << (info.isBusy() ? "Yes" : "No");
            qDebug() << "-----------------------------------";
        }

        // Открытие последовательного порта (замените "COM1" на имя вашего порта)
        QSerialPort serialPort;
        serialPort.setPortName("/dev/pts/3");

        if (serialPort.open(QIODevice::ReadWrite)) {
            qDebug() << "Serial port opened successfully.";

            // Здесь вы можете добавить код для взаимодействия с открытым портом

            // Закрытие порта после использования
            serialPort.close();
            qDebug() << "Serial port closed.";
        } else {
            qDebug() << "Error opening serial port:" << serialPort.errorString();
        }
    return a.exec();
}

#include "toolkit.h"

QPixmap Base64ToImage(QByteArray bytearray, QString SavePath)
{
    QByteArray Ret_bytearray;
    Ret_bytearray = QByteArray::fromBase64(bytearray);
    QBuffer buffer(&Ret_bytearray);
    buffer.open(QIODevice::WriteOnly);
    QPixmap imageresult;
    imageresult.loadFromData(Ret_bytearray);
    if(SavePath != NULL)
    {
        qDebug() << "save image：" << SavePath;
        imageresult.save(SavePath);
    }
    return imageresult;
}

QString SetCiphertext(QString &str, int beginIndex, int endIndex) //起点0
{
    for(int i = beginIndex; i <= endIndex; i++){
        str.replace(i,1,"*");
    }
    return str;
}

void Delay(int stopTime)
{
    QTime dieTime = QTime::currentTime().addMSecs(stopTime);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents);
}

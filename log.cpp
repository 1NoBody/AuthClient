#include "log.h"

LogFile *LogFile::log = NULL;

LogFile *LogFile::GetLogFile(QString fileName)
{
    if (log == NULL){
        log = new LogFile(fileName);
    }
    return log;
}

void LogFile::SaveLog(QString logText)
{
    QTextStream out(&file);//对文件进行写入
    out << QDateTime::currentDateTime().toLocalTime().toString() << '\n' << logText;
}

LogFile::LogFile(QString fileName)
    :file(fileName)
{
    if(file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append) == false){
        qDebug() << "logfile open fail";
    }
}

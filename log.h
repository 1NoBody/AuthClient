/*************************************************************
 * log.h
 * Function: 简单log日志
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

class LogFile
{
public:
    static LogFile * GetLogFile(QString fileName = QString("log.txt"));
    void SaveLog(QString logText);

private:
    LogFile(QString fileName);
    static LogFile *log;
    QFile file;
};

#endif // LOG_H

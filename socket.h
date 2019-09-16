/*************************************************************
 * socket.h
 * Function: 配置连接所需的文件、以客户端的形式跟认证机通信
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QtNetwork>
#include <QDebug>
#include <QtScript>

#include "toolkit.h"
#include "jsonpack.h"
#include "wbase.h"

#include "jsk_json.h"
using namespace JSK;


class Socket : public QObject
{
    Q_OBJECT

public:
    Socket();
    ~Socket();

    static QTcpSocket *TcpSocket;
    static JSONObject *Json;

    typedef enum{   //当前包
        PackInit,
        PackHead,
        PackBody,
        PackAll  // 单包
    }PACKTYPE;

    static bool Connect(); //连接认证机

private:
    QByteArray  *TcpRecvByteArray; // 接收的QByteArray数据

    PACKTYPE    PackType; //当前包是包头？ or 包体？ or 单包？
    int         Jsize;  //包体大小
    int         JType;  //业务类型
    QString     MessageJson; //json数据

    QTimer *Reconnect_Timer;

    //读取配置文件
    static bool ReadConfig(QStringList &configList); // configList 存储配置信息

    void ReadIdCard();
    void AuthSuccess();
    void AuthFailed();



private slots:
    void DisplayError_slot(QAbstractSocket::SocketError);  //显示错误
    void ConnectSuccess_slot();
    void ReadMessage_slot();  //接收数据
    void Reconnect_slot();

};

#endif // SOCKET_H

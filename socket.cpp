#include "socket.h"
#include "wreadvoucher.h"
#include "wauthsuccess.h"
#include "wauthfailure.h"
#include "wauth.h"
#include "wmessagebox.h"
#include "wwait.h"
#include "wmachinecode.h"
#include "log.h"


QTcpSocket *Socket::TcpSocket       = new QTcpSocket;
JSONObject *Socket::Json            = new JSONObject;


Socket::Socket()
{
    //socket
    connect(TcpSocket,SIGNAL(readyRead()),this,SLOT(ReadMessage_slot()));
    connect(TcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(DisplayError_slot(QAbstractSocket::SocketError))); //检测连接失败
    connect(TcpSocket,SIGNAL(connected()),this,SLOT(ConnectSuccess_slot())); //检测连接成功

    //成员初始化
    this->TcpRecvByteArray  = new QByteArray;
    this->PackType = PackInit;
    this->Jsize = 0;
    this->JType = Init;

    //重连定时器
    this->Reconnect_Timer = new QTimer;
    connect(Reconnect_Timer, SIGNAL(timeout()), this, SLOT(Reconnect_slot()));

}

Socket::~Socket()
{
    delete TcpRecvByteArray;
    delete Reconnect_Timer;
}

bool Socket::Connect()
{
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<"cmd.bat");
    if(!p.waitForStarted()){
        qDebug() << "cmd start fail";
        LogFile *logfile = LogFile::GetLogFile();
        logfile->SaveLog("cmd start fail\n");
        return false;
    }
    p.waitForFinished();
    //QString::fromLocal8Bit(p.readAllStandardOutput()); //打印cmd执行结果

    //读取配置信息
    QStringList strList;
    if(!ReadConfig(strList))
    {
        LogFile *logfile = LogFile::GetLogFile();
        logfile->SaveLog("ReadConfig Error\n");
        return false;
    }

    TcpSocket->abort(); //断开已有连接
    TcpSocket->connectToHost(QHostAddress(strList.at(0)),strList.at(1).toInt());
    return true;
}

bool Socket::ReadConfig(QStringList &configList)
{
    QFile f( "config" );
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "打开config文件失败";
        return false;
    }

    QTextStream txtInput(&f);
    QString lineStr;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        configList.append(lineStr);
        lineStr.clear();
    }
    f.close();
    return true;
}


void Socket::ReadIdCard()
{
    //跳转读卡成功界面
    WReadVoucher *w = new WReadVoucher(wCurrent);
    QScriptEngine engine;
    QScriptValue value = engine.evaluate("value=" + MessageJson);
    w->NameText_Label->setText(value.property("Name").toString());
    w->SexText_Label->setText(value.property("Sex").toString());
    w->NationText_Label->setText(value.property("Nation").toString());
    w->YearText_Label->setText(value.property("Birth").toString().mid(0,4));
    w->MonthText_Label->setText(value.property("Birth").toString().mid(4,2));
    w->DateText_Label->setText(value.property("Birth").toString().mid(6,2));
    w->AddrText_Label->setText(value.property("Addr").toString());
    w->IdNumberText_Label->setText(value.property("IDnum").toString());
    w->IssuingAuthorityText_Label->setText(value.property("IssuingAuthority").toString());
    w->ValidPeriodText_Label->setText(value.property("ValidPeriod").toString());
    QPixmap picPer = Base64ToImage(value.property("Photo").toVariant().toByteArray(),"photo.png");
    picPer.scaled(w->Photo_Label->size(), Qt::KeepAspectRatio); //图片填充
    w->Photo_Label->setScaledContents(true);
    w->Photo_Label->setPixmap(QPixmap("photo.png"));
    w->show();
    Delay();
    delete wCurrent; //delete 等待界面
    wCurrent = w;
}

void Socket::AuthSuccess()
{
    WAuthSuccess *w = new WAuthSuccess(wCurrent);
    QScriptEngine engine;
    QScriptValue value = engine.evaluate("value=" + MessageJson);
    QString Voucher = value.property("Voucher").toString();
    if("101" == Voucher){
        Voucher = "第二代居民身份证";
    }
    else if("414" == Voucher){
        Voucher = "普通护照";
    }
    else if("516" == Voucher){
        Voucher = "港澳居民来往内地通行证";
    }
    w->Voucher_Edit->setText(Voucher);
    QString name = value.property("Name").toString();
    w->Name_Edit->setText(name);
    QString IDnum = value.property("ID_number").toString();
    w->IDnum_Edit->setText(IDnum);
    QPixmap picPer = Base64ToImage(value.property("photo").toVariant().toByteArray(),"photo.png");
    picPer.scaled(w->Photo_Label->size(), Qt::KeepAspectRatio);
    w->Photo_Label->setScaledContents(true);
    w->Photo_Label->setPixmap(QPixmap("photo.png"));
    w->show();
    Delay();
    delete wCurrent;
    wCurrent = w;
}

void Socket::AuthFailed()
{
    //跳转认证失败界面
    WAuthFail *w = new WAuthFail(wCurrent);
    if(1 == Json->value(QString("reason"))){
        w->Title_Label->setText(QString("身份信息不匹配,请核对后重新认证"));
    }
    else if(2 == Json->value(QString("reason"))){
        w->Title_Label->setText(QString("认证失败，请确认认证信息是否有误或网络是否异常"));
    }
    w->show();
    Delay();
    delete wCurrent;
    wCurrent = w;
}



void Socket::DisplayError_slot(QAbstractSocket::SocketError)
{
    qDebug() << "connect Error:" << TcpSocket->errorString(); //输出错误信息
    WMessagebox msgBox(wCurrent, NULL, "温馨提示", "连接认证机失败\n请检查线路是否异常", ButtonOne, QString("重连"));
    msgBox.exec();
    Reconnect_Timer->start(1000);
}

void Socket::ConnectSuccess_slot()
{
    qDebug() << "connect success" ;
    Reconnect_Timer->stop();
    WMessagebox msgBox(wCurrent, NULL, "温馨提示", "连接认证机成功", ButtonOne, QString("确定"));
    msgBox.exec();
}

void Socket::ReadMessage_slot()
{
    if(PackType == PackInit || PackType == PackHead || PackType == PackAll){
        qDebug() << "Json读取中...";

        TcpRecvByteArray->append(TcpSocket->readAll());
        MessageJson = QString::fromUtf8(TcpRecvByteArray->data());
        //qDebug() << "MessageJson :" << MessageJson;
        Json->fromString(MessageJson);
        JType = Json->value(QString("Jtype")).toInt();
        switch(JType){
            case AUTHSUCCESS:
            case ReadCard_S:
                {
                    if (WWait::isShow == true){
                        //认证成功
                        Jsize = Json->value(QString("Jsize")).toInt();
                        PackType = PackBody;
                    }
                }
                break;
            case AUTHFAILURE:
                {
                    if (WWait::isShow == true){
                        //认证失败
                        //qDebug() << "MessageJson :" << MessageJson;
                        AuthFailed();
                    }
                }
                break;
            case BackAuth:
                {
                    //返回认证
                    if ( WWait::isShow == true) {
                        WAuth *w = new WAuth(wCurrent);
                        w->show();
                        Delay();
                        delete wCurrent;
                        wCurrent = w;
                    }
                }
                break;
            case BackMachineCode:
                {
                    //返回机读码输入界面
                    if ( WWait::isShow == true) {
                        WMachineCode *w = new WMachineCode(wCurrent);
                        w->show();
                        Delay();
                        delete wCurrent;
                        wCurrent = w;
                    }
                }
                break;
            case HeartBeat:
                {
                    //心跳包
                }
                break;
            default:
                break;
        }
        TcpRecvByteArray->clear();
        MessageJson.clear();
        Json->clear();
        qDebug() << "Json读取完毕";
    }
    else if(PackType == PackBody){
        qDebug() << "Jbody读取数据中...";
        if(TcpRecvByteArray->append(TcpSocket->readAll()).size() >= Jsize){
            MessageJson = QString::fromUtf8(TcpRecvByteArray->data());
            Json->fromString(MessageJson);
            switch(JType){
                case AUTHSUCCESS:
                    //跳转认证成功界面
                    AuthSuccess();
                    break;
                case ReadCard_S:
                    //跳转读证成功界面
                    ReadIdCard();
                break;
                default:
                    break;
            }
            JType        = Init;
            PackType     = PackAll;
            TcpRecvByteArray->clear();
            MessageJson.clear();
            Json->clear();
            qDebug() << "Jbody读取完毕";
        }
    }
}

void Socket::Reconnect_slot()
{
    if(false == Connect()){
        WMessagebox msgBox(wCurrent, NULL, "温馨提示", "配置文件异常或缺失", ButtonOne, QString("确定"));
        msgBox.exec();
    }
}

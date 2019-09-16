#include "wauth.h"
#include "whomepage.h"
#include "wvoucher.h"
#include "wtextinput.h"
#include "wwait.h"
#include "toolkit.h"
#include "socket.h"

WAuth::WAuth(QWidget *parent)
    :WBase(parent)
{
    Line_Label->show(); //显示分割线
    CreatePersonCenter();
    CreateBack();

    //身份证认证按钮
    this->IDcard_Button = new QPushButton(this);
    IDcard_Button->setGeometry(203, 205, 165, 196);
    IDcard_Button->setStyleSheet("border-image: url(:/resource/image/wAuth/IDcard.png);");
    connect(IDcard_Button,SIGNAL(clicked(bool)),this,SLOT(IDcard_slot()));

    //二维码认证按钮
    this->QRcode_Button = new QPushButton(this);
    QRcode_Button->setGeometry(418, 205, 165, 196);
    QRcode_Button->setStyleSheet("border-image: url(:/resource/image/wAuth/QRcode.png);");
    connect(QRcode_Button,SIGNAL(clicked(bool)),this,SLOT(QRcode_slot()));

    //文本输入认证按钮
    this->TextInput_Button = new QPushButton(this);
    TextInput_Button->setGeometry(633, 205, 165, 196);
    TextInput_Button->setStyleSheet("border-image: url(:/resource/image/wAuth/Text.png);");
    connect(TextInput_Button,SIGNAL(clicked(bool)),this,SLOT(TextInput_slot()));

    //纯读证按钮
    this->ReadCard_Button = new QPushButton(this);
    ReadCard_Button->setGeometry(818, 343, 80, 40);
    ReadCard_Button->setText(QString("纯读证"));
    ReadCard_Button->setStyleSheet("font:18px;color:#2B8BF2;border-radius:8px;border:1px solid #2B8BF2;");
    connect(ReadCard_Button,SIGNAL(clicked(bool)),this,SLOT(ReadCard_slot()));
}

WAuth::~WAuth()
{

}

void WAuth::IDcard_slot()
{
    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),IDcard);
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WVoucher *w = new WVoucher(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

void WAuth::QRcode_slot()
{
    //WWait::Timer->start(3000);

    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),QRcode);
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WWait *w = new WWait(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

void WAuth::TextInput_slot()
{
    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),TextInput);
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WTextInput *w = new WTextInput(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

void WAuth::ReadCard_slot()
{
    //WWait::Timer->start(3000);
    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),ReadCard);
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WWait *w = new WWait(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

void WAuth::MenuBack_slot()
{
    WHomePage *w = new WHomePage(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

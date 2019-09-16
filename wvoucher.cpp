#include "wvoucher.h"
#include "wmachinecode.h"
#include "wwait.h"
#include "toolkit.h"
#include "socket.h"

WVoucher::WVoucher(QWidget *parent)
    :WBase(parent)
{
    Line_Label->show();
    CreatePersonCenter();
    CreateBack();
    CreateHomePage();

    //请选择证件类型
    this->Title_Label = new QLabel(this);
    Title_Label->setGeometry(437, 198, 126, 18);
    Title_Label->setText(QString("请选择证件类型"));
    Title_Label->setStyleSheet("color:#131B4C;font: 18px;");

    //第二代居民身份证按钮
    this->IDcard_Button = new QPushButton(this);
    IDcard_Button->setGeometry(380, 243,240,40);
    IDcard_Button->setText(QString("第二代居民身份证"));
    IDcard_Button->setStyleSheet("QPushButton{color:#131B4C ; font:14px;border-radius:4px;border:0.5px solid #DCDCDC;}"
                                 "QPushButton:hover{background-color:rgba(190,190,190,150)}");
    connect(IDcard_Button,SIGNAL(clicked(bool)),this,SLOT(IDcard_slot()));

    //普通护照按钮
    this->Passport_Button = new QPushButton(this);
    Passport_Button->setGeometry(380, 298,240,40);
    Passport_Button->setText(QString("普通护照"));
    Passport_Button->setStyleSheet("QPushButton{color:#131B4C ; font:14px; border-radius:4px;border:0.5px solid #DCDCDC;}"
                                   "QPushButton:hover{background-color:rgba(190,190,190,150)}");
    connect(Passport_Button,SIGNAL(clicked(bool)),this,SLOT(Passport_slot()));

    //港澳居民来往内地通行证按钮
    this->GatePass_Button = new QPushButton(this);
    GatePass_Button->setGeometry(380, 353,240,40);
    GatePass_Button->setText(QString("港澳居民来往内地通行证"));
    GatePass_Button->setStyleSheet("QPushButton{ color:#131B4C ; font:14px;border-radius:4px;border:0.5px solid #DCDCDC;}"
                                   "QPushButton:hover{background-color:rgba(190,190,190,150)}");
    connect(GatePass_Button,SIGNAL(clicked(bool)),this,SLOT(GatePass_slot()));

}

WVoucher::~WVoucher()
{

}

void WVoucher::IDcard_slot()
{
    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),IDcard);
    Socket::Json->add(QString("Voucher"),"101");
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WWait *w = new WWait(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

void WVoucher::Passport_slot()
{
    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),IDcard);
    Socket::Json->add(QString("Voucher"),"414");
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WMachineCode *w = new WMachineCode(this, Passport);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

void WVoucher::GatePass_slot()
{
    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),IDcard);
    Socket::Json->add(QString("Voucher"),"516");
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WMachineCode *w = new WMachineCode(this, Gatepass);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

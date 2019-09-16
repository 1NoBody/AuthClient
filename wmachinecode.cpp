#include "wmachinecode.h"
#include "wvoucher.h"
#include "toolkit.h"
#include "wmessagebox.h"
#include "socket.h"
#include "wwait.h"

WMachineCode::WMachineCode(QWidget *parent, MACHINECODE MachineCode)
    :WBase(parent)
{
    Line_Label->show();
    CreatePersonCenter();
    CreateBack();
    CreateHomePage();

    //请输入机读码
    this->Title_Label = new QLabel(this);
    Title_Label->setGeometry(446,155,108,18);
    Title_Label->setText(QString("请输入机读码"));
    Title_Label->setStyleSheet("color:#131B4C;font: 18px;");

    //点击放大标签
    this->Example_Label = new QLabel(this);
    Example_Label->setGeometry(339,206,42,17);
    Example_Label->setAlignment(Qt::AlignRight);
    Example_Label->setText(QString("示例"));
    Example_Label->setStyleSheet("color:#131B4C;font: 14px;");

    //区域一标签
    this->Area1_Label = new QLabel(this);
    Area1_Label->setGeometry(339,268,42,14);
    Area1_Label->setText(QString("区域一"));
    Area1_Label->setStyleSheet("color:#131B4C;font: 14px;");

    //区域二标签
    this->Area2_Label = new QLabel(this);
    Area2_Label->setGeometry(339,323,42,14);
    Area2_Label->setText(QString("区域二"));
    Area2_Label->setStyleSheet("color:#131B4C;font: 14px;");

    //区域三标签
    this->Area3_Label = new QLabel(this);
    Area3_Label->setGeometry(339,378,42,14);
    Area3_Label->setText(QString("区域三"));
    Area3_Label->setStyleSheet("color:#131B4C;font: 14px;");

    //区域一编辑框
    QRegExp regx("[a-zA-Z0-9]+$"); //编辑框输入限制
    this->validator = new QRegExpValidator(regx,this);

    this->Area1_Edit = new QLineEdit(this);
    Area1_Edit->setGeometry(393,255,240,40);
    Area1_Edit->setPlaceholderText("  请输入区域一的10位机读码");
    Area1_Edit->setStyleSheet("QLineEdit{color:#131B4C; font:14px; border-radius:4px; border:0.5px solid #DCDCDC}");
    Area1_Edit->setMaxLength(10);
    Area1_Edit->setValidator(validator);

    //区域二编辑框
    this->Area2_Edit = new QLineEdit(this);
    Area2_Edit->setGeometry(393,310,240,40);
    Area2_Edit->setPlaceholderText("  请输入区域二的7位机读码");
    Area2_Edit->setStyleSheet("QLineEdit{color:#131B4C; font:14px; border-radius:4px; border:0.5px solid #DCDCDC}");
    Area2_Edit->setMaxLength(7);
    Area2_Edit->setValidator(validator);

    //区域三编辑框
    this->Area3_Edit = new QLineEdit(this);
    Area3_Edit->setGeometry(393,365,240,40);
    Area3_Edit->setPlaceholderText("  请输入区域三的7位机读码");
    Area3_Edit->setStyleSheet("QLineEdit{color:#131B4C; font:14px; border-radius:4px; border:0.5px solid #DCDCDC}");
    Area3_Edit->setMaxLength(7);
    Area3_Edit->setValidator(validator);

    //放大按钮
    this->Example_Button = new QPushButton(this);
    Example_Button->setEnabled(false);
    Example_Button->setGeometry(393,198,240,50);
    QString url = "";
    switch (MachineCode) {
    case Passport:
    {
        url = "border-image: url(:/resource/image/wMachineCode/passport.png)";
        break;
    }
    case Gatepass:
    {
        url = "border-image: url(:/resource/image/wMachineCode/gatepass.png)";
        break;
    }
    default:
        break;
    }
    Example_Button->setStyleSheet(url);
    connect(Example_Button,SIGNAL(clicked(bool)),this,SLOT(Example_slot()));

    //预览按钮
    this->Preview_Button = new QPushButton(this);
    Preview_Button->setGeometry(393,420,112,40);
    Preview_Button->setText(QString("确认信息"));
    Preview_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:14px; border-radius:4px;}"
                                  "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                                  "QPushButton:hover{background-color:rgb(0,191,255)}");
    connect(Preview_Button,SIGNAL(clicked(bool)),this,SLOT(Preview_slot()));

    //认证按钮
    this->Auth_Button = new QPushButton(this);
    Auth_Button->setGeometry(521,420,112,40);
    Auth_Button->setText(QString("下一步"));
    Auth_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:14px; border-radius:4px;}"
                               "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                               "QPushButton:hover{background-color:rgb(0,191,255)}");
    connect(Auth_Button,SIGNAL(clicked(bool)),this,SLOT(Auth_slot()));
}

WMachineCode::~WMachineCode()
{

}

void WMachineCode::Example_slot()
{

}

void WMachineCode::Preview_slot()
{
    if(10 != Area1_Edit->text().length()){
        WMessagebox msgBox(this, NULL, "温馨提示", "区域一机读码不能小于10位数", ButtonOne, QString("确定"));
        msgBox.exec();
    }
    else if(7 != Area2_Edit->text().length()){
        WMessagebox msgBox(this, NULL, "温馨提示", "区域二机读码不能小于7位数", ButtonOne, QString("确定"));
        msgBox.exec();
    }
    else if(7 != Area3_Edit->text().length()){
        WMessagebox msgBox(this, NULL, "温馨提示", "区域三机读码不能小于7位数", ButtonOne, QString("确定"));
        msgBox.exec();
    }
    else{
        //json send
        Socket::Json->clear();
        Socket::Json->add(QString("Jtype"),Preview);
        Socket::Json->add(QString("firstArea"),Area1_Edit->text());
        Socket::Json->add(QString("secondArea"),Area2_Edit->text());
        Socket::Json->add(QString("thirdArea"),Area3_Edit->text());
        Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());
    }
}

void WMachineCode::Auth_slot()
{
    if(10 != Area1_Edit->text().length()){
        WMessagebox msgBox(this, NULL, "温馨提示", "区域一机读码不能小于10位数", ButtonOne, QString("确定"));
        msgBox.exec();
    }
    else if(7 != Area2_Edit->text().length()){
        WMessagebox msgBox(this, NULL, "温馨提示", "区域二机读码不能小于7位数", ButtonOne, QString("确定"));
        msgBox.exec();
    }
    else if(7 != Area3_Edit->text().length()){
        WMessagebox msgBox(this, NULL, "温馨提示", "区域三机读码不能小于7位数", ButtonOne, QString("确定"));
        msgBox.exec();
    }
    else{
        //json send
        Socket::Json->clear();
        Socket::Json->add(QString("Jtype"),Auth);
        Socket::Json->add(QString("firstArea"),Area1_Edit->text());
        Socket::Json->add(QString("secondArea"),Area2_Edit->text());
        Socket::Json->add(QString("thirdArea"),Area3_Edit->text());
        Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

        WWait *w = new WWait(this);
        wCurrent = w;
        w->show();
        Delay();
        delete this;
    }
}

void WMachineCode::MenuBack_slot()
{
    WVoucher *w = new WVoucher(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

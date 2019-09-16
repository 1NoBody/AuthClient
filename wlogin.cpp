#include "wlogin.h"
#include "whomepage.h"
#include "wmessagebox.h"
#include "toolkit.h"

WLogin::WLogin(QWidget *parent)
    :WBase(parent)
{
    //用户名标签
    this->UserText_Label = new QLabel(this);
    UserText_Label->setGeometry(340,216,46,14);
    UserText_Label->setText(QString("用户名:"));
    UserText_Label->setStyleSheet("color:#131B4C;font:14px;");

    //密码标签
    this->PswText_Label = new QLabel(this);
    PswText_Label->setGeometry(354,271,32,14);
    PswText_Label->setText(QString("密码:"));
    PswText_Label->setStyleSheet("color:#131B4C;font:14px;");

    //用户名编辑框
    this->User_Edit = new QLineEdit(this);
    User_Edit->setGeometry(401,203,240,40);
    User_Edit->setPlaceholderText("  请输入用户名");
    User_Edit->setStyleSheet("border-radius:4px;border:1px solid rgb(211,211,211);font: 14px;");
    User_Edit->setFocusPolicy(Qt::ClickFocus );

    //密码编辑框
    this->Psw_Edit = new QLineEdit(this);
    Psw_Edit->setGeometry(401,258,240,40);
    Psw_Edit->setPlaceholderText("  请输入密码");
    Psw_Edit->setStyleSheet("border-radius:4px;border:1px solid rgb(211,211,211);font: 14px;");
    Psw_Edit->setFocusPolicy(Qt::ClickFocus );

    //登录按钮
    this->Login_Button = new QPushButton(this);
    Login_Button->setGeometry(401,357,240,40);
    Login_Button->setText(QString("登录"));
    Login_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:16px; border-radius:4px;}"
                                "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                                "QPushButton:hover{background-color:rgb(0,191,255)}");
    connect(Login_Button,SIGNAL(clicked(bool)),this,SLOT(Login_slot()));

    //忘记密码按钮
    this->GetPsw_Button = new QPushButton(this);
    GetPsw_Button->setGeometry(585,313,56,14);
    GetPsw_Button->setStyleSheet("QPushButton{font:14px;border:none}"
                                 "QPushButton:hover{color: rgb(50,100,200)}");
    GetPsw_Button->setFlat(true);
    GetPsw_Button->setText("忘记密码");
    connect(GetPsw_Button,SIGNAL(clicked(bool)),this,SLOT(GetPsw_slot()));

    //checkBox记住密码
    this->RemberPsw_CheckBox = new QCheckBox(this);
    RemberPsw_CheckBox->setGeometry(401,313,75,14);
    RemberPsw_CheckBox->setText("记住密码");
    RemberPsw_CheckBox->setStyleSheet("QCheckBox{font:14px;border:none}");
}

WLogin::~WLogin()
{

}

void WLogin::Login_slot()
{
    WHomePage *w = new WHomePage(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

void WLogin::GetPsw_slot()
{
    WMessagebox msgBox(this, NULL, "温馨提示", "忘记密码请联系管理员", ButtonOne, QString("确定"));
    msgBox.exec();
}

#include "wresetpsw.h"

WResetPsw::WResetPsw(WBase *parent)
{
    this->Parent = parent;
    //窗口属性
    this->setGeometry(parent->geometry().x() + 307, parent->geometry().y() + 167, 386, 266);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏、边框
    QPalette palette(this->palette()); //背景色
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);

    //修改密码标题
    this->Title_Label = new QLabel(this);
    Title_Label->setGeometry(161, 22,64,16);
    Title_Label->setText(QString("修改密码"));
    Title_Label->setStyleSheet("color:#131B4C;font: 16px;");

    //旧密码标签
    this->OldPsw_Label = new QLabel(this);
    OldPsw_Label->setGeometry(70, 70,40,12);
    OldPsw_Label->setText(QString("旧密码:"));
    OldPsw_Label->setStyleSheet("color:#131B4C;font: 12px");

    //新密码标签
    this->NewPsw_Label = new QLabel(this);
    NewPsw_Label->setGeometry(70, 120,40,12);
    NewPsw_Label->setText(QString("新密码:"));
    NewPsw_Label->setStyleSheet("color:#131B4C;font: 12px");

    //确认密码标签
    this->ConfirmPsw_Label = new QLabel(this);
    ConfirmPsw_Label->setGeometry(46, 170,64,12);
    ConfirmPsw_Label->setText(QString("确认新密码:"));
    ConfirmPsw_Label->setStyleSheet("color:#131B4C;font: 12px");

    //旧密码编辑框
    this->OldPsw_Edit = new QLineEdit(this);
    OldPsw_Edit->setGeometry(120, 58,200,36);
    OldPsw_Edit->setPlaceholderText("  请输入旧密码");
    OldPsw_Edit->setStyleSheet("font: 12px;border-radius:4px;border:0.5px solid #DCDCDC");

    //新密码编辑框
    this->NewPsw_Edit = new QLineEdit(this);
    NewPsw_Edit->setGeometry(120, 108,200,36);
    NewPsw_Edit->setPlaceholderText("  请输入新密码");
    NewPsw_Edit->setStyleSheet("font: 12px;border-radius:4px;border:0.5px solid #DCDCDC");

    //确认密码编辑框
    this->ConfirmPsw_Edit = new QLineEdit(this);
    ConfirmPsw_Edit->setGeometry(120, 158,200,36);
    ConfirmPsw_Edit->setPlaceholderText("  请再次输入新密码");
    ConfirmPsw_Edit->setStyleSheet("font: 12px;border-radius:4px;border:0.5px solid #DCDCDC");

    //取消按钮
    this->Cancel_Button = new QPushButton(this);
    Cancel_Button->setGeometry(120, 208,93,36);
    Cancel_Button->setText(QString("取消"));
    Cancel_Button->setStyleSheet("QPushButton{background-color:#FFFFFF; color:#131B4C; font:12px; border-radius:4px;border:0.5px solid #DCDCDC}"
                                 "QPushButton:hover{background-color:rgba(0,191,255,150)}");
    connect(Cancel_Button,SIGNAL(clicked(bool)),this,SLOT(Cancel_slot()));

    //确认按钮
    this->Confirm_Button = new QPushButton(this);
    Confirm_Button->setGeometry(227, 208,93,36);
    Confirm_Button->setText(QString("确认"));
    Confirm_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:12px; border-radius:4px;}"
                                  "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                                  "QPushButton:hover{background-color:rgba(0,191,255,150)}");
    connect(Confirm_Button,SIGNAL(clicked(bool)),this,SLOT(Confirm_slot()));
}

WResetPsw::~WResetPsw()
{

}

void WResetPsw::Confirm_slot()
{
    Parent->Gray_Label->hide();
    delete this;
}

void WResetPsw::Cancel_slot()
{
    Parent->Gray_Label->hide();
    delete this;
}

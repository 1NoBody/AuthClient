#include "wauthfailure.h"

WAuthFail::WAuthFail(QWidget *parent)
    :WBase(parent)
{
    Line_Label->show();
    CreatePersonCenter();
    CreateBack();
    CreateHomePage();

    //ICon
    this->Icon_Label = new QLabel(this);
    Icon_Label->setGeometry(472, 212, 44, 44);
    Icon_Label->setStyleSheet("border-image: url(:/resource/image/wAuthFail/fail.png);");

    //认证失败提示语标签
    this->Title_Label = new QLabel(this);
    Title_Label->setWordWrap(true); //自动换行
    Title_Label->setAlignment(Qt::AlignHCenter);
    Title_Label->setGeometry(338, 285, 320, 50);
    //Title_Label->setText(QString("身份信息不匹配,请核对后重新认证"));
    //Title_Label->setText(QString("认证失败，请确认认证信息是否有误或网络是否异常"));
    Title_Label->setStyleSheet("color: rgb(0, 0, 0);"" font:  20px;");

    //返回按钮
    this->Back_Button = new QPushButton(this);
    Back_Button->setGeometry(435, 360, 120, 40);
    Back_Button->setText(QString("返回"));
    Back_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:14px; border-radius:4px;}"
                               "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                               "QPushButton:hover{background-color:rgba(0,191,255,150)}");
    connect(Back_Button,SIGNAL(clicked(bool)),this,SLOT(MenuBack_slot()));
}

WAuthFail::~WAuthFail()
{

}

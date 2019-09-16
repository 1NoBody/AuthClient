#include "wmessagebox.h"

WMessagebox::WMessagebox(QWidget *parent, QString Icon, QString Title, QString Text, ButtonNum num,QString BText1, QString BText2)
{
    //窗口属性
    this->setGeometry(parent->geometry().x() + parent->geometry().width()/2 - 150, parent->geometry().y() + parent->geometry().height()/2 - 50, (Text.length() > 10 ? 11:9) * 20, 100);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    this->setWindowTitle(Title);
    Qt::WindowFlags flags= this->windowFlags();
    this->setWindowFlags(flags&~Qt::WindowContextHelpButtonHint); //去弹窗问号


    //Icon图标
    this->Icon_Label = NULL;


    //白色背景
    this->BackgroundColor_Label = new QLabel(this);
    BackgroundColor_Label->setGeometry(0, 0, this->geometry().width(), 60);
    BackgroundColor_Label->setStyleSheet("background-color:white");

    //文字信息
    this->Text_Label = new QLabel(this);
    Text_Label->setGeometry(0, 10, this->geometry().width(), 50);
    Text_Label->setStyleSheet("color:rgb(0, 0, 0); font:15px;");
    Text_Label->setAlignment(Qt::AlignCenter);
    Text_Label->setText(Text);

    switch (num) {
    case NoButton:
        break;
    case ButtonOne:
        this->Button1 = new QPushButton(this);
        Button1->setGeometry(this->geometry().width()/2 - 35, this->geometry().height() - 32, 70, 25);
        Button1->setText(BText1);
        Button1->setStyleSheet("color:rgb(0, 0, 0); font:12px;");
        connect(Button1,SIGNAL(clicked(bool)),this,SLOT(accept()));
        break;
    case ButtonTwo:
        this->Button1 = new QPushButton(this);
        Button1->setGeometry(17, this->geometry().height() - 32, 70, 25);
        Button1->setText(BText1);
        Button1->setStyleSheet("color:rgb(0, 0, 0); font:12px;");
        connect(Button1,SIGNAL(clicked(bool)),this,SLOT(reject()));

        this->Button2 = new QPushButton(this);
        Button2->setGeometry(this->geometry().width() - 87, this->geometry().height() - 32, 70, 25);
        Button2->setText(BText2);
        Button2->setStyleSheet("color:rgb(0, 0, 0); font:12px;");
        connect(Button2,SIGNAL(clicked(bool)),this,SLOT(accept()));
        break;
    default:
        break;
    }
}

WMessagebox::~WMessagebox()
{

}

void WMessagebox::Button1_slot()
{

}

void WMessagebox::Button2_slot()
{

}

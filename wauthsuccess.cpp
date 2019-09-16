#include "wauthsuccess.h"

WAuthSuccess::WAuthSuccess(QWidget *parent)
    :WBase(parent)
{
    Line_Label->show();
    CreatePersonCenter();
    CreateBack();
    CreateHomePage();

    //ICon图标
    this->Icon_Label = new QLabel(this);
    Icon_Label->setGeometry(478, 186, 44, 44);
    Icon_Label->setStyleSheet("border-image: url(:/resource/image/wAuthSuc/ok.png);");

    //认证成功
    this->Title_Label = new QLabel(this);
    Title_Label->setGeometry(456, 247, 88, 22);
    Title_Label->setText(QString("认证成功"));
    Title_Label->setStyleSheet("color:#131B4C;""font: 22px;");

    //照片标签
    this->Photo_Label = new QLabel(this);
    Photo_Label->setGeometry(338, 290, 75, 100);
    Photo_Label->setText(QString("照片"));
    Photo_Label->setAlignment(Qt::AlignCenter);
    Photo_Label->setStyleSheet("color: rgb(120, 120, 120);""font:20px;""background-color: gray;");

    //证件类型
    this->Voucher_Label = new QLabel(this);
    Voucher_Label->setGeometry(423, 300, 70, 30);
    Voucher_Label->setAlignment(Qt::AlignRight);
    Voucher_Label->setText(QString("证件类型:"));
    Voucher_Label->setStyleSheet("color:#131B4C;""font: 16px;");

    this->Voucher_Edit = new QLineEdit(this);
    Voucher_Edit->setAlignment(Qt::AlignLeft);
    Voucher_Edit->setGeometry(500, 294, 300, 30);
    Voucher_Edit->setStyleSheet("color:#131B4C;""font: 16px;""background:transparent;border-style:none");
    Voucher_Edit->setReadOnly(true);
    Voucher_Edit->setContextMenuPolicy(Qt::NoContextMenu); //去掉右键菜单


    //姓名标签
    this->Name_Label = new QLabel(this);
    Name_Label->setGeometry(423, 329, 70, 30);
    Name_Label->setAlignment(Qt::AlignRight);
    Name_Label->setText(QString("姓名:"));
    Name_Label->setStyleSheet("color:#131B4C;""font: 16px;");

    this->Name_Edit = new QLineEdit(this);
    Name_Edit->setAlignment(Qt::AlignLeft);
    Name_Edit->setGeometry(500, 323, 300, 30);
    Name_Edit->setStyleSheet("color:#131B4C;font: 16px;""background:transparent;border-style:none");
    Name_Edit->setReadOnly(true);
    Name_Edit->setContextMenuPolicy(Qt::NoContextMenu);
    //Name_Edit->setText("林建雄");

    //证件号码标签
    this->IDnum_Label = new QLabel(this);
    IDnum_Label->setGeometry(423, 358, 70, 30);
    IDnum_Label->setAlignment(Qt::AlignRight);
    IDnum_Label->setText(QString("证件号码:"));
    IDnum_Label->setStyleSheet("color:#131B4C;""font: 16px;");

    this->IDnum_Edit = new QLineEdit(this);
    IDnum_Edit->setAlignment(Qt::AlignLeft);
    IDnum_Edit->setGeometry(500, 353, 300, 30);
    IDnum_Edit->setStyleSheet("color:#131B4C;""font: 16px;""background:transparent;border-style:none");
    IDnum_Edit->setReadOnly(true);
    IDnum_Edit->setContextMenuPolicy(Qt::NoContextMenu);
    //IDnum_Edit->setText("350321199507162615");

    //返回按钮
    this->Back_Button = new QPushButton(this);
    Back_Button->setGeometry(430, 413, 140, 40);
    Back_Button->setText(QString("返回"));
    Back_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:14px; border-radius:4px;}"
                               "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                               "QPushButton:hover{background-color:rgba(0,191,255,150)}");
    connect(Back_Button,SIGNAL(clicked(bool)),this,SLOT(MenuBack_slot()));
}

WAuthSuccess::~WAuthSuccess()
{

}

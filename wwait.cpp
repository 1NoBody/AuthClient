#include "wwait.h"
#include "wauthsuccess.h"
#include "wauthfailure.h"
#include "wreadvoucher.h"
#include "toolkit.h"

QTimer *WWait::Timer = new QTimer;
bool WWait::isShow   = false;


WWait::WWait(QWidget *parent)
    :WBase(parent)
{
    Line_Label->show();
    CreatePersonCenter();
    CreateBack();
    CreateHomePage();

    //提示语标签
    this->TextTip_Label = new QLabel(this);
    TextTip_Label->setGeometry(370, 277, 260, 26);
    TextTip_Label->setText(QString("用户操作中，请等待..."));
    TextTip_Label->setStyleSheet("color:#131B4C;""font:26px;");

    //定时器
    connect(Timer,SIGNAL(timeout()),this,SLOT(Timeout_slot()));
    //当前界面为wwait
    isShow = true;
}

WWait::~WWait()
{
    isShow = false;
}

void WWait::Timeout_slot()
{
    Timer->stop();
    if(true){
        //WAuthSuccess *w = new WAuthSuccess(this);
        WReadVoucher *w = new WReadVoucher(this);
        wCurrent = w;
        w->show();
        Delay();
        delete this;
    }
    else{
        WAuthFail *w = new WAuthFail(this);
        wCurrent = w;
        w->show();
        Delay();
        delete this;
    }
}

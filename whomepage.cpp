#include "whomepage.h"
#include "wauth.h"
#include "toolkit.h"

WHomePage::WHomePage(QWidget *parent)
    :WBase(parent)
{

    CreatePersonCenter();

    //身份认证按钮
    this->Auth_Button = new QPushButton(this);
    Auth_Button->setGeometry(400, 209, 200, 222);
    Auth_Button->setText(QString("身份认证"));
    Auth_Button->setStyleSheet("color:rgb(255,255,255);font:28px;text-align: center;border-image:url(:/resource/image/wHomePage/auth.png);");
    connect(Auth_Button,SIGNAL(clicked(bool)),this,SLOT(Auth_slot()));
}

WHomePage::~WHomePage()
{

}

void WHomePage::Auth_slot()
{
    WAuth *w = new WAuth(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

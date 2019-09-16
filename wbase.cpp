#include "wbase.h"
#include "whomepage.h"
#include "wauth.h"
#include "wmessagebox.h"
#include "wlogin.h"
#include "wresetpsw.h"
#include "toolkit.h"
#include "socket.h"

WBase::WBase(QWidget *parent)
{
    //窗口属性
    if(parent == NULL){
        QDesktopWidget *deskWgt = QApplication::desktop();
        this->setGeometry(deskWgt->width()/2 - QWidget_Width/2, deskWgt->height()/2 - QWidget_Height/2, QWidget_Width, QWidget_Height);
    }
    else{
        this->setGeometry(parent->geometry().x(), parent->geometry().y(), QWidget_Width, QWidget_Height);
    }

    this->setMaximumSize(QWidget_Width, QWidget_Height);
    this->setMinimumSize(QWidget_Width, QWidget_Height);
    this->setWindowTitle(QString("可信认证机操作系统"));
    QPalette palette(this->palette()); //背景色 (不会影响控件)
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);

    //菜单栏
    this->MenuBar_Lable = new QLabel(this);
    MenuBar_Lable->setGeometry(0,0,this->geometry().width(),48);
    MenuBar_Lable->setStyleSheet("QLabel{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}");

    this->Line_Label = new QLabel(this);
    Line_Label->setGeometry(172,15,1,18);
    Line_Label->setStyleSheet("QLabel{background-color:gray}");
    Line_Label->hide();

    //Title
    this->TitleText_Label = new QLabel(this);
    TitleText_Label->setText(QString("可信认证机操作系统"));
    TitleText_Label->setGeometry(16, 16, 144, 16); //px
    QFont font("PingFangSC-Medium");
    TitleText_Label->setFont(font);
    TitleText_Label->setStyleSheet("QLabel{color: #FFFFFF; font:16px }");

    //窗体灰化
    this->Gray_Label = new QLabel(this);
    Gray_Label->resize(this->size());
    Gray_Label->setStyleSheet("background-color:rgba(33,42,52,50%)");
    Gray_Label->hide();
}

WBase::~WBase()
{

}

void WBase::CreatePersonCenter()
{
    //个人中心
    this->Name_Action   = new QAction(QString("姓名 :"), this);
    Name_Action->setEnabled(false);
    this->ID_Action = new QAction(QString("工号 :"), this);
    ID_Action->setEnabled(false);
    this->ResetPsw_Action = new QAction(QString("修改密码"), this);
    connect(ResetPsw_Action, SIGNAL(triggered()), this, SLOT(ResetPsw_slot()));
    this->Logout_Action = new QAction(QString("退出登录"), this);
    connect(Logout_Action, SIGNAL(triggered()), this, SLOT(Logout_slot()));

    this->PersonCenter_QMenu = new QMenu(this);
    PersonCenter_QMenu->installEventFilter(this);
    PersonCenter_QMenu->setWindowFlags(PersonCenter_QMenu->windowFlags() | Qt::FramelessWindowHint); //去阴影边框
    PersonCenter_QMenu->setAttribute(Qt::WA_TranslucentBackground); //透明
    PersonCenter_QMenu->setStyleSheet("QMenu::item{padding-left:16px ; height: 42px; width: 160px;}"
                                      "QMenu{font: 12px;background-color:#FFFFFF;border-radius:8px;border:1px solid #DDDDDD;}" //圆角 线宽+颜色
                                      "QMenu::item:selected {color:rgba(85, 170, 255,50%);}"); //选中的样式

    PersonCenter_QMenu->addAction(Name_Action);
    PersonCenter_QMenu->addAction(ID_Action);
    PersonCenter_QMenu->addAction(ResetPsw_Action);
    PersonCenter_QMenu->addAction(Logout_Action);

    this->PersonCenter_Button = new QPushButton(this);
    PersonCenter_Button->setGeometry(927,13,23.7,23.7);
    PersonCenter_Button->setFlat(true);
    PersonCenter_Button->setMenu(PersonCenter_QMenu);
    PersonCenter_Button->setStyleSheet("QPushButton{border-image: url(:/resource/image/wBase/percenter.png)}"
                                       "QPushButton::menu-indicator{image:none}"); //去小三角
}

void WBase::CreateBack()
{
    //返回
    this->MenuBackIcon_Label = new QLabel(this);
    MenuBackIcon_Label->setGeometry(185, 18, 7, 12);
    MenuBackIcon_Label->setStyleSheet("border-image: url(:/resource/image/wBase/back.png);");

    this->MenuBack_Button = new QPushButton(this);
    MenuBack_Button->setGeometry(196, 18, 24, 12);
    MenuBack_Button->setFlat(true);
    MenuBack_Button->setText(QString("返回"));
    MenuBack_Button->setStyleSheet("QPushButton{color:#FFFFFF;font:12px;border:none}" //border:none 去掉按下边框效果
                                   "QPushButton:hover{color:#D3D3D3;}");

    connect(MenuBack_Button,SIGNAL(clicked(bool)),this,SLOT(MenuBack_slot()));
}

void WBase::CreateHomePage()
{
    //首页
    this->HomePageIcon_Button = new QPushButton(this);
    HomePageIcon_Button->setGeometry(245, 18, 12, 12);
    HomePageIcon_Button->setStyleSheet("border-image: url(:/resource/image/wBase/home.png);");
    connect(HomePageIcon_Button,SIGNAL(clicked(bool)),this,SLOT(HomePage_slot()));

    this->HomePage_Button = new QPushButton(this);
    HomePage_Button->setFlat(true);
    HomePage_Button->setGeometry(257, 19, 30, 12);
    HomePage_Button->setText(QString(" 首页"));
    HomePage_Button->setStyleSheet("QPushButton{color:#FFFFFF;font:12px;border:none}"
                                   "QPushButton:hover{color:#D3D3D3}");

    connect(HomePage_Button,SIGNAL(clicked(bool)),this,SLOT(HomePage_slot()));
}

void WBase::closeEvent(QCloseEvent *event)
{
    qDebug() << "退出程序:" << event;
}


void WBase::Close_slot()
{
    exit(0);
}

void WBase::Min_slot()
{
    this->showMinimized();
}

void WBase::ResetPsw_slot()
{
    Gray_Label->show();
    Gray_Label->raise();
    WResetPsw *w = new WResetPsw(this);
    w->exec();
}

void WBase::Logout_slot()
{
    WMessagebox msgBox(this, NULL, "温馨提示", "是否确认退出账号？", ButtonTwo, QString("取消"), QString("确认"));
    msgBox.Button2->setFocus();
    int res = msgBox.exec();
    if(QDialog::Accepted == res){
        WLogin *w = new WLogin(this);
        wCurrent = w;
        w->show();
        Delay();
        delete this;
    }
}

void WBase::MenuBack_slot()
{
    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),BackAuth);
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WAuth *w = new WAuth(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

void WBase::HomePage_slot()
{
    //json send
    Socket::Json->clear();
    Socket::Json->add(QString("Jtype"),BackAuth);
    Socket::TcpSocket->write(Socket::Json->toString().toStdString().c_str());

    WHomePage *w = new WHomePage(this);
    wCurrent = w;
    w->show();
    Delay();
    delete this;
}

bool WBase::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Show && obj == PersonCenter_Button->menu()){
        PersonCenter_Button->menu()->move(PersonCenter_Button->menu()->pos().x() - 125, PersonCenter_Button->menu()->pos().y() + 12);
        return true;
    }
    return false;
}


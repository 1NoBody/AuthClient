/*****************************************************************************************
 * wbase.h
 * Function: 窗口基类
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 *
 * **************************************************************************************/

#ifndef WBASE_H
#define WBASE_H

#include <QWidget>
#include <QtGui>
#include <QCloseEvent>
#include <QDebug>


#define QWidget_Width   1000
#define QWidget_Height  600

extern QWidget *wCurrent;

class WBase : public QWidget
{
    Q_OBJECT

public:
    WBase(QWidget *parent = 0);
    ~WBase();

    QLabel   *Gray_Label;  //界面灰化
    QLabel   *Line_Label;  //分割线

protected:
    void CreatePersonCenter();        //个人中心
    void CreateBack();                //返回
    void CreateHomePage();            //首页

private:

    QLabel       *MenuBar_Lable;
    QLabel       *TitleText_Label;
    QLabel       *MenuBackIcon_Label;
    QPushButton  *MenuBack_Button;
    QPushButton  *HomePageIcon_Button;
    QPushButton  *HomePage_Button;

    QPushButton  *Close_Button;
    QPushButton  *Max_Button;
    QPushButton  *Min_Button;

    QMenu       *PersonCenter_QMenu;
    QAction     *Name_Action;
    QAction     *ID_Action;
    QAction     *ResetPsw_Action;
    QAction     *Logout_Action;
    QPushButton *PersonCenter_Button;

    void closeEvent(QCloseEvent *event); //程序退出

private slots:
    void Close_slot();
    void Min_slot();

    void ResetPsw_slot();
    void Logout_slot();
    void HomePage_slot();
    virtual void MenuBack_slot();

    bool eventFilter(QObject * obj, QEvent *event); //设置个人中心坐标
};

#endif // WBASE_H

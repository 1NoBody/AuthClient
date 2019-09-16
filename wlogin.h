/*************************************************************
 * wlogin.h
 * Function:操作员登录窗口
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WLOGIN_H
#define WLOGIN_H

#include "wbase.h"


class WLogin : public WBase
{
    Q_OBJECT

public:
    WLogin(QWidget *parent = NULL);
    ~WLogin();

private:
    QLabel      *UserText_Label;
    QLabel      *PswText_Label ;
    QLineEdit   *User_Edit ;
    QLineEdit   *Psw_Edit  ;
    QPushButton *Login_Button;
    QPushButton *GetPsw_Button;
    QCheckBox   *RemberPsw_CheckBox;

private slots:
    void Login_slot();
    void GetPsw_slot();
};

#endif // WLOGIN_H

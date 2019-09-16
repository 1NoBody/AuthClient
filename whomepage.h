/*************************************************************
 * whomepage.h
 * Function: 首页界面
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WHOMEPAGE_H
#define WHOMEPAGE_H

#include "wbase.h"

class WHomePage : public WBase
{
    Q_OBJECT

public:
    WHomePage(QWidget *parent = NULL);
    ~WHomePage();

private:
    QPushButton *Auth_Button;

private slots:
    void Auth_slot();
};

#endif // WHOMEPAGE_H

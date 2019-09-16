/*************************************************************
 * wauthfailure.h
 * Function: 认证失败界面
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WAUTHFAILURE_H
#define WAUTHFAILURE_H

#include "wbase.h"

class WAuthFail : public WBase
{
    Q_OBJECT

public:
    WAuthFail(QWidget *parent = NULL);
    ~WAuthFail();

    QLabel      *Title_Label;

private:
    QLabel      *Icon_Label;
    QPushButton *Back_Button;

private slots:

};

#endif // WAUTHFAILURE_H

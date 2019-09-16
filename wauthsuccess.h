/*************************************************************
 * wauthsuccess.h
 * Function: 认证成功界面
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WAUTHSUCCESS_H
#define WAUTHSUCCESS_H

#include "wbase.h"

class WAuthSuccess : public WBase
{
    Q_OBJECT

public:
    WAuthSuccess(QWidget *parent = NULL);
    ~WAuthSuccess();

    QLabel *Photo_Label;
    QLineEdit *Voucher_Edit;
    QLineEdit *Name_Edit;
    QLineEdit *IDnum_Edit;


private:
    QLabel *Icon_Label;
    QLabel *Title_Label;
    QLabel *Voucher_Label;
    QLabel *Name_Label;
    QLabel *IDnum_Label;
    QPushButton *Back_Button;

private slots:

};

#endif // WAUTHSUCCESS_H

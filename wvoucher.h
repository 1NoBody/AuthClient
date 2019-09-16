/*************************************************************
 * wvoucher.h
 * Function: 证件类型选择
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WVOUCHER_H
#define WVOUCHER_H

#include <QtGui>

#include "wbase.h"


class WVoucher : public WBase
{
    Q_OBJECT
public:
    WVoucher(QWidget *parent = NULL);
    ~WVoucher();

private:
    QLabel      *Title_Label;
    QPushButton *IDcard_Button;
    QPushButton *Passport_Button;
    QPushButton *GatePass_Button; //出入境证件

private slots:
    void IDcard_slot();
    void Passport_slot();
    void GatePass_slot();
};


#endif // WVOUCHER_H

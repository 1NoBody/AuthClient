/*************************************************************
 * wreadvoucher.h
 * Function: 纯读证显示界面
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WREADVOUCHER_H
#define WREADVOUCHER_H

#include "wbase.h"

class WReadVoucher : public WBase
{
    Q_OBJECT

public:
    WReadVoucher(QWidget *parent = NULL);
    ~WReadVoucher();

    QLabel *NameText_Label;
    QLabel *SexText_Label;
    QLabel *NationText_Label;
    QLabel *YearText_Label;
    QLabel *MonthText_Label;
    QLabel *DateText_Label;
    QLabel *AddrText_Label;
    QLabel *IdNumberText_Label;
    QLabel *IssuingAuthorityText_Label;
    QLabel *ValidPeriodText_Label;

    QLabel *Photo_Label;

private:
    QLabel *Name_Label;
    QLabel *Sex_Label;
    QLabel *Nation_Label;
    QLabel *Birth_Label;
    QLabel *Year_Label;
    QLabel *Month_Label;
    QLabel *Date_Label;
    QLabel *Addr_Label;
    QLabel *IdNumber_Label;
    QLabel *IssuingAuthority_Label;
    QLabel *ValidPeriod_Label;

    QPushButton *Back_Button;

private slots:

};

#endif // WREADVOUCHER_H

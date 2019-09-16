/*************************************************************
 * wmachinecode.h
 * Function: 机读码输入界面
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WMACHINECODE_H
#define WMACHINECODE_H

#include <QValidator>

#include "wbase.h"

typedef enum{
    IDCARD,
    Passport,
    Gatepass
}MACHINECODE;

class WMachineCode : public WBase
{
    Q_OBJECT
public:
    WMachineCode(QWidget *parent = NULL, MACHINECODE MachineCode = IDCARD);
    ~WMachineCode();

private:

    QLabel *Title_Label;
    QLabel *Example_Label;
    QLabel *Area1_Label;
    QLabel *Area2_Label;
    QLabel *Area3_Label;

    QValidator  *validator;
    QLineEdit   *Area1_Edit;
    QLineEdit   *Area2_Edit;
    QLineEdit   *Area3_Edit;

    QPushButton *Example_Button; //预留 点击放大
    QPushButton *Preview_Button;
    QPushButton *Auth_Button;

private slots:
    void Example_slot();
    void Preview_slot();
    void Auth_slot();
    void MenuBack_slot();
};

#endif // WMACHINECODE_H

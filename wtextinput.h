/*************************************************************
 * wtextinput.h
 * Function: 输入认证信息界面
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WTEXTINPUT_H
#define WTEXTINPUT_H

#include "wbase.h"


class WTextInput : public WBase
{
    Q_OBJECT

public:
    WTextInput(QWidget *parent = NULL);
    ~WTextInput();


private:
    QLabel *Title_Label;
    QLabel *Voucher_Label;
    QLabel *Name_Label;
    QLabel *IDnum_Label;

    QComboBox *Voucher_ComboBox;
    QRegExpValidator  *validator; //利用正则表达式设置编辑框属性
    QLineEdit *Name_Edit;
    QLineEdit *IDnum_Edit;

    QPushButton *Preview_Button;
    QPushButton *Auth_Button;

    QString VoucherName;
    QString VoucherType;

    bool CheckIdCard(QString IDnum); //第二代身份证校验

private slots:
    void Preview_slot();
    void Auth_slot();
    void Voucher_slot();
};


#endif // WTEXTINPUT_H

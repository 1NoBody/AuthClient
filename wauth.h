/*************************************************************
 * wauth.h
 * Function: 选择认证方式界面
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WAUTH_H
#define WAUTH_H

#include "wbase.h"

class WAuth : public WBase
{
    Q_OBJECT

public:
    WAuth(QWidget *parent = NULL);
    ~WAuth();

private:
    QPushButton *IDcard_Button;
    QPushButton *QRcode_Button;
    QPushButton *TextInput_Button;
    QPushButton *ReadCard_Button;

private slots:
    void IDcard_slot();
    void QRcode_slot();
    void TextInput_slot();
    void ReadCard_slot();
    void MenuBack_slot();
};

#endif // WAUTH_H

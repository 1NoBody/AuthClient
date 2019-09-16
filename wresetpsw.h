/*************************************************************
 * wresetpsw.h
 * Function: 修改密码界面
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WRESETPSW_H
#define WRESETPSW_H

#include "wbase.h"


class WResetPsw : public QDialog
{
    Q_OBJECT
public:
    WResetPsw(WBase *parent = NULL);
    ~WResetPsw();

private:
    WBase *Parent;

    QLabel *Title_Label;
    QLabel *OldPsw_Label;
    QLabel *NewPsw_Label;
    QLabel *ConfirmPsw_Label;

    QLineEdit *OldPsw_Edit;
    QLineEdit *NewPsw_Edit;
    QLineEdit *ConfirmPsw_Edit;

    QPushButton *Confirm_Button;
    QPushButton *Cancel_Button;

private slots:
    void Confirm_slot();
    void Cancel_slot();
};


#endif // WRESETPSW_H

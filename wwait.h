/*************************************************************
 * wwait.h
 * Function: 等待用户操作
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WWAIT_H
#define WWAIT_H

#include "wbase.h"

class WWait : public WBase
{
    Q_OBJECT

public:
    WWait(QWidget *parent = NULL);
    ~WWait();

    static QTimer *Timer; //for test
    static bool isShow;

private:
    QLabel *TextTip_Label;

private slots:
    void Timeout_slot();

};

#endif // WWAIT_H

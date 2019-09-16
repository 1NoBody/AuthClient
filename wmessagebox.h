/*************************************************************
 * wmessagebox.h
 * Function: 自定义弹窗
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef WMESSAGEBOX_H
#define WMESSAGEBOX_H


#include "wbase.h"

typedef enum{
  NoButton  ,
  ButtonOne ,
  ButtonTwo ,
}ButtonNum;

class WMessagebox : public QDialog
{
   Q_OBJECT

public:
   WMessagebox( QWidget *parent = NULL, QString Icon = NULL, QString Title = NULL, QString Text = NULL,
               ButtonNum num = NoButton,QString BText1 = NULL, QString BText2 = NULL);  // BText1 == reject BText2 == accept
   ~WMessagebox();

   QPushButton *Button1;
   QPushButton *Button2;

private:
   QLabel *Icon_Label;
   QLabel *Text_Label;
   QLabel *BackgroundColor_Label;


private slots:
   void Button1_slot();
   void Button2_slot();

};

#endif // WMESSAGEBOX_H

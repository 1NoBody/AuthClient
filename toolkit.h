/*************************************************************
 * toolkit.h
 * Function: 提供各种功能性接口
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef TOOLKIT_H
#define TOOLKIT_H

#include <QBuffer>
#include <QDebug>
#include <QtGui>



QPixmap Base64ToImage(QByteArray bytearray, QString SavePath = NULL);  //base64 转图片
QString SetCiphertext(QString &str, int beginIndex = 0, int endIndex = -1);  // 脱敏处理 beginIndex == 起点加密  beginIndex == 终点加密
void Delay(int stopTime = 10); //延时函数 缓解界面切换闪烁问题  stopTime （ms）

#endif // TOOLKIT_H

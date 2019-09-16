/*************************************************************
 * jsonpack.h
 * Function:通信协议  json数据格式
 * Author:ljx
 * Create Date:2019.09.10
 * Modify Date:2019.09.10
 * Version:1.0.0
 * ***********************************************************/

#ifndef JSONPACK_H
#define JSONPACK_H

typedef enum
{
    Init            = 0,
    IDcard          = 1,        //身份证认证请求包
    QRcode          = 2,        //二维码认证请求包
    TextInput       = 3,        //文本认证请求包
    Preview         = 4,        //信息预览
    Auth            = 5,        //文本认证
    AUTHSUCCESS     = 6,        //认证成功
    AUTHFAILURE     = 7,        //认证失败
    BackAuth        = 8,        //返回认证选择界面
    HeartBeat       = 9,        //心跳包  预留

    //add by ljx on 20190909
    ReadCard        = 10,       //纯读证
    ReadCard_S      = 11,       //读证成功
    BackMachineCode = 12,       //返回机读码界面
}J_TYPE;

/*********************************************************************
 *
 *
 *
//认证机sendmessage  1带照片（包头 + 包体） 2 不带照片 单包
//包头格式
{
    "Jtype"     : int,
    "Jsize"     : int,
}

//包体格式
//认证成功  //包头 AuthSuccess
{
    "Voucher"   : "string", //证件类型  // 101 == 第二代居民身份证  414 == 普通护照  516 == 港澳居民来往内地通行证
    "Name"      : "string", //姓名
    "ID_number" : "string", //身份号码
    "photo"     : "string"  //base64编码
}

//纯读证成功
{
    "Name"      :"string",
    "Sex"       :"string",
    "Nation"    :"string",
    "Birth"     :"string",
    "Addr"      :"string",
    "IDnum"     :"string",
    "IssuingAuthority"  :"string", //签发机关
    "ValidPeriod"       :"string", //有效日期
    "Photo"     :"string"
}

//认证失败 单包
{
    "Jtype"     : AUTHFAILURE,
    "reason"    : int  // 1 == 身份不匹配 2 == 网络异常
}




//客户端sendmessage（单包）
//通用
{
    "Jtype"  : int,
}

//机读码信息预览 || 文本认证  // 类型 Preview || Auth
{
    "Jtype"         : int   //数据类型
    "firstArea"     : "string"
    "secondArea"    : "string"
    "thirdArea"     : "string"
}

//信息输入信息预览 || 文本认证  // 类型 Preview || Auth
{
    "Jtype"         : int
    "Voucher"       : "string" //证件类型  // 101 == 第二代居民身份证  414 == 普通护照  516 == 港澳居民来往内地通行证
    "Name"          : "string"
    "ID_number"     : "string"
}

*************************************************************/

#endif // JSONPACK_H

#include <QApplication>

#include "wbase.h"
#include "wlogin.h"
#include "socket.h"
#include "wmessagebox.h"

enum WinVersion {
        WV_32s      = 0x0001,
        WV_95       = 0x0002,
        WV_98       = 0x0003,
        WV_Me       = 0x0004,
        WV_DOS_based= 0x000f,

        /* codenames */
        WV_NT       = 0x0010,
        WV_2000     = 0x0020,
        WV_XP       = 0x0030,
        WV_2003     = 0x0040,
        WV_VISTA    = 0x0080,
        WV_WINDOWS7 = 0x0090,
        WV_NT_based = 0x00f0,

        /* version numbers */
        WV_4_0      = WV_NT,
        WV_5_0      = WV_2000,
        WV_5_1      = WV_XP,
        WV_5_2      = WV_2003,
        WV_6_0      = WV_VISTA,
        WV_6_1      = WV_WINDOWS7,

        WV_CE       = 0x0100,
        WV_CENET    = 0x0200,
        WV_CE_5     = 0x0300,
        WV_CE_6     = 0x0400,
        WV_CE_based = 0x0f00
    };

QWidget *wCurrent = NULL;  //指向当前窗口对象

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8")); //中文乱码
    QDir::setCurrent(a.applicationDirPath());//支持相对路径
    QApplication::addLibraryPath("./"); //插件路径

    //字体设置
    QFont font;
    QSysInfo::WinVersion ver = QSysInfo::windowsVersion();
    switch(ver){
    case WV_XP:
    case WV_2003:
        font.setFamily("SimHei");
        break;
    default:
        font.setFamily("Microsoft YaHei");  //微软雅黑
        break;
    }
    a.setFont(font);

    WLogin *w = new WLogin;
    wCurrent = w;
    w->show();

    //连接认证机
    Socket socket;
    if (Socket::Connect() == false){
        WMessagebox msgBox(wCurrent, NULL, "温馨提示", "配置文件异常或缺失", ButtonOne, QString("确定"));
        msgBox.exec();
    }

    return a.exec();
}

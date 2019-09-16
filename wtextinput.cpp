#include "wtextinput.h"
#include "wwait.h"
#include "toolkit.h"
#include "wmessagebox.h"
#include "socket.h"

WTextInput::WTextInput(QWidget *parent)
    :WBase(parent)
{
    Line_Label->show();
    CreatePersonCenter();
    CreateBack();
    CreateHomePage();

    //请输入身份信息
    this->Title_Label = new QLabel(this);
    Title_Label->setGeometry(437,178,126,18);
    Title_Label->setText(QString("请输入身份信息"));
    Title_Label->setStyleSheet("font:18px;");

    //证件类型标签
    this->Voucher_Label = new QLabel(this);
    Voucher_Label->setGeometry(323, 236, 60, 14);
    Voucher_Label->setText(QString("证件类型:"));
    Voucher_Label->setStyleSheet("font:14px;");

    //姓名标签
    this->Name_Label = new QLabel(this);
    Name_Label->setGeometry(351, 291, 32, 14);
    Name_Label->setText(QString("姓名:"));
    Name_Label->setStyleSheet("font:14px;");

    //身份号码标签
    this->IDnum_Label = new QLabel(this);
    IDnum_Label->setGeometry(323, 346, 60, 14);
    IDnum_Label->setText(QString("证件号码:"));
    IDnum_Label->setStyleSheet("font:14px;");

    //证件类型下拉框
    this->Voucher_ComboBox = new QComboBox(this);
    Voucher_ComboBox->setGeometry(398, 223, 240, 40);
    Voucher_ComboBox->setStyleSheet("QComboBox::drop-down{border-style:none;}"
                                    "QComboBox::down-arrow{image:url(:/resource/image/wTextInput/arrow.png);}"
                                    "QComboBox{border-radius:4px;border:1px solid rgb(211,211,211); font: 14px}" //边框色
                                    "QComboBox QAbstractItemView::item{height:30px;}" //下拉表间距
                                    );
    Voucher_ComboBox->setView(new QListView()); //使下拉框间距设置生效
    Voucher_ComboBox->addItem(QString("  第二代居民身份证"));
    Voucher_ComboBox->addItem(QString("  普通护照"));
    Voucher_ComboBox->addItem(QString("  港澳居民来往内地通行证"));
    connect( Voucher_ComboBox, SIGNAL(activated( int )), this, SLOT(Voucher_slot()));

    //姓名编辑框
    this->Name_Edit = new QLineEdit(this);
    Name_Edit->setGeometry(398, 278, 240, 40);
    Name_Edit->setPlaceholderText("  请输入姓名");
    Name_Edit->setStyleSheet("border-radius:4px;border:1px solid rgb(211,211,211);font: 14px;");

    //证件号码编辑框
    QRegExp regx("[xX0-9]+$"); //设置编辑框输入限制
    this->validator = new QRegExpValidator(regx,this);

    this->IDnum_Edit = new QLineEdit(this);
    IDnum_Edit->setGeometry(398, 333, 240, 40);
    IDnum_Edit->setPlaceholderText("  请输入证件号码");
    IDnum_Edit->setStyleSheet("border-radius:4px;border:1px solid rgb(211,211,211);font: 14px;");
    IDnum_Edit->setMaxLength(18);
    IDnum_Edit->setValidator(validator);

    //预览按钮
    this->Preview_Button = new QPushButton(this);
    Preview_Button->setGeometry(398, 388, 112, 40);
    Preview_Button->setText(QString("确认信息"));
    Preview_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:14px; border-radius:4px;}"
                                  "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                                  "QPushButton:hover{background-color:rgba(0,191,255,150)}");
    connect(Preview_Button,SIGNAL(clicked(bool)),this,SLOT(Preview_slot()));

    //认证按钮
    this->Auth_Button = new QPushButton(this);
    Auth_Button->setGeometry(526, 388, 112, 40);
    Auth_Button->setText(QString("下一步"));
    Auth_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:14px; border-radius:4px;}"
                               "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                               "QPushButton:hover{background-color:rgba(0,191,255,150)}");
    connect(Auth_Button,SIGNAL(clicked(bool)),this,SLOT(Auth_slot()));

    VoucherName = QString("第二代居民身份证");
    VoucherType = "101";
}

WTextInput::~WTextInput()
{

}

bool WTextInput::CheckIdCard(QString IDnum) {
    if (IDnum.length() != 18)
        return false;

    //加权因子
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    //校验码表
    char validateCodes[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int sum = 0;
    for(int i = 0; i < 17; i++) {
        sum = sum + (IDnum.at(i).digitValue()) * weight[i];
    }
    int mod = sum % 11;
    if (mod == 2) {
        return validateCodes[mod] == 'x' || validateCodes[mod] == 'X';
    }
    return validateCodes[mod] == IDnum[17];
}


void WTextInput::Preview_slot()
{
    bool checkIDnum = true;
    switch (VoucherType.toInt()) {
    case 101:
    {
        if(Name_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入姓名", ButtonOne, QString("确定"));
            msgBox.exec();
        }
        else if(false == CheckIdCard(IDnum_Edit->text())){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "身份号码无效", ButtonOne, QString("确定"));
            msgBox.exec();
        }
    }
        break;
    case 414:
    {
        if(Name_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入姓名", ButtonOne, QString("确定"));
            msgBox.exec();
        }
        else if(IDnum_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入证件号码", ButtonOne, QString("确定"));
            msgBox.exec();
        }
    }
        break;
    case 516:
    {
        if(Name_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入姓名", ButtonOne, QString("确定"));
            msgBox.exec();
        }
        else if(IDnum_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入证件号码", ButtonOne, QString("确定"));
            msgBox.exec();
        }
    }
        break;
    default:
        break;
    }

    if(checkIDnum){
        //json send
        Socket::Json->clear();
        Socket::Json->add(QString("Jtype"),Preview);
        Socket::Json->add(QString("Voucher"),VoucherType);
        Socket::Json->add(QString("ID_number"),IDnum_Edit->text());
        QString json = Socket::Json->toString().replace('}',"") + ",\"Name\":" + "\"" + Name_Edit->text() + "\"" + "}";  //解决 · 显示乱码问题
        //qDebug() << json;
        Socket::TcpSocket->write(json.toStdString().c_str());
    }
}

void WTextInput::Auth_slot()
{
    //WWait::Timer->start(2000);
    bool checkIDnum = true;
    switch (VoucherType.toInt()) {
    case 101:
    {
        if(Name_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入姓名", ButtonOne, QString("确定"));
            msgBox.exec();
        }
        else if(false == CheckIdCard(IDnum_Edit->text())){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "身份号码无效", ButtonOne, QString("确定"));
            msgBox.exec();
        }
    }
        break;
    case 414:
    {
        if(Name_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入姓名", ButtonOne, QString("确定"));
            msgBox.exec();
        }
        else if(IDnum_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入证件号码", ButtonOne, QString("确定"));
            msgBox.exec();
        }
    }
        break;
    case 516:
    {
        if(Name_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入姓名", ButtonOne, QString("确定"));
            msgBox.exec();
        }
        else if(IDnum_Edit->text() == NULL){
            checkIDnum = false;
            WMessagebox msgBox(this, NULL, "温馨提示", "请输入证件号码", ButtonOne, QString("确定"));
            msgBox.exec();
        }
    }
        break;
    default:
        break;
    }

    if(checkIDnum){
        //json send
        Socket::Json->clear();
        Socket::Json->add(QString("Jtype"),Auth);
        Socket::Json->add(QString("Voucher"),VoucherType);
        Socket::Json->add(QString("ID_number"),IDnum_Edit->text());
        QString json = Socket::Json->toString().replace('}',"") + ",\"Name\":" + "\"" + Name_Edit->text() + "\"" + "}";  //解 · 显示乱码问题
        Socket::TcpSocket->write(json.toStdString().c_str());

        WWait *w = new WWait(this);
        wCurrent = w;
        w->show();
        Delay();
        delete this;
    }

}

void WTextInput::Voucher_slot()
{
    IDnum_Edit->clear();
    VoucherName  = Voucher_ComboBox->currentText();
    if("  第二代居民身份证" == VoucherName){
        VoucherType = "101";
        delete validator;
        validator = NULL;
        QRegExp regx("[xX0-9]+$"); //设置编辑框输入限制
        IDnum_Edit->setValidator((validator = new QRegExpValidator(regx,this)));
        IDnum_Edit->setMaxLength(18);
    }
    else if("  普通护照" == VoucherName){
        VoucherType = "414";
        delete validator;
        validator = NULL;
        QRegExp regx("[a-zA-Z0-9]+$"); //设置编辑框输入限制
        IDnum_Edit->setValidator((validator = new QRegExpValidator(regx,this)));
        IDnum_Edit->setMaxLength(-1);
    }
    else if("  港澳居民来往内地通行证" == VoucherName){
        VoucherType = "516";
        delete validator;
        validator = NULL;
        QRegExp regx("[a-zA-Z0-9]+$"); //设置编辑框输入限制
        IDnum_Edit->setValidator((validator = new QRegExpValidator(regx,this)));
        IDnum_Edit->setMaxLength(-1);
    }
}

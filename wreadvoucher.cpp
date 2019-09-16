#include "wreadvoucher.h"

WReadVoucher::WReadVoucher(QWidget *parent)
    :WBase(parent)
{
    Line_Label->show();
    CreatePersonCenter();
    CreateBack();
    CreateHomePage();

    //姓名标签
    this->Name_Label = new QLabel(this);
    Name_Label->setGeometry(314, 166, 43, 16);
    Name_Label->setText(QString("姓 名"));
    Name_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->NameText_Label = new QLabel(this);
    NameText_Label->setGeometry(369, 166, 16 * 10, 16);
    //NameText_Label->setText(QString("林建雄"));
    NameText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //民族标签
    this->Nation_Label = new QLabel(this);
    Nation_Label->setGeometry(439, 196, 43, 16);
    Nation_Label->setText(QString("民 族"));
    Nation_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->NationText_Label = new QLabel(this);
    NationText_Label->setGeometry(494, 196, 16 * 5, 16);
    //NationText_Label->setText(QString("乌孜别克族"));
    NationText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //性别标签
    this->Sex_Label = new QLabel(this);
    Sex_Label->setGeometry(314, 196, 43, 16);
    Sex_Label->setText(QString("性 别"));
    Sex_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->SexText_Label = new QLabel(this);
    SexText_Label->setGeometry(369, 196, 16 * 1, 16);
    //SexText_Label->setText(QString("男"));
    SexText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");


    //出身标签
    this->Birth_Label = new QLabel(this);
    Birth_Label->setGeometry(314, 226, 43, 16);
    Birth_Label->setText(QString("出 身"));
    Birth_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    //年份标签
    this->Year_Label = new QLabel(this);
    Year_Label->setGeometry(410, 226, 16, 16);
    Year_Label->setText(QString("年"));
    Year_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->YearText_Label = new QLabel(this);
    YearText_Label->setGeometry(369, 226, 9 * 4, 16);
    //YearText_Label->setText(QString("1995"));
    YearText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //月份标签
    this->Month_Label = new QLabel(this);
    Month_Label->setGeometry(458, 226, 16, 16);
    Month_Label->setText(QString("月"));
    Month_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->MonthText_Label = new QLabel(this);
    MonthText_Label->setGeometry(432, 226, 9 * 2, 16);
    //MonthText_Label->setText(QString("07"));
    MonthText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //日标签
    this->Date_Label = new QLabel(this);
    Date_Label->setGeometry(506, 226, 16, 16);
    Date_Label->setText(QString("日"));
    Date_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->DateText_Label = new QLabel(this);
    DateText_Label->setGeometry(480, 226, 9 * 2, 16);
    //DateText_Label->setText(QString("16"));
    DateText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //地址标签
    this->Addr_Label = new QLabel(this);
    Addr_Label->setGeometry(314, 256, 43, 16);
    Addr_Label->setText(QString("地 址"));
    Addr_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->AddrText_Label = new QLabel(this);
    AddrText_Label->setGeometry(369, 254, 16 * 12, 16 * 2 + 5);
    AddrText_Label->setWordWrap(true); //自动换行
    //AddrText_Label->setText(QString("福建省莆田市荔城区新都镇白城村园顶22号"));
    AddrText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //IDNumber标签
    this->IdNumber_Label = new QLabel(this);
    IdNumber_Label->setGeometry(314, 310, 102, 16);
    IdNumber_Label->setText(QString("公民身份号码"));
    IdNumber_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->IdNumberText_Label = new QLabel(this);
    IdNumberText_Label->setGeometry(442, 310, 9 * 18, 16);
    //IdNumberText_Label->setText(QString("350321199507162615"));
    IdNumberText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //签发机关标签
    this->IssuingAuthority_Label = new QLabel(this);
    IssuingAuthority_Label->setGeometry(314, 340, 68, 16);
    IssuingAuthority_Label->setText(QString("签发机关"));
    IssuingAuthority_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->IssuingAuthorityText_Label = new QLabel(this);
    IssuingAuthorityText_Label->setGeometry(400, 340, 16 * 10, 16);
    //IssuingAuthorityText_Label->setText(QString("新都镇派出所公安局"));
    IssuingAuthorityText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //有效日期标签
    this->ValidPeriod_Label = new QLabel(this);
    ValidPeriod_Label->setGeometry(314, 370, 68, 16);
    ValidPeriod_Label->setText(QString("有效期限"));
    ValidPeriod_Label->setStyleSheet("opacity: 0.6; font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 153); line-height: 16px;");

    this->ValidPeriodText_Label = new QLabel(this);
    ValidPeriodText_Label->setGeometry(400, 370, 9 * 20, 16);
    //ValidPeriodText_Label->setText(QString("1995.07.06-2019.09.09"));
    ValidPeriodText_Label->setStyleSheet("font-family: PingFangSC-Regular; font-size: 16px; color:rgba(19, 27, 76, 255); line-height: 16px;");

    //照片标签
    this->Photo_Label = new QLabel(this);
    Photo_Label->setGeometry(597, 166, 90, 120);
    Photo_Label->setText(QString("照片"));
    Photo_Label->setAlignment(Qt::AlignCenter);
    Photo_Label->setStyleSheet("color: rgb(0, 0, 0);""font:20px;""background-color: gray;");

    //返回按钮
    this->Back_Button = new QPushButton(this);
    Back_Button->setGeometry(430, 431, 140, 40);
    Back_Button->setText(QString("返回"));
    Back_Button->setStyleSheet("QPushButton{color:#FFFFFF; font:14px; border-radius:4px;}"
                               "QPushButton{background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #23A9F5 ,stop:1 #2B8BF2)}"
                               "QPushButton:hover{background-color:rgba(0,191,255,150)}");
    connect(Back_Button,SIGNAL(clicked(bool)),this,SLOT(MenuBack_slot()));
}

WReadVoucher::~WReadVoucher()
{

}

#include "rc.h"
#include "ui_rc.h"
//#include "ui_mainwindow.h"
#include "resouse.h"

#include <QMessageBox>
#include <QTextStream>
#include <QPushButton>
#include <QFileDialog>
#include <string.h>
#include <QString>
#include <string>
#include <QLabel>
#include <QFont>

using namespace std;

RC::RC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RC)
{
    ui->setupUi(this);
    curFile = tr("辈分计算器");
    setWindowTitle(curFile);

}

RC::~RC()
{
    delete ui;
}

void RC::on_faBtn_clicked() //+a
{
    input += "的父亲";
    ui->lineEdit->setText(input);
    out=out+"a";

}

void RC::on_maBtn_clicked()  //+b
{
    input += "的母亲";
    ui->lineEdit->setText(input);
     out=out+"b";
}

void RC::on_xiongBtn_clicked()  //+g
{
    input += "的哥哥";
    ui->lineEdit->setText(input);
     out=out+"g";

}

void RC::on_jieBtn_clicked()   //+i
{
    input += "的姐姐";
    ui->lineEdit->setText(input);
     out=out+"i";
}

void RC::on_hanBtn_clicked()   //+c
{
    input += "的丈夫";
    ui->lineEdit->setText(input);
     out=out+"c";

}

void RC::on_wifeBtn_clicked()  //+d
{
    input += "的妻子";
    ui->lineEdit->setText(input);
     out=out+"d";

}

void RC::on_diBtn_clicked()  //+h
{
    input += "的弟弟";
    ui->lineEdit->setText(input);
     out=out+"h";

}

void RC::on_meiBtn_clicked()  //+j
{
    input += "的妹妹";
    ui->lineEdit->setText(input);
     out=out+"j";

}

void RC::on_sonBtn_clicked()  //+e
{
    input += "的儿子";
    ui->lineEdit->setText(input);
     out=out+"e";

}

void RC::on_durBtn_clicked() //+f
{
    input += "的女儿";
    ui->lineEdit->setText(input);
     out=out+"f";
}

void RC::on_searchBtn_clicked()//judge and calculate
{
    out2=out.toStdString();
    x = out.length(); 
    switch (out2[x-1])// read y in the this step
    {
        case 'a' : y=0;break;
        case 'b' : y=1;break;
        case 'c' : y=2;break;
        case 'd' : y=3;break;
        case 'e' : y=4;break;
        case 'f' : y=5;break;
        case 'g' : y=6;break;
        case 'h' : y=7;break;
        case 'i' : y=8;break;
        case 'j' : y=9;break;
     }
       if(x==1)
          ui->lineEdit->setText(chu[y]);
       else if(x==2)
          switch (out2[0]){
              case 'a' : ui->lineEdit->setText(a[y]);break;
              case 'b' : ui->lineEdit->setText(b[y]);break;
              case 'c' : ui->lineEdit->setText(c[y]);break;
              case 'd' : ui->lineEdit->setText(d[y]);break;
              case 'e' : ui->lineEdit->setText(e[y]);break;
              case 'f' : ui->lineEdit->setText(f[y]);break;
              case 'g' : ui->lineEdit->setText(g[y]);break;
              case 'h' : ui->lineEdit->setText(h[y]);break;
              case 'i' : ui->lineEdit->setText(i[y]);break;
              case 'j' : ui->lineEdit->setText(j[y]);break;
        }
       else if(x==3)
       {

           out = out.left(out.length()-1);
           out2=out.toStdString();
           for(int i=0;i<100;i++)
           {
               if( out2 == ku[i].name)
               {
                   out = QString::fromStdString(ku[i].rela[y]);
                   ui->lineEdit->setText(out);
                   recore=1;
                   break;
               }
           }
       }
       else
       { if(recore==0)
               ui->lineEdit->setText(tr("他/她好像跟你不熟哦"));
       }
}

void RC::on_bsBtn_clicked() //backspace btn , redefine record=0 everytimes
{
    input = input.left(input.length()-3);
    if(input=="")input="我";
    out = out.left(out.length()-1);
    ui->lineEdit->setText(input);
    recore =0;
}

void RC::on_acBtn_clicked() //reference upon
{
    input="我";
    ui->lineEdit->setText(input);
    out="";
    recore=0;
}

#include "myjsq.h"
#include "ui_myjsq.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Myjsq::Myjsq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Myjsq)
{
    ui->setupUi(this);
}

Myjsq::~Myjsq()
{
    delete ui;
}


void Myjsq::two_to_ten(const char * inputS ,char outputS[])
{
    int i,l,result_1=0;
    l=strlen(inputS);
    for(i=0;i<l;i++)
    {
        result_1=inputS[i]-48+result_1*2;
    }
    sprintf(outputS,"%d",result_1);
}

void Myjsq::eig_to_ten(const char * inputS ,char outputS[])
{
    int i,l,result_1=0;
    l=strlen(inputS);
    for(i=0;i<l;i++)
    {
        result_1=inputS[i]-48+result_1*8;
    }
    sprintf(outputS,"%d",result_1);
}

void Myjsq::six_to_ten(const char * inputS ,char outputS[])
{
    int i,l,result_1=0;
    l=strlen(inputS);
    for(i=0;i<l;i++)
    {
        if(inputS[i]>47&&inputS[i]<58)
            result_1=inputS[i]-48+result_1*16;
        if(inputS[i]>64&&inputS[i]<71)
            result_1=inputS[i]-55+result_1*16;
    }
    sprintf(outputS,"%d",result_1);
}

void Myjsq::ten_to_two(const char * inputS ,char outputS[])
{
    int i,j,l,r=0;
    char str[1000]={0};
    char output1[1000]={0};
    l=strlen(inputS);
    for(i=0;i<l;i++)
    {
        r=inputS[i]-48+r*10;
    }
    while(r!=0)
    {
        sprintf(str,"%d",r%2);
        strcat(output1,str);
        memset(str,0,sizeof(str));
        r=(r-r%2)/2;
    }
    l=strlen(output1);
    for(i=0,j=l-1;i<l;i++,j--)
    {
        outputS[j]=output1[i];
    }
}

void Myjsq::ten_to_eig(const char * inputS ,char outputS[])
{
    int i,j,l,r=0;
    char str[1000]={0};
    char output1[1000]={0};
    l=strlen(inputS);
    for(i=0;i<l;i++)
    {
        r=inputS[i]-48+r*10;
    }
    while(r!=0)
    {
        sprintf(str,"%d",r%8);
        strcat(output1,str);
        memset(str,0,sizeof(str));
        r=(r-r%8)/8;
    }
    l=strlen(output1);
    for(i=0,j=l-1;i<l;i++,j--)
    {
        outputS[j]=output1[i];
    }
}

void Myjsq::ten_to_six(const char * inputS ,char outputS[])
{
    int i,j,l,r=0;
    char str[1000]={0};
    char output1[1000]={0};
    l=strlen(inputS);
    for(i=0;i<l;i++)
    {
        r=inputS[i]-48+r*10;
    }
    while(r!=0)
    {
        if(r%16<10)
        {
            sprintf(str,"%d",r%16);
        }
        else
        {
            if(r%16==10)
                sprintf(str,"A");
            if(r%16==11)
                sprintf(str,"B");
            if(r%16==12)
                sprintf(str,"C");
            if(r%16==13)
                sprintf(str,"D");
            if(r%16==14)
                sprintf(str,"E");
            if(r%16==15)
                sprintf(str,"F");
        }
        strcat(output1,str);
        memset(str,0,sizeof(str));
        r=(r-r%16)/16;
    }
    l=strlen(output1);
    for(i=0,j=l-1;i<l;i++,j--)
    {
        outputS[j]=output1[i];
    }
}

void Myjsq::char_to_int(const char * inputS,int &out)
{
    out=0;
    int i,l;
    l=strlen(inputS);
    for(i=0;i<l;i++)
    {
        out=inputS[i]-48+out*10;
    }
}

void Myjsq::deal(const char * inputS ,char str1[],char str2[])
{
    int i,j,l;
    l=strlen(inputS);
    for(i=0;i<l;i++)
    {
        if(inputS[i]>41&&inputS[i]<48)
        {
            judge=1;
            symbol=inputS[i];
            break;
        }
        else
        {
            judge=0;
            str1[i]=inputS[i];
        }
    }
    for(j=i+1,i=0;j<l;j++,i++)
    {
        if(inputS[j]>41&&inputS[j]<48)
        {
            judge=2;
            break;
        }
        else
        {
            str2[i]=inputS[j];
        }
    }
}

void Myjsq::on_change_clicked()
{
    std::string str = input.toStdString();
    const char *S = str.c_str();
    char output[1000]={0};
    char str1[1000]={0};
    char str2[1000]={0};
    char output1[1000]={0};
    char output2[1000]={0};
    char result_2[1000]={0};
    char result_8[1000]={0};
    char result_16[1000]={0};
    char ch[1000]={0};
    char ch1[1000]={0};
    char ch2[1000]={0};
    char ch3[1000]={0};
    int out1,out2,out3;
    deal(S,str1,str2);
    if(judge==2)
    {
        ui->lineEdit2->setText("请减少运算符号，出错啦！");
        ui->lineEdit3->setText("请减少运算符号，出错啦！");
        ui->lineEdit4->setText("请减少运算符号，出错啦！");
        ui->lineEdit5->setText("请减少运算符号，出错啦！");
    }
    if(judge==0)
    {
        if(option==2)
        {
            two_to_ten(S,output);
            ten_to_two(output,result_2);
            ten_to_eig(output,result_8);
            ten_to_six(output,result_16);
            ui->lineEdit2->setText(QString::fromStdString(result_2));
            ui->lineEdit3->setText(QString::fromStdString(result_8));
            ui->lineEdit4->setText(QString::fromStdString(output));
            ui->lineEdit5->setText(QString::fromStdString(result_16));
        }
        if(option==8)
        {
            eig_to_ten(S,output);
            ten_to_two(output,result_2);
            ten_to_eig(output,result_8);
            ten_to_six(output,result_16);
            ui->lineEdit2->setText(QString::fromStdString(result_2));
            ui->lineEdit3->setText(QString::fromStdString(result_8));
            ui->lineEdit4->setText(QString::fromStdString(output));
            ui->lineEdit5->setText(QString::fromStdString(result_16));
        }
        if(option==10)
        {
            strcat(output,S);
            ten_to_two(output,result_2);
            ten_to_eig(output,result_8);
            ten_to_six(output,result_16);
            ui->lineEdit2->setText(QString::fromStdString(result_2));
            ui->lineEdit3->setText(QString::fromStdString(result_8));
            ui->lineEdit4->setText(QString::fromStdString(output));
            ui->lineEdit5->setText(QString::fromStdString(result_16));
        }
        if(option==16)
        {
            six_to_ten(S,output);
            ten_to_two(output,result_2);
            ten_to_eig(output,result_8);
            ten_to_six(output,result_16);
            ui->lineEdit2->setText(QString::fromStdString(result_2));
            ui->lineEdit3->setText(QString::fromStdString(result_8));
            ui->lineEdit4->setText(QString::fromStdString(output));
            ui->lineEdit5->setText(QString::fromStdString(result_16));
        }
    }
    if(judge==1)
    {
        if(option==2)
        {
            two_to_ten(str1,output1);
            two_to_ten(str2,output2);
        }
        if(option==8)
        {
            eig_to_ten(str1,output1);
            eig_to_ten(str2,output2);
        }
        if(option==10)
        {
            strcpy(output1,str1);
            strcpy(output2,str2);
        }
        if(option==16)
        {
            six_to_ten(str1,output1);
            six_to_ten(str2,output2);
        }
        char_to_int(output1,out1);
        char_to_int(output2,out2);
        if(symbol=='+')
        {
            out3=out1+out2;
            ui->lineEdit4->setText(QString::number(out3));
        }
        if(symbol=='-')
        {
            out3=out1-out2;
            ui->lineEdit4->setText(QString::number(out3));
        }
        if(symbol=='*')
        {
            out3=out1*out2;
            ui->lineEdit4->setText(QString::number(out3));
        }
        if(symbol=='/')
        {
            out3=out1/out2;
            ui->lineEdit4->setText(QString::number(out3));
        }
        sprintf(ch,"%d",out3);
        ten_to_two(ch,ch1);
        ui->lineEdit2->setText(QString::fromStdString(ch1));
        ten_to_eig(ch,ch2);
        ui->lineEdit3->setText(QString::fromStdString(ch2));
        ten_to_six(ch,ch3);
        ui->lineEdit5->setText(QString::fromStdString(ch3));
    }
    temp=1;
    symbol=' ';
}

void Myjsq::on_two_clicked()
{
    option=2;
}

void Myjsq::on_eight_clicked()
{
    option=8;
}

void Myjsq::on_ten_clicked()
{
    option=10;
}

void Myjsq::on_sixteen_clicked()
{
    option=16;
}

void Myjsq::on_q1_clicked()
{
    if(option>1)
    {
        if(temp==0)
            input+="1";
        if(temp==1)
        {
            input="1";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q2_clicked()
{
    if(option>2)
    {
        if(temp==0)
            input+="2";
        if(temp==1)
        {
            input="2";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q3_clicked()
{
    if(option>2)
    {
        if(temp==0)
            input+="3";
        if(temp==1)
        {
            input="3";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q4_clicked()
{
    if(option>2)
    {
        if(temp==0)
            input+="4";
        if(temp==1)
        {
            input="4";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q5_clicked()
{
    if(option>2)
    {
        if(temp==0)
            input+="5";
        if(temp==1)
        {
            input="5";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q6_clicked()
{
    if(option>2)
    {
        if(temp==0)
            input+="6";
        if(temp==1)
        {
            input="6";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q7_clicked()
{
    if(option>2)
    {
        if(temp==0)
            input+="7";
        if(temp==1)
        {
            input="7";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q8_clicked()
{
    if(option>8)
    {
        if(temp==0)
            input+="8";
        if(temp==1)
        {
            input="8";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q9_clicked()
{
    if(option>8)
    {
        if(temp==0)
            input+="9";
        if(temp==1)
        {
            input="9";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_q0_clicked()
{
    if(option>1)
    {
        if(temp==0)
            input+="0";
        if(temp==1)
        {
            input="0";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_A_clicked()
{
    if(option==16)
    {
        if(temp==0)
            input+="A";
        if(temp==1)
        {
            input="A";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_B_clicked()
{
    if(option==16)
    {
        if(temp==0)
            input+="B";
        if(temp==1)
        {
            input="B";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_C_clicked()
{
    if(option==16)
    {
        if(temp==0)
            input+="C";
        if(temp==1)
        {
            input="C";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_D_clicked()
{
    if(option==16)
    {
        if(temp==0)
            input+="D";
        if(temp==1)
        {
            input="D";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_E_clicked()
{
    if(option==16)
    {
        if(temp==0)
            input+="E";
        if(temp==1)
        {
            input="E";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_F_clicked()
{
    if(option==16)
    {
        if(temp==0)
            input+="F";
        if(temp==1)
        {
            input="F";
            temp=0;
        }
        ui->lineEdit1->setText(input);
    }
}

void Myjsq::on_add_clicked()
{
    if(temp==0)
        input+="+";
    ui->lineEdit1->setText(input);
}

void Myjsq::on_minus_clicked()
{
    if(temp==0)
        input+="-";
    ui->lineEdit1->setText(input);
}

void Myjsq::on_multiply_clicked()
{
    if(temp==0)
        input+="*";
    ui->lineEdit1->setText(input);
}

void Myjsq::on_divide_clicked()
{
    if(temp==0)
        input+="/";
    ui->lineEdit1->setText(input);
}

void Myjsq::on_AC_clicked()
{
    input="";
    ui->lineEdit1->setText(input);
    ui->lineEdit2->setText(input);
    ui->lineEdit3->setText(input);
    ui->lineEdit4->setText(input);
    ui->lineEdit5->setText(input);
}

void Myjsq::on_Del_clicked()
{
    input = input.left(input.length()-1);
    ui->lineEdit1->setText(input);
}

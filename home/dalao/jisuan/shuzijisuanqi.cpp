#include "shuzijisuanqi.h"
#include "ui_shuzijisuanqi.h"
#include <math.h>

shuzijisuanqi::shuzijisuanqi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shuzijisuanqi)
{
    ui->setupUi(this);
    ui->lineEdit->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_2->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit->setFont(QFont("Timers" , 28 ,  QFont::AnyStyle));
    ui->lineEdit->setText(input);
    ui->lineEdit_2->setFont(QFont("Timers" , 35 ,  QFont::AnyStyle));
    ui->lineEdit->setAlignment(Qt::AlignRight);
    ui->lineEdit_2->setAlignment(Qt::AlignRight);

}

shuzijisuanqi::~shuzijisuanqi()
{
    delete ui;
}

void shuzijisuanqi::on_oneBtn_clicked()
{
    input=input+"1";
    input1=input1+"1";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_twoBtn_clicked()
{
    input=input+"2";
    input1=input1+"2";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_threeBtn_clicked()
{
    input=input+"3";
    input1=input1+"3";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_fourBtn_clicked()
{
    input=input+"4";
    input1=input1+"4";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_fiveBtn_clicked()
{
    input=input+"5";
    input1=input1+"5";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_sixBtn_clicked()
{
    input=input+"6";
    input1=input1+"6";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_sevenBtn_clicked()
{
    input=input+"7";
    input1=input1+"7";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_eightBtn_clicked()
{
    input=input+"8";
    input1=input1+"8";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_nineBtn_clicked()
{
    input=input+"9";
    input1=input1+"9";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_equBtn_clicked()
{
    input=input+"/";
    input1=input1+"/";
    ui->lineEdit->setText(input1);
    output="";
    ui->lineEdit_2->setText(output);
}

void shuzijisuanqi::on_XBtn_clicked()
{
    input=input+"*";
    input1=input1+"*";
    ui->lineEdit->setText(input1);
    output="";
    ui->lineEdit_2->setText(output);
}

void shuzijisuanqi::on_jianBtn_clicked()
{
    input=input+"-";
    input1=input1+"-";
    ui->lineEdit->setText(input1);
    output="";
    ui->lineEdit_2->setText(output);
}

void shuzijisuanqi::on_addBtn_clicked()
{
    input=input+"+";
    input1=input1+"+";
    ui->lineEdit->setText(input1);
    output="";
    ui->lineEdit_2->setText(output);
}

void shuzijisuanqi::on_DelBtn_clicked()
{
    input = input.left(input.length()-1);
    input1=input1.left(input1.length()-1);
    ui->lineEdit->setText(input1);
    if(!input.isEmpty()){
    Calculation();
    }else {
        ui->lineEdit_2->setText("");
    }
}

void shuzijisuanqi::on_ACBtn_clicked()
{
    input="";
    input1="";
    ui->lineEdit->setText(input1);
    output="";
    ui->lineEdit_2->setText(output);
}

void shuzijisuanqi::on_zeroBtn_clicked()
{
    input=input+"0";
    input1=input1+"0";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_dianBtn_clicked()
{
    input=input+".";
    input1=input1+".";
    ui->lineEdit->setText(input1);
    Calculation();
}

void startCalculation(char inputS[],const char *S,int &len,bool &f,double *PFnum)
{
    QStack<char>outputS;
    int i=0,j=0,n=0;
    inputS[0]='\0';
    for(i=0;i<strlen(S);i++)
    {
        switch (S[i]) {
        case '+':
            if(outputS.isEmpty()){
                outputS.push(S[i]);
            }else if((outputS.top() == '/')||(outputS.top() == '*')){
                inputS[j++] = outputS.pop();
                inputS[j] = '\0';
                i--;
            }else {
                outputS.push(S[i]);
            }

            break;
        case '-':
            if((S[i-1] != '(')&&i!=0){
            if(outputS.isEmpty()){
                outputS.push(S[i]);
            }else if((outputS.top() == '/')||(outputS.top() == '*')){
                inputS[j++] = outputS.pop();
                inputS[j] = '\0';
                i--;
            }else {
                outputS.push(S[i]);
            }
            }else{
            while ((S[i]>='0')&&(S[i]<='9')
                    ||(S[i]=='.')
                    ||(('-'==S[i])&&(S[i-1]<'0'||S[i-1]>'9'))){

                inputS[j++] = S[i];

                if('-'==S[i])
                    inputS[j++]='#';
                i++;
            }
            i--;
            inputS[j++] = '!';
            inputS[j] = '\0';
            }

            break;
        case '*':
        case '/':
        case '%':
        case '(':
            outputS.push(S[i]);
            break;
        case ')':

            while ((!outputS.isEmpty())&&(outputS.top()!='(')) {
                inputS[j++] = outputS.pop();
                inputS[j] = '\0';
            }
            if(!outputS.isEmpty())outputS.pop();
            break;

        case '~':
        {
            char sqrtS[50];
            int k=0;
            i++;
            if(S[i] == '('){
                i++;
                while ((S[i]!=')')&&(S[i]!='\0')) {
                    sqrtS[k++] = S[i];
                    i++;
                }
                i++;
            }else {
                if(S[i]=='-'){
                    sqrtS[k++] = S[i];
                    i++;
                }
                while ((S[i]!='+')&&(S[i]!='-')&&(S[i]!='*')&&(S[i]!='/')&&S[i]!='\0') {
                    sqrtS[k++] = S[i];
                    i++;
                }
                i--;
            }
            sqrtS[k++]='\0';
            const char *tmpS = sqrtS;
            bool flag = true;
            char sqrOutS[50];
            char tmpstr[50];
            double temp[10];
            int sqrLen;
            double sqrResult=0;
            startCalculation(sqrOutS,tmpS,sqrLen,flag,temp);
            endCalculation(sqrOutS,sqrLen,sqrResult,flag,temp);
            if(sqrResult < 0){
                f = false;
                return ;
            }else {
                sqrResult = sqrt(sqrResult);
                sprintf(tmpstr,"%f",sqrResult);
                strcat(inputS,tmpstr);
                j=j+strlen(tmpstr);
            }
        }
            inputS[j++] = '!';
            inputS[j] = '\0';
            break;

        case '^':
        {
            if(i==0||!(((S[i-1]>=0)&&(S[i-1]<=9))||(S[i-1]!=')'))){
                f=false;
                return ;
            }else {
                inputS[j++] = '^';
                inputS[j] = '\0';
            }
            i++;
            char strtmp[10];
            int k=0;
            while ((S[i]!='+')&&(S[i]!='-')&&S[i]!='\0') {
                strtmp[k++]=S[i];
                i++;
            }
            PFnum[n++] = atof(strtmp);
            i--;
            break;
        }
        default:
            while ((S[i]>='0')&&(S[i]<='9')
                   ||(S[i]=='.')) {
                inputS[j++] = S[i];
                i++;
            }
            i--;
            inputS[j++] = '!';
            inputS[j] = '\0';
            break;

        }
    }
    for(;!outputS.isEmpty();)
    {
        if(outputS.top() == '('){
            outputS.pop();
        }else {
            inputS[j++] = outputS.pop();
            inputS[j] = '\0';
        }
    }
    len = j;
}

void endCalculation(char inputS[],int len,double& result,bool &f,double* PFnum)
{
    double x,y,z;
    int n=0;
    QStack<double>outputnum;
    for(int i=0;i<len;i++)
    {
        x=0;y=0;z=0;
        switch (inputS[i]) {
        case '+':
            if(!outputnum.isEmpty())
            x = outputnum.pop();
            if(!outputnum.isEmpty())
            y = outputnum.pop();
            z = x+y;
            outputnum.push(z);

            break;

        case '-':
            if(inputS[i+1] != '#'){
                if(!outputnum.isEmpty())
                x = outputnum.pop();
                if(!outputnum.isEmpty())
                y = outputnum.pop();
                z = y-x;
                outputnum.push(z);
            }else {
                double n1;
                int j1=1;
                i+=2;
                char *str = new char[10];
                *str = '-';
                for(;inputS[i] != '!';i++)
                {
                    str[j1++]=inputS[i];

                }
                str[j1]='\0';
                n1 = atof(str);
                outputnum.push(n1);
                delete str;
            }

            break;
        case '*':
            if(!outputnum.isEmpty())
            x = outputnum.pop();
            if(!outputnum.isEmpty())
            y = outputnum.pop();
            z = x*y;
            outputnum.push(z);

            break;
        case '/':
            if(!outputnum.isEmpty())
            x = outputnum.pop();
            if(!outputnum.isEmpty())
            y = outputnum.pop();
            if( x == 0 ){
                f = false;
                return ;
            }
            z = y/x;
            outputnum.push(z);
            break;

        case '%':
            if(!outputnum.isEmpty())
            x = outputnum.pop();
            if(!outputnum.isEmpty())
            y = outputnum.pop();
            if( x == 0 ){
                f = false;
                return ;
            }
            z = (int)y%(int)x;
            outputnum.push(z);

            break;

        case '^':
            if(!outputnum.isEmpty())
            x = outputnum.pop();
            z = pow(x ,PFnum[n++]);
            outputnum.push(z);

            break;

        default:
            double n;
            int j=0;
            char *str = new char[10];
            for(;inputS[i] != '!';i++)
            {
                str[j++]=inputS[i];

            }
            str[j]='\0';
            n = atof(str);
            outputnum.push(n);
            delete str;
            break;
        }
    }
    if(!outputnum.isEmpty())
    result = outputnum.pop();
}

void shuzijisuanqi::on_zuokuohaoBtn_clicked()
{
    input+="(";
    input1=input1+"(";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_youkuohaoBtn_clicked()
{
    input+=")";
    input1=input1+")";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::Calculation()
{
    output="";
    ui->lineEdit_2->setText(output);
    output = "=";
    std::string str = input.toStdString();
    int len;
    const char *S = str.c_str();
    char inputS[50];
    double result=0;
    double PFnum[10];
    bool f=true;
    foundError(f,S);
    startCalculation(inputS,S,len,f,PFnum);
    endCalculation(inputS,len,result,f,PFnum);
    output += QString::number(result);
    if(f){
    ui->lineEdit_2->setText(output);
    }else {
        ui->lineEdit_2->setText("Error!");
    }
}

void shuzijisuanqi::on_baifenhaoBtn_clicked()
{
    input+="%";
    input1=input1+"%";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_sqrtBtn_clicked()
{
    input+="~";
    input1=input1+"√";
    ui->lineEdit->setText(input1);
    Calculation();
}

void shuzijisuanqi::on_pingfangBtn_clicked()
{
    input+="^";
    input1=input1+"^";
    ui->lineEdit->setText(input1);
    Calculation();
}

void foundError(bool &f,const char *S)
{
    int i;
    int errorNum[50];
    for(i=0;i<strlen(S);i++){
        switch (S[i]) {
        case '+':
            errorNum[i] = 1;
            break;
        case '-':
            errorNum[i] = 1;
            break;
        case '*':
            errorNum[i] = 1;
            break;
        case '/':
            errorNum[i] = 1;
            break;
        default:
            errorNum[i] = 0;
            break;
        }
    }
    for(int j=0;j<i;j++)
    {
        if(errorNum[j]==1&&errorNum[j+1]==1){
            f = false;
            return ;
        }
    }
    f = true;
}

//For you debug ,thousand times over

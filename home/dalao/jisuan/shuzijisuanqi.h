#ifndef SHUZIJISUANQI_H
#define SHUZIJISUANQI_H


#include <QDialog>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QString>
#include<QStack>
#include <string>

void startCalculation(char inputS[],const char *S,int &len ,bool &f,double * PFnum);

void endCalculation(char inputS[],int len,double& result,bool &f,double * PFnum);

void foundError(bool &f,const char *S);

namespace Ui {
class shuzijisuanqi;
}

class shuzijisuanqi : public QDialog
{
    Q_OBJECT

public:
    void Calculation();
    explicit shuzijisuanqi(QWidget *parent = 0);
    ~shuzijisuanqi();

private slots:
    void on_oneBtn_clicked();

    void on_twoBtn_clicked();

    void on_threeBtn_clicked();

    void on_fourBtn_clicked();

    void on_fiveBtn_clicked();

    void on_sixBtn_clicked();

    void on_sevenBtn_clicked();

    void on_eightBtn_clicked();

    void on_nineBtn_clicked();

    void on_equBtn_clicked();

    void on_XBtn_clicked();

    void on_jianBtn_clicked();

    void on_addBtn_clicked();

    void on_DelBtn_clicked();

    void on_ACBtn_clicked();

    void on_zeroBtn_clicked();

    void on_dianBtn_clicked();

    void on_zuokuohaoBtn_clicked();

    void on_youkuohaoBtn_clicked();

    void on_baifenhaoBtn_clicked();

    void on_sqrtBtn_clicked();

    void on_pingfangBtn_clicked();

private:
    Ui::shuzijisuanqi *ui;
    QString input="";
    QString input1="";
    QString output="";
};

#endif // SHUZIJISUANQI_H

#ifndef MYJSQ_H
#define MYJSQ_H
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QString>


namespace Ui {
class Myjsq;
}

class Myjsq : public QDialog
{
    Q_OBJECT

protected:


public:
        void two_to_ten(const char * inputS ,char outputS[]);
        void eig_to_ten(const char * inputS ,char outputS[]);
        void six_to_ten(const char * inputS ,char outputS[]);
        void ten_to_two(const char * inputS ,char outputS[]);
        void ten_to_eig(const char * inputS ,char outputS[]);
        void ten_to_six(const char * inputS ,char outputS[]);
        void deal(const char * inputS ,char str1[],char str2[]);
        void char_to_int(const char * intputS,int &out);

    explicit Myjsq(QWidget *parent = 0);
    ~Myjsq();

private slots:
    void on_q1_clicked();

    void on_q2_clicked();

    void on_q3_clicked();

    void on_q4_clicked();

    void on_q5_clicked();

    void on_q6_clicked();

    void on_q7_clicked();

    void on_q8_clicked();

    void on_q9_clicked();

    void on_q0_clicked();

    void on_add_clicked();

    void on_minus_clicked();

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_AC_clicked();

    void on_Del_clicked();

    void on_A_clicked();

    void on_B_clicked();

    void on_C_clicked();

    void on_D_clicked();

    void on_E_clicked();

    void on_F_clicked();

    void on_two_clicked();

    void on_eight_clicked();

    void on_ten_clicked();

    void on_sixteen_clicked();

    void on_change_clicked();

private:
    int option=0;
    int temp=1;
    int judge=0;
    char symbol;
    Ui::Myjsq *ui;
    QString input="";

};

#endif // MYJSQ_H

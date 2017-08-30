#ifndef RC_H
#define RC_H

#include <QDialog>
#include <QString>
#include <string.h>
#include <string>
#include <QLabel>
class QLabel;
using namespace std;

namespace Ui {
class RC;
}

class RC : public QDialog
{
    Q_OBJECT

public:
    explicit RC(QWidget *parent = 0);
    ~RC();

private slots:
    void on_faBtn_clicked();

    void on_maBtn_clicked();

    void on_xiongBtn_clicked();

    void on_jieBtn_clicked();

    void on_hanBtn_clicked();

    void on_wifeBtn_clicked();

    void on_diBtn_clicked();

    void on_meiBtn_clicked();

    void on_sonBtn_clicked();

    void on_durBtn_clicked();

    void on_searchBtn_clicked();

    void on_bsBtn_clicked();

    void on_acBtn_clicked();

private:
    QLabel *statusLabel;
    Ui::RC *ui;
    QString curFile;
    QString input="我";
    QString out="";
    QLabel *label;
    int x=0,y=0,recore=0;
    string out2;
};

#endif // RC_H

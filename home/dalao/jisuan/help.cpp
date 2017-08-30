#include "help.h"
#include "ui_help.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);

    ui->textEdit->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setFont(QFont("Timers" , 16 ,  QFont::AnyStyle));

    QFile file("../jisuan/help.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text))
        QMessageBox::warning(this,"not found",tr("not found!").arg("dajh"));
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    setWindowTitle("帮助");
}

Help::~Help()
{
    delete ui;
}

void Help::on_pushButton_clicked()
{
    close();
}

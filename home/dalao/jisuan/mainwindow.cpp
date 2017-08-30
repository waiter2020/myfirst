#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <shuzijisuanqi.h>
#include <myjsq.h>
#include <rc.h>
#include <help.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("多功能计算器");
    ui->statusBar->showMessage(tr("WHB@ All Rights Reserved"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_shuzijisuanqiBtn_clicked()
{
    shuzijisuanqi dlg;
    dlg.setWindowTitle(tr("数学计算器"));
    dlg.exec();
}

void MainWindow::on_pushButton_clicked()
{
    Myjsq dlg;
    dlg.setWindowTitle(tr("进制转换器"));
    dlg.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    RC dlg;
    dlg.setWindowTitle(tr("辈分计算器"));
    dlg.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Help dlg;
    dlg.setWindowTitle(tr("帮助"));
    dlg.exec();

}

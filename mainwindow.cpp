#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->equacao;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizaMostrador(){
    ui->LedMostrador->setText(equacao.paraString());
}

void MainWindow::on_Btn0_clicked()
{
    equacao.addOperando(NUM, "0");
    atualizaMostrador();
}


void MainWindow::on_Btn1_clicked()
{
    equacao.addOperando(NUM, "1");
    atualizaMostrador();
}


void MainWindow::on_Btn2_clicked()
{
    equacao.addOperando(NUM, "2");
    atualizaMostrador();
}


void MainWindow::on_Btn3_clicked()
{
    equacao.addOperando(NUM, "3");
    atualizaMostrador();
}


void MainWindow::on_Btn4_clicked()
{
    equacao.addOperando(NUM, "4");
    atualizaMostrador();
}


void MainWindow::on_Btn5_clicked()
{
    equacao.addOperando(NUM, "5");
    atualizaMostrador();
}


void MainWindow::on_Btn6_clicked()
{
    equacao.addOperando(NUM, "6");
    atualizaMostrador();
}


void MainWindow::on_Btn7_clicked()
{
    equacao.addOperando(NUM, "7");
    atualizaMostrador();
}


void MainWindow::on_Btn8_clicked()
{
    equacao.addOperando(NUM, "8");
    atualizaMostrador();
}


void MainWindow::on_Btn9_clicked()
{
    equacao.addOperando(NUM, "9");
    atualizaMostrador();
}


void MainWindow::on_BtnVirgula_clicked()
{
    equacao.addOperando(NUM, ",");
    atualizaMostrador();
}


void MainWindow::on_BtnPi_clicked()
{
    equacao.addOperando(PI, QString::number(3.14159265358979323846));
    atualizaMostrador();
}


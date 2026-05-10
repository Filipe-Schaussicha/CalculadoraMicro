#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->equacao = new Equacao();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete equacao;
}

void MainWindow::atualizaMostrador(){
    ui->LedMostrador->setText(equacao->paraString());
}

void MainWindow::on_Btn0_clicked()
{
    equacao->addOperando(NUM, "0");
    atualizaMostrador();
}


void MainWindow::on_Btn1_clicked()
{
    equacao->addOperando(NUM, "1");
    atualizaMostrador();
}


void MainWindow::on_Btn2_clicked()
{
    equacao->addOperando(NUM, "2");
    atualizaMostrador();
}


void MainWindow::on_Btn3_clicked()
{
    equacao->addOperando(NUM, "3");
    atualizaMostrador();
}


void MainWindow::on_Btn4_clicked()
{
    equacao->addOperando(NUM, "4");
    atualizaMostrador();
}


void MainWindow::on_Btn5_clicked()
{
    equacao->addOperando(NUM, "5");
    atualizaMostrador();
}


void MainWindow::on_Btn6_clicked()
{
    equacao->addOperando(NUM, "6");
    atualizaMostrador();
}


void MainWindow::on_Btn7_clicked()
{
    equacao->addOperando(NUM, "7");
    atualizaMostrador();
}


void MainWindow::on_Btn8_clicked()
{
    equacao->addOperando(NUM, "8");
    atualizaMostrador();
}


void MainWindow::on_Btn9_clicked()
{
    equacao->addOperando(NUM, "9");
    atualizaMostrador();
}


void MainWindow::on_BtnVirgula_clicked()
{
    equacao->addOperando(NUM, ",");
    atualizaMostrador();
}


void MainWindow::on_BtnPi_clicked()
{
    equacao->addOperando(PI, QString::number(3.14159265358979323846));
    atualizaMostrador();
}


void MainWindow::on_BtnBackspace_clicked()
{
    equacao->backspace();
    atualizaMostrador();
}


void MainWindow::on_BtnClear_clicked()
{
    delete equacao;
    equacao = new Equacao();
    atualizaMostrador();
}


void MainWindow::on_BtnMais_clicked()
{
    equacao->addOperador(SOMA);
    atualizaMostrador();
}


void MainWindow::on_BtnMenos_clicked()
{
    equacao->addOperador(SUB);
    atualizaMostrador();
}


void MainWindow::on_BtnMult_clicked()
{
    equacao->addOperador(MUL);
    atualizaMostrador();
}


void MainWindow::on_BtnDiv_clicked()
{
    equacao->addOperador(DIV);
    atualizaMostrador();
}


void MainWindow::on_BtnLn_clicked()
{
    equacao->addOperador(LN);
    atualizaMostrador();
}


void MainWindow::on_BtnFat_clicked()
{
    equacao->addOperador(FAT);
    atualizaMostrador();
}


void MainWindow::on_BtnSen_clicked()
{
    equacao->addOperador(SEN);
    atualizaMostrador();
}


void MainWindow::on_BtnCos_clicked()
{
    equacao->addOperador(COS);
    atualizaMostrador();
}


void MainWindow::on_BtnTg_clicked()
{
    equacao->addOperador(TG);
    atualizaMostrador();
}


void MainWindow::on_BtnRaizQuadrada_clicked()
{
    equacao->addOperador(RAIZ);
    atualizaMostrador();
}


void MainWindow::on_BtnElevadoA2_clicked()
{
    equacao->addOperador(ELEVADO);
    equacao->addOperando(NUM, "2");
    atualizaMostrador();
}


void MainWindow::on_BtnEuler_clicked()
{
    equacao->addOperando(EULER, "2.71828182845904523536");
    equacao->addOperador(ELEVADO);
    atualizaMostrador();
}


void MainWindow::on_BtnAbreParenteses_clicked()
{
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();
}


void MainWindow::on_BntFechaParenteses_clicked()
{
    equacao->addOperador(FECHA_PARENTESES);
    atualizaMostrador();
}


void MainWindow::on_BtnFrac_clicked()
{
    // Pode ter comportamento estranho
    equacao->addOperando(NUM, "1");
    equacao->addOperador(DIV);
    atualizaMostrador();
}


void MainWindow::on_BtnElevado_clicked()
{
    equacao->addOperador(ELEVADO);
    atualizaMostrador();
}


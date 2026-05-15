#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include "polonesa.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->equacao = new Equacao(ui->CbxInversao->isChecked());
    //A
    this->pctExpressao = new std::vector<pacoteDaExpressao>();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete equacao;
    //A
    delete pctExpressao;
}

// Atualiza o mostrador da calculador
void MainWindow::atualizaMostrador(){
    ui->LedMostrador->setText(equacao->paraString());
}

void MainWindow::meuAtualizaMostrador(QString txt){
    ui->LedMostrador->setText(txt);
}


/*
* Função de click para cada botão do mostrador
* - Eu sei que tem melhores formas de fazer isso :(
*/
void MainWindow::on_Btn0_clicked()
{
    equacao->addOperando(NUM, "0");
    atualizaMostrador();

    pacoteDaExpressao novo("0",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn1_clicked()
{
    equacao->addOperando(NUM, "1");
    atualizaMostrador();

    pacoteDaExpressao novo("1",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn2_clicked()
{
    equacao->addOperando(NUM, "2");
    atualizaMostrador();

    pacoteDaExpressao novo("2",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn3_clicked()
{
    equacao->addOperando(NUM, "3");
    atualizaMostrador();

    pacoteDaExpressao novo("3",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn4_clicked()
{
    equacao->addOperando(NUM, "4");
    atualizaMostrador();

    pacoteDaExpressao novo("4",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn5_clicked()
{
    equacao->addOperando(NUM, "5");
    atualizaMostrador();

    pacoteDaExpressao novo("5",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn6_clicked()
{
    equacao->addOperando(NUM, "6");
    atualizaMostrador();

    pacoteDaExpressao novo("6",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn7_clicked()
{
    equacao->addOperando(NUM, "7");
    atualizaMostrador();

    pacoteDaExpressao novo("7",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn8_clicked()
{
    equacao->addOperando(NUM, "8");
    atualizaMostrador();

    pacoteDaExpressao novo("8",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btn9_clicked()
{
    equacao->addOperando(NUM, "9");
    atualizaMostrador();

    pacoteDaExpressao novo("9",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnVirgula_clicked()
{
    equacao->addOperando(NUM, ",");
    atualizaMostrador();

    pacoteDaExpressao novo(",",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnPi_clicked()
{
    equacao->addOperando(PI, QString::number(3.14159265358979323846));
    atualizaMostrador();

    pacoteDaExpressao novo("π",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnBackspace_clicked()
{
    equacao->backspace();
    atualizaMostrador();

    if(!pctExpressao->empty()){
        pctExpressao->pop_back();
    }
}


void MainWindow::on_BtnClear_clicked()
{
    delete equacao;
    equacao = new Equacao(ui->CbxInversao->isChecked());
    atualizaMostrador();

    delete pctExpressao;
    pctExpressao = new std::vector<pacoteDaExpressao>();
}


void MainWindow::on_BtnMais_clicked()
{
    equacao->addOperador(SOMA);
    atualizaMostrador();

    pacoteDaExpressao novo("+",1,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnMenos_clicked()
{
    equacao->addOperador(SUB);
    atualizaMostrador();

    pacoteDaExpressao novo("-",1,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnMult_clicked()
{
    equacao->addOperador(MUL);
    atualizaMostrador();

    pacoteDaExpressao novo("*",2,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnDiv_clicked()
{
    equacao->addOperador(DIV);
    atualizaMostrador();

    pacoteDaExpressao novo("/",2,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnLn_clicked()
{
    equacao->addLog(EULER, "");
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo("ln",4,2.71828182845904523536);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnFat_clicked()
{
    equacao->addOperador(FAT);
    atualizaMostrador();

    pacoteDaExpressao novo("!",4,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnSen_clicked()
{
    equacao->addOperador(SEN);
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo("sen",4,0);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnCos_clicked()
{
    equacao->addOperador(COS);
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo("cos",4,0);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnTg_clicked()
{
    equacao->addOperador(TG);
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo("tan",4,0);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnRaizQuadrada_clicked()
{
    equacao->addRaiz(NUM, "2");
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo("√",4,2);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnElevadoA2_clicked()
{
    equacao->addOperador(ELEVADO);
    equacao->addOperando(NUM, "2");
    atualizaMostrador();

    pacoteDaExpressao novo("^2",3,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnEuler_clicked()
{
    equacao->addOperando(EULER, "2.71828182845904523536");
    equacao->addOperador(ELEVADO);
    atualizaMostrador();

    pacoteDaExpressao novo("e",0,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnAbreParenteses_clicked()
{
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo("(",5,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BntFechaParenteses_clicked()
{
    equacao->addOperador(FECHA_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo(")",5,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnFrac_clicked()
{
    equacao->addOperador(UM_SOBRE_X);
    atualizaMostrador();

    pacoteDaExpressao novo("⁻¹",4,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_BtnElevado_clicked()
{
    equacao->addOperador(ELEVADO);
    atualizaMostrador();

    pacoteDaExpressao novo("^",3,0);
    pctExpressao->push_back(novo);
}


void MainWindow::on_Btnlog_clicked()
{
    DialogLerValor lerValor;


    lerValor.mudarLabel("Digite o valor da base do Log:");

    if(lerValor.exec() == QDialog::Accepted){
        QString base = lerValor.getTexto();

        if(base == "e"){
            equacao->addLog(EULER, "");
            pacoteDaExpressao novo("log",4,2.71828182845904523536);
            pctExpressao->push_back(novo);
            pacoteDaExpressao novo2("(",5,0);
            pctExpressao->push_back(novo2);
        }else if(base == "π"){
            equacao->addLog(PI, "");
            pacoteDaExpressao novo("log",4,3.14159265358979323846);
            pctExpressao->push_back(novo);
            pacoteDaExpressao novo2("(",5,0);
            pctExpressao->push_back(novo2);
        }else{
            equacao->addLog(NUM, base);
            pacoteDaExpressao novo("log",4,base.toFloat());
            pctExpressao->push_back(novo);
            pacoteDaExpressao novo2("(",5,0);
            pctExpressao->push_back(novo2);
        }

        equacao->addOperador(ABRE_PARENTESES);
        atualizaMostrador();
    }
}


void MainWindow::on_BtnRaizY_clicked()
{
    DialogLerValor lerValor;

    lerValor.mudarLabel("Digite o valor do indice da raiz:");

    if(lerValor.exec() == QDialog::Accepted){
        QString base = lerValor.getTexto();

        if(base == "e"){
            equacao->addRaiz(EULER, "");
            pacoteDaExpressao novo("√",4,2.71828182845904523536);
            pctExpressao->push_back(novo);
            pacoteDaExpressao novo2("(",5,0);
            pctExpressao->push_back(novo2);
        }else if(base == "π"){
            equacao->addRaiz(PI, "");
            pacoteDaExpressao novo("√",4,3.14159265358979323846);
            pctExpressao->push_back(novo);
            pacoteDaExpressao novo2("(",5,0);
            pctExpressao->push_back(novo2);
        }else{
            equacao->addRaiz(NUM, base);
            pacoteDaExpressao novo("√",4,base.toFloat());
            pctExpressao->push_back(novo);
            pacoteDaExpressao novo2("(",5,0);
            pctExpressao->push_back(novo2);
        }

        equacao->addOperador(ABRE_PARENTESES);
        atualizaMostrador();
    }
}


void MainWindow::on_BtnSinal_clicked()
{
    equacao->trocaSinal();
    atualizaMostrador();
}

// Quando a ckeck box inversão é mudada
void MainWindow::on_CbxInversao_checkStateChanged(const Qt::CheckState &arg1)
{
    equacao->atualizarInversao(ui->CbxInversao->isChecked());
    atualizaMostrador();
}


void MainWindow::on_BtnIgual_clicked()
{
    pacoteDaExpressao pct;

    polonesa portalPolones;

    std::vector<pacoteDaExpressao> temporario = portalPolones.polonese(*pctExpressao);


    if(temporario[0].getProcedencia()>=0) {
        meuAtualizaMostrador(pct.transformaEmTexto(temporario));
    } else {
        meuAtualizaMostrador("Erro de sintaxe!");
    }
}


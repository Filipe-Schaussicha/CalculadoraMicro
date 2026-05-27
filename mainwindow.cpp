#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include "polonesa.h"
#include "calculos.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->equacao = new Equacao();
    //A
    this->pctExpressao = new std::vector<pacoteDaExpressao>();

    setFixedSize(width(), height());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete equacao;
    //A
    delete pctExpressao;
    grau = true;
}

// Atualiza o mostrador da calculador
void MainWindow::atualizaMostrador(){
    ui->LedMostrador->setText(equacao->paraString());
}

void MainWindow::meuAtualizaMostrador(QString txt){
    ui->LedMostrador->setText("");
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

    pacoteDaExpressao novo("3.14159265358979323846",0,0);
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
    equacao = new Equacao();
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
    equacao->addOperador(LN);
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
    if(!ui->CbxInversao->isChecked()){
        equacao->addOperador(SEN);

        pacoteDaExpressao novo("sen",4,0);
        pctExpressao->push_back(novo);
    }else{
        equacao->addOperador(ARCSEN);

        pacoteDaExpressao novo("arcsen",4,0);
        pctExpressao->push_back(novo);
    }

    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnCos_clicked()
{
    if(!ui->CbxInversao->isChecked()){
        equacao->addOperador(COS);

        pacoteDaExpressao novo("cos",4,0);
        pctExpressao->push_back(novo);
    }else{
        equacao->addOperador(ARCCOS);

        pacoteDaExpressao novo("arccos",4,0);
        pctExpressao->push_back(novo);
    }

    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnTg_clicked()
{
    if(!ui->CbxInversao->isChecked()){
        equacao->addOperador(TG);

        pacoteDaExpressao novo("tg",4,0);
        pctExpressao->push_back(novo);
    }else{
        equacao->addOperador(ARCTG);

        pacoteDaExpressao novo("arctg",4,0);
        pctExpressao->push_back(novo);
    }

    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnRaizQuadrada_clicked()
{
    equacao->addRaiz(NUM, "2");
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo("√",3,2);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnElevadoA2_clicked()
{
    equacao->addOperador(ELEVADO);
    equacao->addOperando(NUM, "2");
    atualizaMostrador();

    pacoteDaExpressao novo("^",3,0);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("2",0,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnEuler_clicked()
{
    equacao->addOperando(EULER, "2.71828182845904523536");
    equacao->addOperador(ELEVADO);
    atualizaMostrador();

    pacoteDaExpressao novo("e",0,0);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("^",3,0);
    pctExpressao->push_back(novo2);
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
    equacao->addOperador(LOG);
    equacao->addOperador(ABRE_PARENTESES);
    atualizaMostrador();

    pacoteDaExpressao novo("log",4,10);
    pctExpressao->push_back(novo);
    pacoteDaExpressao novo2("(",5,0);
    pctExpressao->push_back(novo2);
}


void MainWindow::on_BtnRaizY_clicked()
{
    DialogLerValor lerValor;

    lerValor.mudarLabel("Digite o valor do indice da raiz:");

    if(lerValor.exec() == QDialog::Accepted){
        QString base = lerValor.getTexto();

        if(base == "e"){
            equacao->addRaiz(EULER, "");
            pacoteDaExpressao novo("√",3,2.71828182845904523536);
            pctExpressao->push_back(novo);
            pacoteDaExpressao novo2("(",5,0);
            pctExpressao->push_back(novo2);
        }else if(base == "π"){
            equacao->addRaiz(PI, "");
            pacoteDaExpressao novo("√",3,3.14159265358979323846);
            pctExpressao->push_back(novo);
            pacoteDaExpressao novo2("(",5,0);
            pctExpressao->push_back(novo2);
        }else{
            equacao->addRaiz(NUM, base);
            pacoteDaExpressao novo("√",3,base.toFloat());
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

    if(!pctExpressao->empty()) {
        if(pctExpressao->back().getProcedencia() == 0) {

            pacoteDaExpressao temp = pctExpressao->back();
            pctExpressao->pop_back();

            double tempDouble = temp.getNome().toDouble();
            tempDouble*=(-1);
            temp.setNome(QString::number(tempDouble));

            pctExpressao->push_back(temp);
        }
    }
}

// Quando a ckeck box inversão é mudada
void MainWindow::on_CbxInversao_checkStateChanged(const Qt::CheckState &arg1)
{
    if(ui->CbxInversao->isChecked()){
        ui->BtnSen->setText("arcsen");
        ui->BtnCos->setText("arccos");
        ui->BtnTg->setText("arctg");
    }else{
        ui->BtnSen->setText("sen");
        ui->BtnCos->setText("cos");
        ui->BtnTg->setText("tg");
    }
}

bool MainWindow::getGrau() {
    return grau;
}

void MainWindow::setGrau(bool gra){
    this->grau=gra;
}

void MainWindow::on_BtnIgual_clicked()
{
    pacoteDaExpressao pct;

    polonesa portalPolones;

    if(!pctExpressao->empty() && (pctExpressao->front().getNome()!="^"
                    && pctExpressao->front().getNome()!="-"
                    && pctExpressao->front().getNome()!="+"
                    && pctExpressao->front().getNome()!="*"
                    && pctExpressao->front().getNome()!="/"
                    && pctExpressao->front().getNome()!="!"
                    && pctExpressao->front().getNome()!="⁻¹")) {
        std::vector<pacoteDaExpressao> temporario = portalPolones.polonese(*pctExpressao);

        if(!temporario.empty()){
        if(temporario[0].getProcedencia()>=0) {


            if(ui->radioButton->isChecked()) {

                setGrau(true);
            }
            if(ui->radioButton_2->isChecked()){
                setGrau(false);
            }

            calculos calculo(getGrau());

            QString fim = calculo.calculaPolonesa(temporario);

            if(fim=="F") {
                meuAtualizaMostrador("Cálculo matematicamente inconsistente!");
            } else {

                double fimD=fim.toDouble();
                fimD=std::abs(fimD);

                if(fimD<0.00001) {
                    fim="0";
                }
                meuAtualizaMostrador(fim);
            }


        } else {
            meuAtualizaMostrador("Erro de sintaxe!");
        }
        }

        delete equacao;
        equacao = new Equacao();
        delete pctExpressao;
        pctExpressao = new std::vector<pacoteDaExpressao>();
    }
}


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

void MainWindow::limpa() {
    delete equacao;
    equacao = new Equacao();
    delete pctExpressao;
    pctExpressao = new std::vector<pacoteDaExpressao>();
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


    if(!pctExpressao->empty() && pctExpressao->back().getProcedencia() == 0) {
        pacoteDaExpressao temp = pctExpressao->back();
        pctExpressao->pop_back();


        temp.setNome(temp.getNome() + ".");

        pctExpressao->push_back(temp);
    } else {

        pacoteDaExpressao novo("0.", 0, 0);
        pctExpressao->push_back(novo);
    }
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

    pacoteDaExpressao novo("2.71828182845904523536",0,0);
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

    if(pctExpressao->empty()) return;

    int i = pctExpressao->size() - 1;
    int blocosDeNumero = 0;

    while(i >= 0 && pctExpressao->at(i).getProcedencia() == 0) {
        blocosDeNumero++;
        i--;
    }

    if(blocosDeNumero > 0) {

        QString numeroCompleto = "";


        int indiceInicio = pctExpressao->size() - blocosDeNumero;

        for(int j = indiceInicio; j < pctExpressao->size(); j++) {
            QString parte = pctExpressao->at(j).getNome();
            if(parte == ",") parte = ".";
            numeroCompleto += parte;
        }

        for(int k = 0; k < blocosDeNumero; k++) {
            pctExpressao->pop_back();
        }

        double valor = numeroCompleto.toDouble();
        valor *= (-1);

        pacoteDaExpressao numeroCorrigido(QString::number(valor, 'g', 10), 0, 0);
        pctExpressao->push_back(numeroCorrigido);
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

    if(pctExpressao->empty() || (equacao->listaElementos.size() == 1 && (equacao->listaElementos.back()->tipo == NUM || equacao->listaElementos.back()->tipo == EULER || equacao->listaElementos.back()->tipo == PI))) return;


    QString ultimo = pctExpressao->back().getNome();
    if(ultimo == "+" || ultimo == "-" || ultimo == "*" || ultimo == "/" || ultimo=="^") {
        meuAtualizaMostrador("Erro: Expressão incompleta!");
        delete equacao;
        equacao = new Equacao();
        delete pctExpressao;
        pctExpressao = new std::vector<pacoteDaExpressao>();
        return;
    }

    //1 -> + -
    //2 -> * /
    //3 -> ^ sqrt()
    //4 -> sen cos tg arctg arccos arcsen ! ⁻¹
    //5 -> )  (

    for(int i=0;i< pctExpressao->size()-1;i++) {
        int atual = (*pctExpressao)[i].getProcedencia();
        int prox = (*pctExpressao)[i+1].getProcedencia();
        QString atualStr = (*pctExpressao)[i].getNome();
        QString proxStr = (*pctExpressao)[i+1].getNome();

        if(atual>0 && prox>0) {

            if(atual==1 && prox==1) {
                meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                limpa();
                return;
            }

            if(atual==2 && prox==2) {
                meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                limpa();
                return;
            }

            if((atual==1 && prox==2) || (atual==2 && prox==1) ) {
                meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                limpa();
                return;
            }

            if(atual==1 && prox==3) {
                if(proxStr=="^") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
            }

            if(atual==3 && prox==1) {
                if(atualStr=="^") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
                if(atualStr=="√") {
                    meuAtualizaMostrador("Faltou o parentese da raiz!");
                    limpa();
                    return;
                }
            }

            if(atual==1 && prox==4) {
                if(proxStr=="!" || proxStr=="⁻¹") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
            }

            if(atual==4 && prox==1) {
                if(atualStr=="sen") {
                    meuAtualizaMostrador("Falta o parentese do seno!");
                    limpa();
                    return;
                }
                if(atualStr=="cos") {
                    meuAtualizaMostrador("Faltou o parentese do cosseno!");
                    limpa();
                    return;
                }
                if(atualStr=="arccos") {
                    meuAtualizaMostrador("Faltou o parentese do arccosseno!");
                    limpa();
                    return;
                }
                if(atualStr=="arcsen") {
                    meuAtualizaMostrador("Faltou o parentese do arcseno!");
                    limpa();
                    return;
                }
                if(atualStr=="tg") {
                    meuAtualizaMostrador("Faltou o parentese da tangente!");
                    limpa();
                    return;
                }
                if(atualStr=="arctg") {
                    meuAtualizaMostrador("Faltou o parentese da arctangente!");
                    limpa();
                    return;
                }
                if(atualStr=="log") {
                    meuAtualizaMostrador("Faltou o parentese do log!");
                    limpa();
                    return;
                }
                if(atualStr=="ln") {
                    meuAtualizaMostrador("Faltou o parentese do ln!");
                    limpa();
                    return;
                }
            }


            if(atual==2 && prox==3) {
                if(proxStr=="^") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
            }

            if(atual==3 && prox==2) {
                if(proxStr=="^") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
                if(proxStr=="√") {
                    meuAtualizaMostrador("Faltou o parentese da raiz!");
                    limpa();
                    return;
                }
            }

            if(atual==3 && prox==3) {
                if(atualStr=="√") {
                    meuAtualizaMostrador("Faltou o parentese da raiz!");
                    limpa();
                    return;
                }
            }


            if(atual==3 && prox==4) {
                if(atualStr=="√" && (proxStr=="!" || proxStr=="⁻¹")) {
                    meuAtualizaMostrador("Erro de formatação!");
                    limpa();
                    return;
                }

                if(atualStr=="^" && (proxStr=="!" || proxStr=="⁻¹")) {
                    meuAtualizaMostrador("Erro de formatação!");
                    limpa();
                    return;
                }

            }

            if(atual==4 && prox==3) {
                if(atualStr=="!" && proxStr=="√") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
                if(atualStr=="sen") {
                    meuAtualizaMostrador("Falta o parentese do seno!");
                    limpa();
                    return;
                }
                if(atualStr=="cos") {
                    meuAtualizaMostrador("Faltou o parentese do cosseno!");
                    limpa();
                    return;
                }
                if(atualStr=="arccos") {
                    meuAtualizaMostrador("Faltou o parentese do arccosseno!");
                    limpa();
                    return;
                }
                if(atualStr=="arcsen") {
                    meuAtualizaMostrador("Faltou o parentese do arcseno!");
                    limpa();
                    return;
                }
                if(atualStr=="tg") {
                    meuAtualizaMostrador("Faltou o parentese da tangente!");
                    limpa();
                    return;
                }
                if(atualStr=="arctg") {
                    meuAtualizaMostrador("Faltou o parentese da arctangente!");
                    limpa();
                    return;
                }
                if(atualStr=="log") {
                    meuAtualizaMostrador("Faltou o parentese do log!");
                    limpa();
                    return;
                }
                if(atualStr=="ln") {
                    meuAtualizaMostrador("Faltou o parentese do ln!");
                    limpa();
                    return;
                }
            }

            if(atual==4 && prox==4) {
                meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                limpa();
                return;
            }


            if(atual==2 && prox==4) {
                if(proxStr=="!" || proxStr=="⁻¹") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
            }

            if(atual==4 && prox==2) {
                if(atualStr=="sen") {
                    meuAtualizaMostrador("Falta o parentese do seno!");
                    limpa();
                    return;
                }
                if(atualStr=="cos") {
                    meuAtualizaMostrador("Faltou o parentese do cosseno!");
                    limpa();
                    return;
                }
                if(atualStr=="arccos") {
                    meuAtualizaMostrador("Faltou o parentese do arccosseno!");
                    limpa();
                    return;
                }
                if(atualStr=="arcsen") {
                    meuAtualizaMostrador("Faltou o parentese do arcseno!");
                    limpa();
                    return;
                }
                if(atualStr=="tg") {
                    meuAtualizaMostrador("Faltou o parentese da tangente!");
                    limpa();
                    return;
                }
                if(atualStr=="arctg") {
                    meuAtualizaMostrador("Faltou o parentese da arctangente!");
                    limpa();
                    return;
                }
                if(atualStr=="log") {
                    meuAtualizaMostrador("Faltou o parentese do log!");
                    limpa();
                    return;
                }
                if(atualStr=="ln") {
                    meuAtualizaMostrador("Faltou o parentese do ln!");
                    limpa();
                    return;
                }
            }

            if(atual==5 && prox==5) {
                if(atualStr=="(" && proxStr==")") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
            }

            if(atual==5 && prox==4) {
                if((proxStr=="⁻¹" || proxStr=="!") && atualStr=="(") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }

                if(atualStr==")") {
                    if(proxStr=="sen") {
                        meuAtualizaMostrador("Falta o parentese do seno!");
                        limpa();
                        return;
                    }
                    if(proxStr=="cos") {
                        meuAtualizaMostrador("Faltou o parentese do cosseno!");
                        limpa();
                        return;
                    }
                    if(proxStr=="arccos") {
                        meuAtualizaMostrador("Faltou o parentese do arccosseno!");
                        limpa();
                        return;
                    }
                    if(proxStr=="arcsen") {
                        meuAtualizaMostrador("Faltou o parentese do arcseno!");
                        limpa();
                        return;
                    }
                    if(proxStr=="tg") {
                        meuAtualizaMostrador("Faltou o parentese da tangente!");
                        limpa();
                        return;
                    }
                    if(proxStr=="arctg") {
                        meuAtualizaMostrador("Faltou o parentese da arctangente!");
                        limpa();
                        return;
                    }
                    if(proxStr=="log") {
                        meuAtualizaMostrador("Faltou o parentese do log!");
                        limpa();
                        return;
                    }
                    if(proxStr=="ln") {
                        meuAtualizaMostrador("Faltou o parentese do ln!");
                        limpa();
                        return;
                    }
                }

            }
            ///////////////////////////////////
            if(atual==4 && prox==5) {

                if(proxStr=="(" && (atualStr=="!" || atualStr=="⁻¹")) {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }

                if(proxStr==")") {
                    if(atualStr=="sen") {
                        meuAtualizaMostrador("Falta o parentese do seno!");
                        limpa();
                        return;
                    }
                    if(atualStr=="cos") {
                        meuAtualizaMostrador("Faltou o parentese do cosseno!");
                        limpa();
                        return;
                    }
                    if(atualStr=="arccos") {
                        meuAtualizaMostrador("Faltou o parentese do arccosseno!");
                        limpa();
                        return;
                    }
                    if(atualStr=="arcsen") {
                        meuAtualizaMostrador("Faltou o parentese do arcseno!");
                        limpa();
                        return;
                    }
                    if(atualStr=="tg") {
                        meuAtualizaMostrador("Faltou o parentese da tangente!");
                        limpa();
                        return;
                    }
                    if(atualStr=="arctg") {
                        meuAtualizaMostrador("Faltou o parentese da arctangente!");
                        limpa();
                        return;
                    }
                    if(atualStr=="log") {
                        meuAtualizaMostrador("Faltou o parentese do log!");
                        limpa();
                        return;
                    }
                    if(atualStr=="ln") {
                        meuAtualizaMostrador("Faltou o parentese do ln!");
                        limpa();
                        return;
                    }
                }
            }

            if(atual==5 && prox==3){
                if(atualStr=="("&& proxStr=="^"){

                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;

                }
            }

            if(atual==3 && prox==5) {
                if((atualStr=="√" || atualStr=="^") && proxStr==")"){

                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;

                }
            }

            if((atual==5 && prox==2)) {
                if(atualStr=="(") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
            }

            if(atual==2 && prox==5) {
                if(proxStr==")") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
            }

            if(atual==5 && prox==1) {
                if(atualStr=="(") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }
            }

            if(atual==1 && prox==5) {
                if(proxStr==")") {
                    meuAtualizaMostrador("Posição dos operandos na expressão é inválida!");
                    limpa();
                    return;
                }

            }
        }
    }

    try{

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
    } catch(const std::exception& e) {
        meuAtualizaMostrador("Erro na construção da expressão!");
    }
}
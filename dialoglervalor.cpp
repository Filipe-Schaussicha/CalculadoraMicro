#include "dialoglervalor.h"
#include "ui_dialoglervalor.h"

DialogLerValor::DialogLerValor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLerValor)
{
    ui->setupUi(this);
}

DialogLerValor::~DialogLerValor()
{
    delete ui;
}

void DialogLerValor::mudarLabel(QString msg){
    ui->label->setText(msg);
}

void DialogLerValor::on_BtnPi_clicked()
{
    ui->lineEdit->setText("π");
    accept();
}


void DialogLerValor::on_BtnEuler_clicked()
{
    ui->lineEdit->setText("e");
    accept();
}

QString DialogLerValor::getTexto(){
    return ui->lineEdit->text();
}

void DialogLerValor::on_BtnCancelar_clicked()
{
    reject();
}


void DialogLerValor::on_BtnOK_clicked()
{
    QString texto = ui->lineEdit->text();
    int i = 0;

    // Ignora textos vazios
    if(texto == ""){
        ui->LedSaida->setPlaceholderText("A entrada não pode estar vazia");
        return;
    }

    // ignora o sinal negativo do início
    if(texto[i] == '-') i++;

    // Verifica virgula no início
    if(texto[i] == ',' || texto[i] == '.'){
        ui->lineEdit->setText("");
        ui->LedSaida->setPlaceholderText("Entrada inválida");
        return;
    }

    // Ignora virgulas ou ponto do final
    if(texto.last(1) == "," || texto.last(1) == "."){
        texto.removeLast();
    }

    bool virgula_encontrada = false;
    QString char_aceitos = "0123456789";
    for(; i < texto.size(); i++){
        // Converte pontos em virgula
        if(texto[i] == '.'){
            texto[i] = ',';
        }

        // Verifica por multiplas virgulas
        if(texto[i] == ","){
            if(virgula_encontrada){
                ui->lineEdit->setText("");
                ui->LedSaida->setPlaceholderText("Apenas um ponto ou virgula é permitida");
                return;
            }else{
                virgula_encontrada = true;
            }
        // Retorna erro para caracteres não aceitos
        }else if(!char_aceitos.contains(texto[i])){
            ui->lineEdit->setText("");
            ui->LedSaida->setPlaceholderText("Entrada inválida!");
            return;
        }
    }

    ui->lineEdit->setText(texto);

    accept();
}


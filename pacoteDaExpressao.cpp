#include "pacoteDaExpressao.h"
#include<QString>

pacoteDaExpressao::pacoteDaExpressao(QString nome, int procedencia, float baseOuExpoente) {
    this->nome=nome;
    this->procedencia=procedencia;
    this->baseOuExpoente=baseOuExpoente;
}

pacoteDaExpressao::pacoteDaExpressao() {
    this->nome;
    this->procedencia;
}

float pacoteDaExpressao::getBaseOuExpoente() {
    return this->baseOuExpoente;
}

void pacoteDaExpressao::setBaseOuExpoente(float baseOuExpoente) {
    this->baseOuExpoente=baseOuExpoente;
}

QString pacoteDaExpressao::getNome(){
    return this->nome;
}

int pacoteDaExpressao::getProcedencia() {
    return this->procedencia;
}

void pacoteDaExpressao::setProcedencia(int procedencia){
    this->procedencia=procedencia;
}

void pacoteDaExpressao::setNome(QString nome) {
    this->nome=nome;
}

QString pacoteDaExpressao::transformaEmTexto(const std::vector<pacoteDaExpressao>& lista) {

    QString saida="";
    //QString buffer="";

    for(int i=0; i<lista.size(); i++) {

        if(lista[i].nome!="log" && lista[i].nome!="√") {
            saida+=lista[i].nome;
        } else {

            //buffer=QString::number(lista[i].baseOuExpoente, 'f', 5);
            //saida+=buffer;
            saida+=lista[i].nome;
        }
    }

    return saida;

}
//int procedencia;
//QString nome;
//float baseOuExpoente;
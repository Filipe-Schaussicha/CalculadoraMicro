#include "equacao.h"
#include <QDebug>

Equacao::Equacao() {
    this->listaElementos;
}

void Equacao::addOperando(tipoElemento tipo, QString val){
    // Caso haja a tentativa de adicionar uma virgula sozinha
    if(listaElementos.size() > 0 && listaElementos.back()->tipo != NUM && val == ","){
        val = "0,";
    }

    // Caso um novo digito seja adicionado, ele é adiciona ao fim caso ele seja um número comum
    if(listaElementos.size() > 0 && listaElementos.back()->tipo == NUM && tipo == NUM){
        listaElementos.back()->addFim(val);
    }else{
        // Senão cria outro nó
        this->listaElementos.push_back(std::make_unique<Operandos>(tipo, val));
    }
}

void Equacao::addOperador(tipoElemento tipo){
    this->listaElementos.push_back(std::make_unique<Operador>(tipo));
}

QString Equacao::paraString(){
    QString saida;

    for(auto& e: listaElementos){
        saida.append(e->paraString());
        saida.append(" ");
    }

    return saida;
}
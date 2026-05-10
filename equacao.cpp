#include "equacao.h"
#include <QDebug>

Equacao::Equacao() {
    this->listaElementos;
}

void Equacao::addOperando(tipoElemento tipo, QString val){
    // Caso haja a tentativa de adicionar uma virgula sozinha
    if((listaElementos.size() > 0 && listaElementos.back()->tipo != NUM || listaElementos.size() == 0) && val == ","){
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

void Equacao::addLog(tipoElemento tipoBase, QString val){
    this->listaElementos.push_back(std::make_unique<Logaritimo>(tipoBase, val));
}

void Equacao::addRaiz(tipoElemento tipoElevado, QString val){
    this->listaElementos.push_back(std::make_unique<Raiz>(tipoElevado, val));
}

// Remove o último digito ou o último elemento
void Equacao::backspace(){
    if(listaElementos.size() <= 0) return;

    if(!listaElementos.back()->removeFim()){
        listaElementos.pop_back();
    }
}

QString Equacao::paraString(){
    QString saida;

    for(auto& e: listaElementos){
        saida.append(e->paraString());
        saida.append(" ");
    }

    return saida;
}
#include "elementooperacao.h"

Operador::Operador(tipoElemento tipo){
    this->tipo = tipo;
}

Operandos::Operandos(tipoElemento tipo, QString valor){
    this->tipo = tipo;
    this->valor = valor;
}

// Ignorar
void Operador::addFim(QString qs){
    return;
}

//Adicionar digito ao fim do número
void Operandos::addFim(QString qs){
    if(qs == ","){
        if(!this->valor.contains(",")){
            this->valor.append(",");
        }
    }else{
        this->valor.append(qs);
    }
}

QString Operador::paraString(){
    switch (this->tipo) {
    case SOMA: return "+";
    case SUB: return "-";
    case DIV: return "/";
    case MUL: return "*";
    case LOG: return "log";
    case LN: return "ln";
    case FAT: return "!";
    case SEN: return "sen";
    case COS: return "cos";
    case TG: return "Tg";
    case ELEVADO: return "^";
    case RAIZ: return "√";

    default:
        return "NULO";
    }
}

QString Operandos::paraString(){
    QString saida;

    switch(this->tipo){
    case PI: saida = "π"; break;
    case EULER: saida = "e"; break;
    default: saida = this->valor; break;
    }

    return saida;
}

/*
typedef enum{
    NUM,
    PI,
    EULER,
    SOMA,
    SUB,
    DIV,
    MUL,
    LOG,
    FAT,
    SEN,
    COS,
    TG,
    ELEVADO,
    RAIZ
}tipoElemento;
*/
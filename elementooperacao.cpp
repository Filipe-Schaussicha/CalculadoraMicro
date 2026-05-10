#include "elementooperacao.h"

Operador::Operador(tipoElemento tipo){
    this->tipo = tipo;
}

Operandos::Operandos(tipoElemento tipo, QString valor){
    this->tipo = tipo;
    this->valor = valor;

    if(tipo == EULER) this->valor = "2.71828182845904523536";
    else if(tipo == PI) this->valor = "3.14159265358979323846";
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

bool Operador::removeFim(){
    return false;
}

bool Operandos::removeFim(){
    if(this->valor.size() <= 1 || this->tipo == PI || this->tipo == EULER){
        return false;
    }

    this->valor.removeLast();
    return true;
}

QString Operador::paraString(){
    switch (this->tipo) {
    case SOMA: return "+";
    case SUB: return "-";
    case DIV: return "/";
    case MUL: return "*";
    case FAT: return "!";
    case SEN: return "sen";
    case COS: return "cos";
    case TG: return "tg";
    case ELEVADO: return "^";
    //case RAIZ: return "√";
    case ABRE_PARENTESES: return "(";
    case FECHA_PARENTESES: return ")";

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

Logaritimo::Logaritimo(tipoElemento tipoBase, QString valBase) : Operador(LOG){
    this->tipoBase = tipoBase;
    this->valorBase = valBase;
}

QString Logaritimo::paraString(){
    if(this->tipoBase == EULER){
        return "ln";
    }

    QString saida = "log";
    if(this->tipoBase == PI){
        saida.append(Utilidades::numParaSubscrito("π"));
    }else{
        saida.append(Utilidades::numParaSubscrito(this->valorBase));
    }

    return saida;
}

Raiz::Raiz(tipoElemento tipoBase, QString valBase) : Operador(LOG){
    this->tipoBase = tipoBase;
    this->valorBase = valBase;
}

QString Raiz::paraString(){
    if(this->valorBase == "2"){
        return "√";
    }

    QString saida = "";
    if(this->tipoBase == PI){
        saida.append(Utilidades::numParaSobrescrito("π"));
    }else if(this->tipoBase == EULER){
        saida.append(Utilidades::numParaSobrescrito("e"));
    }else{
        saida.append(Utilidades::numParaSobrescrito(this->valorBase));
    }

    saida.append("√");

    return saida;
}

void Operandos::trocarSinal(){
    if(this->valor.first(1) == "-"){
        this->valor.removeFirst();
    }else{
        this->valor.push_front("-");
    }
}

void Operador::trocarSinal(){}
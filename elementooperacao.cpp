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
 // Ingorar
bool Operador::removeFim(){
    return false;
}

// Remove digito do final do número
// Retorna falso caso não seja um número ou se o número só tiver um digito
bool Operandos::removeFim(){
    if(this->valor.size() <= 1 || this->tipo == PI || this->tipo == EULER){
        return false;
    }

    this->valor.removeLast();
    return true;
}

// Retorna equivalente do operador em string
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
    case ABRE_PARENTESES: return "(";
    case FECHA_PARENTESES: return ")";
    case UM_SOBRE_X: return "⁻¹";

    default:
        return "NULO";
    }
}

// Retorna equivalente do operando em string
QString Operandos::paraString(){
    QString saida;

    switch(this->tipo){
    case PI: saida = "π"; break;
    case EULER: saida = "e"; break;
    default: saida = this->valor; break;
    }

    return saida;
}

// Construtor de uma log
Logaritimo::Logaritimo(tipoElemento tipoBase, QString valBase) : Operador(LOG){
    this->tipoBase = tipoBase;
    this->valorBase = valBase;
}

// Retorna equivalente do log em string
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

// Construtor de uma raiz
Raiz::Raiz(tipoElemento tipoBase, QString valBase) : Operador(LOG){
    this->tipoBase = tipoBase;
    this->valorBase = valBase;
}

// Retorna equivalente da raiz em string
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

// Troca o sinal de um operando
void Operandos::trocarSinal(){
    if(this->valor.first(1) == "-"){
        this->valor.removeFirst();
    }else{
        this->valor.push_front("-");
    }
}

// Ignorar
void Operador::trocarSinal(){}
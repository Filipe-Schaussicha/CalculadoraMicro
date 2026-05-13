#include "equacao.h"
#include <QDebug>

/*
* Essa classe é responsável pro gerenciar os diversos elemetos (operandos e operadores) do mostrador
*/

// Inicializador
Equacao::Equacao(bool inversao){
    this->listaElementos;

    this->estaInvertido = inversao;
}

// Adiciona um novo operando (número)
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

// Adiciona um novo operador
void Equacao::addOperador(tipoElemento tipo){
    this->listaElementos.push_back(std::make_unique<Operador>(tipo));
}

// Adiciona um novo operador (feito espeficiamente para log e ln)
void Equacao::addLog(tipoElemento tipoBase, QString val){
    this->listaElementos.push_back(std::make_unique<Logaritimo>(tipoBase, val));
}

// Adiciona um novo operador (feito espeficiamente para raiz)
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

// Monta uma string da equação para o display
QString Equacao::paraString(){
    QString saida;

    for(auto& e: listaElementos){
        QString elemento = e->paraString();

        // Muda a funções trigonometricas quando intertidas
        if(this->estaInvertido){
            if(elemento == "sen")
                elemento = "arcsen";
            else if (elemento == "cos")
                elemento = "arccos";
            else if (elemento == "tg")
                elemento = "arctg";
        }

        saida.append(elemento);
        saida.append(" ");
    }

    return saida;
}

// Troca o sinal do último número
void Equacao::trocaSinal(){
    if(listaElementos.size() != 0 && listaElementos.back()->tipo == NUM){
        listaElementos.back()->trocarSinal();
    }
}

void Equacao::atualizarInversao(bool novo){
    this->estaInvertido = novo;
}
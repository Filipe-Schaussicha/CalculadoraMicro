#ifndef EQUACAO_H
#define EQUACAO_H

#include <vector>
#include <QString>
#include "elementooperacao.h"

/*
* Essa classe é responsável pro gerenciar os diversos elemetos (operandos e operadores) do mostrador
*/

class Equacao
{
public:
    std::vector<std::unique_ptr<ElementoOperacao>> listaElementos;

    // Metodos
    Equacao();

    void addOperando(tipoElemento tipo, QString val);
    void addOperador(tipoElemento tipo);
    void addRaiz(tipoElemento tipoElevado, QString val);
    void backspace();
    void trocaSinal();
    QString paraString();
};

#endif // EQUACAO_H

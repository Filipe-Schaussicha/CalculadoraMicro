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
private:
    std::vector<std::unique_ptr<ElementoOperacao>> listaElementos;

public:
    bool estaInvertido;

    // Metodos
    Equacao(bool inversao);

    void addOperando(tipoElemento tipo, QString val);
    void addOperador(tipoElemento tipo);
    void addLog(tipoElemento tipoBase, QString val);
    void addRaiz(tipoElemento tipoElevado, QString val);
    void backspace();
    void trocaSinal();
    void atualizarInversao(bool novo);
    QString paraString();
};

#endif // EQUACAO_H

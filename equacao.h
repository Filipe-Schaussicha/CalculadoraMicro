#ifndef EQUACAO_H
#define EQUACAO_H

#include <vector>
#include <QString>
#include "elementooperacao.h"

class Equacao
{
private:
    std::vector<std::unique_ptr<ElementoOperacao>> listaElementos;

public:
    Equacao();

    void addOperando(tipoElemento tipo, QString val);
    void addOperador(tipoElemento tipo);
    QString paraString();
};

#endif // EQUACAO_H

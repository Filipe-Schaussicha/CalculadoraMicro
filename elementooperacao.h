#ifndef ELEMENTOOPERACAO_H
#define ELEMENTOOPERACAO_H

#include <QString>

// Enum com os os possíveis tipos de elementos
typedef enum{
    NUM,
    PI,
    EULER,
    SOMA,
    SUB,
    DIV,
    MUL,
    LOG,
    LN,
    FAT,
    SEN,
    COS,
    TG,
    ELEVADO,
    RAIZ
}tipoElemento;

// Classe que representa um elemento de uma operação
class ElementoOperacao
{
public:
    tipoElemento tipo;

    virtual QString paraString() = 0;
    virtual void addFim(QString qs) = 0;
    virtual ~ElementoOperacao() = default;
};

class Operador: public ElementoOperacao{
public:
    Operador(tipoElemento tipo);

    void addFim(QString qs);
    QString paraString() override;
};

class Operandos: public ElementoOperacao{
public:
    QString valor;

    Operandos(tipoElemento tipo, QString valor);

    void addFim(QString qs);
    QString paraString() override;
};

#endif // ELEMENTOOPERACAO_H

#ifndef ELEMENTOOPERACAO_H
#define ELEMENTOOPERACAO_H

#include <QString>
#include "utilidades.h"

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
    FAT,
    SEN,
    COS,
    TG,
    ELEVADO,
    RAIZ,
    ABRE_PARENTESES,
    FECHA_PARENTESES,
    UM_SOBRE_X
}tipoElemento;

// Classe que representa um elemento de uma operação
class ElementoOperacao
{
public:
    tipoElemento tipo;

    virtual QString paraString() = 0;
    virtual void addFim(QString qs) = 0;
    virtual bool removeFim() = 0;
    virtual ~ElementoOperacao() = default;
    virtual void trocarSinal() = 0;
};

class Operador: public ElementoOperacao{
public:
    Operador(tipoElemento tipo);

    void addFim(QString qs) override;
    bool removeFim() override;
    QString paraString() override;
    void trocarSinal() override;
};

class Operandos: public ElementoOperacao{
public:
    QString valor;

    Operandos(tipoElemento tipo, QString valor);

    void addFim(QString qs) override;
    bool removeFim() override;
    QString paraString() override;
    void trocarSinal() override;
};

class Logaritimo: public Operador{
public:
    tipoElemento tipoBase;
    QString valorBase;

    Logaritimo(tipoElemento tipoBase, QString valBase);
    QString paraString() override;
};

class Raiz: public Operador{
public:
    tipoElemento tipoBase;
    QString valorBase;

    Raiz(tipoElemento tipoBase, QString valBase);
    QString paraString() override;
};

#endif // ELEMENTOOPERACAO_H

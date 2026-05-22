#ifndef ELEMENTOOPERACAO_H
#define ELEMENTOOPERACAO_H

#include <QString>
#include "utilidades.h"

#define PI_VAL 3.14159265
#define EULER_VAL 2.71828

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
    ARCSEN,
    ARCCOS,
    ARCTG,
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

class Raiz: public Operador{
public:
    tipoElemento tipoBase;
    QString valorBase;

    Raiz(tipoElemento tipoBase, QString valBase);
    QString paraString() override;
};

#endif // ELEMENTOOPERACAO_H

#ifndef POLONESA_H
#define POLONESA_H

#include<QString>
#include<vector>
#include "pacoteDaExpressao.h"

class polonesa{

public:

    std::vector<pacoteDaExpressao> polonese(std::vector<pacoteDaExpressao>& pseudoString);

    int ateOndeEOperador(std::vector<pacoteDaExpressao>& l, int pos);

    void concatenaInteiros(std::vector<pacoteDaExpressao>& lista, int pos, int max);
};

#endif // POLONESA_H

#ifndef CALCULOS_H
#define CALCULOS_H
#include <cmath>
#include "pacoteDaExpressao.h"

class calculos
{
private:
    bool grau;
public:
    calculos(bool grau);
    bool getGrau();
    double subtracao(double a, double b);
    double raiz(double n, double indice);
    double multiplicacao(double a, double b);
    double logaritmo(double a, double base);
    double cosseno(double a);
    double arctg(double num);
    double arccos(double num);
    double soma(double a, double b);
    double divisao(double a, double b);
    double seno(double x);
    double tangente(double x);
    double potenciacao(double x, double y);
    double fatorial(int num);
    double arcsen(double x);
    double graus_para_radianos(double graus);
    double x_sobre_um(double x);
    QString calculaPolonesa(std::vector<pacoteDaExpressao> exp);



};

#endif // CALCULOS_H

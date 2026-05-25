#include <cmath>
#include <iostream>
#include <stdio.h>

using namespace std;

double soma(double a, double b){
    double result;

    asm volatile(
        "finit ;"
        "fldl %1;"
        "fldl %2;"
        "faddp;"
        "fstpl %0;"

        : "=m"(result)
        : "m"(a), "m"(b)
    );

    return result;
}

double divisao(double a, double b){
    if(b == 0)
        return NAN;

    double result;

    asm volatile(
        "finit ;"
        "fldl %1;"
        "fldl %2;"
        "fdivrp;"
        "fstpl %0;"

        : "=m"(result)
        : "m"(a), "m"(b)
    );

    return result;
}

double seno(double x){
    double result;

    asm volatile(
        "finit ;"
        "fldl %1;"
        "fsin;"
        "fstpl %0;"

        : "=m"(result)
        : "m"(x)
    );

    return result;
}

double tangente(double x){
    // Validação de domínio
    if (fabs(cos(x)) < 0.0000000001)
        return NAN;

    double result;

    asm volatile(
        "finit ;"
        "fldl %1;"
        "fptan;"
        "fstpl %0;"
        "fstpl %0;"

        : "=m"(result)
        : "m"(x)
    );

    return result;
}

double potenciacao(double x, double y){
    double result;

    asm volatile(
        "finit;"
        "fldl %2;"
        "fld1;"
        "fldl %1;"
        "fyl2x;"
        "fmulp;"
        "fld %%st(0);"
        "frndint;"
        "fsubr %%st, %%st(1);"
        "fxch;"
        "f2xm1;"
        "fld1;"
        "faddp;"
        "fscale;"
        "fstpl %0;"

        : "=m"(result)
        : "m"(x), "m"(y)
    );

    return result;
}

double fatorial(int num){
    // Verificação de domínio
    if(num < 0)
        return NAN;

    double result;
    double n = (double)num;

    asm volatile(
        "finit;"
        // Carrega valores iniciais
        "fld1;"
        "fldl %1;"
        // Início do loop
        "loop:"
        // Verifica se o valor de n chegou a zero
        "ftst;"
        "fnstsw %%ax;"
        "sahf;"
        // Caso sim, pula pro fim
        "jbe fim;"
        // Multplica n por f(n-1)
        "fxch;"
        "fld %%st(1);"
        "fmulp;"
        // Subtrai 1 de n
        "fxch;"
        "fld1;"
        "fsubrp;"
        // Vai para o topo do loop
        "jmp loop;"
        "fim:"
        // Salva o resultado
        "fstp %%st(0);"
        "fstpl %0;"
        : "=m"(result)
        : "m"(n)
    );

    return result;
}

double arcsen(double x){
    if(x < -1.0 || x > 1.0)
        return NAN;

    double result;

    // Calculando arcsen(x) = arctan(x / sqtr{1 - x²})
    asm volatile(
        "finit;"
        "fldl %1;"
        "fld %%st(0);"
        "fmulp;"
        "fld1;"
        "fsub %%st(1), %%st(0);"
        "fsqrt;"
        "fldl %1;"
        "fxch;"
        "fpatan;"
        "fstpl %0;"
        : "=m"(result)
        : "m"(x)
    );

    return result;
}

double graus_para_radianos(double graus){
    double radianos;
    const int centoOintenta = 180;

    // Converte graus para radianos
    // a(radianos) = a(graus) * pi / 180
    asm volatile(
        "finit;"
        "fldpi;"
        "fild %2;"
        "fdivrp;"
        "fldl %1;"
        "fmulp;"
        "fstpl %0;"
        : "=m"(radianos)
        : "m"(graus), "m"(centoOintenta)
    );

    return radianos;
}

double x_sobre_um(double x){
    double result;

    // Calcula 1/x
    asm volatile(
        "finit;"
        "fldl %1;"
        "fld1;"
        "fdivp;"
        "fstpl %0;"
        : "=m"(result)
        : "m"(x)
    );

    return result;
}

int main(){
    cout << "Soma: " << soma(1.1, 2.2) << endl;

    cout << "Divisão: " << divisao(10, 2) << endl;

    printf("Seno: %.2f\n", seno(3.14159265 / 2));

    printf("Tangente: %.2f\n", tangente(M_PI));

    cout << "Pontenciacão: " << potenciacao(3, 2) << endl;

    cout << "Fatorial: " << fatorial(5) << endl;

    cout << "Arco seno: " << arcsen(1.0) << endl;

    cout << "Radianos: " << graus_para_radianos(180) << endl;

    cout << "1 sobre X: " << x_sobre_um(0.5) << endl;

    return 0;
}

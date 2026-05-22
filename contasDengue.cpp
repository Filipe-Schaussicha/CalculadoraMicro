#include <iostream>
#include <stdio.h>

using namespace std;

/**
 * A fazer:
 *
 * - [x] Soma
 * - [x] Div
 * - [x] Sen
 * - [ ] Arcsen
 * - [ ] Tg
 * - [\] Exp
 * - [ ] Fatorial
 */

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
    double result;

    asm volatile(
        "finit ;"
        "fldl %1;"
        "fldl %2;"
        "fdivp;"
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

// Está com algum erro
double potenciacao(double x, double y){
    double result;

    asm volatile(
        "finit;"
        "fldl %2;"
        "fld1;"
        "fldl %1;"
        "fyl2x;"
        "fmulp;"

        "fld %%st;"
        "frndint;"
        "fsub %%st, %%st(1);"
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

int main(){
    cout << "Soma: " << soma(1.1, 2.2) << endl;

    cout << "Divisão: " << divisao(10, 2) << endl;

    printf("Seno: %.2f\n", seno(3.14159265 / 2));

    cout << "Pontenciacão: " << potenciacao(3, 2) << endl;

    return 0;
}

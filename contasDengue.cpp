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
 * - [x] Tg
 * - [\] Exp
 * - [x] Fatorial
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

double tangente(double x){
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

int fatorial(int num){

    double result;
    double n = num;

    asm volatile(
        "finit;"
        "fld1;"
        "fldl %1;"
        "loop:"
        "ftst;"
        "fnstsw %%ax;"
        "sahf;"
        "jbe fim;"
        "fxch;"
        "fld %%st(1);"
        "fmulp;"
        "fxch;"
        "fld1;"
        "fsubrp;"
        "jmp loop;"
        "fim:"
        "fstp %%st(0);"
        "fstpl %0;"
        : "=m"(result)
        : "m"(n)
    );

    return result;
}

int main(){
    cout << "Soma: " << soma(1.1, 2.2) << endl;

    cout << "Divisão: " << divisao(10, 2) << endl;

    printf("Seno: %.2f\n", seno(3.14159265 / 2));

    printf("Tangente: %.2f\n", tangente(0));

    cout << "Pontenciacão: " << potenciacao(3, 2) << endl;

    cout << "Fatorial: " << fatorial(10) << endl;

    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

double logaritmo(double a, double base) {

    if(a<=0 || base<=0 || base==1) {
        return NAN;
    }

    double resultado=0;

    asm volatile(

        "finit ;"
        "fld1;"
        "fldl %1;"
        "fyl2x ;"
        "fld1 ;"
        "fdiv %%st, %%st(1);"
        "fstp %%st;"
        "fldl %2;"
        "fyl2x;"
        "fstpl %0;"

        : "=m"(resultado)
        :"m"(base), "m"(a)
    );

    return resultado;
}

int main() {

    double base=0;
    double a=0;

    cout << "Digite o número e a base do logarítmo: ";
    cin >> a;
    cin >> base;

    double resultado=logaritmo(a, base);

    if(isnan(resultado)) {
        cout << "Valores inadequdos!";
    } else {
        cout << "O resultado é: " << resultado << "\n";
    }


    return 0;
}
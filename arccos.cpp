#include <iostream>
#include <cmath>

using namespace std;

double arccos(double num) {

    double resultado=0;


    asm volatile(

        "finit ;"
        "fldl %1;"
        "fldl %1;"
        "fmul %%st(1), %%st(0) ;"
        "fld1 ;"
        "fsub %%st(1), %%st(0) ;"
        "fsqrt ;"
        "fldl %1;"
        //"fdiv %%st(1), %%st(0);"
        //"fld1;"
        "fxch %%st(1);"
        "fpatan ;"

        "fldpi ;"
        "fld1 ;"
        "fld1 ;"
        "fadd %%st(1), %%st(0);"
        "fxch %%st(2);"
        "fdiv %%st(2), %%st(0);"
        "fsub %%st(3), %%st(0);"
        "fstpl %0;"



        : "=m"(resultado)
        : "m"(num)
    );


    return resultado;
}

int main() {


    double numero=0;

    cout << "Digite o valor para função arccos: " ;
    cin >> numero;

    double resultado = arccos(numero);

    cout << "Resultado: " << resultado << "\n";
    cout << acos(numero);

    return 0;
}
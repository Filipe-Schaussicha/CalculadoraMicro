#include <iostream>
#include <cmath>

using namespace std;

double arctg(double num) {

    double resultado=0;

    asm volatile(

        "finit;"
        "fldl %1;"
        "fld1 ;"
        "fpatan;"
        "fstpl %0;"

        : "=m"(resultado)
        : "m"(num)
    );

    return resultado;
}

int main() {

    double valor=0;

    cout << "Digite o numeropara arctg: ";
    cin >> valor;

    double resultado = arctg(valor);

    cout << resultado <<"\n";
    //cout << atan(valor);


    return 0;
}
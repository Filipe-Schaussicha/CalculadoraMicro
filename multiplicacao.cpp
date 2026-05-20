#include <iostream>

using namespace std;

double multiplicacao(double a, double b) {

    double resultado=0;

    asm volatile(

        "finit ;"
        "fldl %1;"
        "fmull %2;"
        "fstpl %0;"

        : "=m"(resultado)
        : "m"(a), "m"(b)
    ) ;

    return resultado;
}

int main() {

    double n1=0;
    double n2=0;

    cout << "Digite dois numeros: ";
    cin >> n1;
    cin >> n2;

    double resultado=multiplicacao(n1, n2);

    cout << "Resultado: " << resultado << "\n";

    return 0;
}
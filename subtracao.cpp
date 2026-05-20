#include <iostream>

using namespace std;

double subtracao(double a, double b) {

    double resultado=0;

    asm volatile( 

        "finit ;"
        "fldl %1;"
        "fsubl %2;"
        "fstpl %0;"

        :"=m"(resultado)
        : "m"(a), "m"(b)

    ) ;

    return resultado;
}

int main() {

    double n1=0;
    double n2=0;

    cout << "Digite um número: ";
    cin >> n1;
    cout << "Digite outro número: ";
    cin >> n2;

    double resultado=subtracao(n1, n2);

    cout << "Resultado: " << resultado << "\n";

    return 0;
}
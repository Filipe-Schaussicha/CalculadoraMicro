#include <iostream>

using namespace std;

double cosseno(double a) {

    double resultado=0;

    asm volatile(

        "finit ;"
        "fldl %1;"
        "fcos;"    
        "fstpl %0"

        : "=m"(resultado)
        : "m"(a)
    );

    return resultado;
}

int main() {

    double teste=0;
    double res=0;

    cin >> teste;

    res=cosseno(teste);

    cout << "\n" << res;

    return 0;
}
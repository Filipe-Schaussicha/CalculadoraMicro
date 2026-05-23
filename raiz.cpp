#include <iostream>
#include <cmath>

using namespace std;

double raiz(double n, double indice) {

    if(n==0) return 0;
    if(indice==0) return NAN;

    double resultado=0;

    asm volatile(

        "finit ;"
        "fldl %1;"
        "fld1 ;"
        "fdiv %%st(1), %%st(0);"
        "fld1 ;"
        "fldl %2;"
        "fyl2x ;"
        "fmul %%st(1), %%st(0);"
        "fld %%st(0);"
        "frndint ;"
        "fsubr %%st(0), %%st(1) ;"
                              
                                   
        "fxch %%st(1);"       
        "f2xm1 ;"             
        "fld1 ;"              
        "faddp %%st(0), %%st(1) ;"
        
        "fscale ;"                
        "fstpl %0;"               
        "fstp %%st(0);"
        

        : "=m"(resultado)
        : "m"(indice), "m"(n)
    );

    return resultado;

}

int main() {

    double numero=0;
    double indice=0;
    
    cout << "Digite o número e o índice da raiz: ";
    cin >> numero;
    cin >> indice;

    double resultado = raiz(numero, indice);

    if(!std::isnan(resultado)) {
        cout << "Resultado: " << resultado;
    } else {
        cout << "Operadores inválidos!";
    }
    return 0;
}
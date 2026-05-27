#include "calculos.h"
#include <stack>
#include <cmath>

calculos::calculos(bool grau) {
    this->grau=grau;
}

bool calculos::getGrau() {
    return grau;
}

double calculos::subtracao(double a, double b) {

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
double calculos::raiz(double n, double indice) {

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

double calculos::multiplicacao(double a, double b) {

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

double calculos::logaritmo(double a, double base) {

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

double calculos::cosseno(double a) {

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

double calculos::arctg(double num) {

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

double calculos::arccos(double num) {
    if(num < -1.0 || num > 1.0)
        return NAN;

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

double calculos::soma(double a, double b){
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

double calculos::divisao(double a, double b){
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

double calculos::seno(double x){
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

double calculos::tangente(double x){
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

double calculos::potenciacao(double x, double y){
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

double calculos::fatorial(int num){
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

double calculos::arcsen(double x){
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

double calculos::radianos_para_graus(double radianos) {
    double graus;
    const int centoOitenta=180;

    asm volatile(
        "finit;"
        "fldl %1;"
        "fildl %2;"
        "fmulp;"
        "fldpi;"
        "fdivrp;"
        "fstpl %0;"
        : "=m"(graus)
        : "m"(radianos), "m"(centoOitenta)
        );

    return graus;
}

double calculos::graus_para_radianos(double graus){
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

double calculos::x_sobre_um(double x){
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

QString calculos::calculaPolonesa(std::vector<pacoteDaExpressao> exp){

    double resultado=0;
    QString resultadoS;
    std::stack<QString> pilha;
    double a=0;
    double b=0;
    QString aS;
    QString bS;

    for(int i=0;i<exp.size();i++) {

        if(exp[i].getProcedencia()==0) {
            if(exp[i].getNome()!="e") {
                pilha.push(exp[i].getNome());
            } else {
                pilha.push("2.71828182845904523536");
            }



        } else {

            if(exp[i].getNome()=="+") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                bS=pilha.top();
                pilha.pop();
                b=bS.toDouble();

                resultado=soma(a, b);
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="-") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                bS=pilha.top();
                pilha.pop();
                b=bS.toDouble();

                resultado=subtracao(b, a);
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="*") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                bS=pilha.top();
                pilha.pop();
                b=bS.toDouble();

                resultado=multiplicacao(a, b);
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);

            }

            if(exp[i].getNome()=="/") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                bS=pilha.top();
                pilha.pop();
                b=bS.toDouble();

                resultado=divisao(b, a);
                if(std::isnan(resultado)){
                    return "F";
                }
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);

            }

            if(exp[i].getNome()=="^") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                bS=pilha.top();
                pilha.pop();
                b=bS.toDouble();

                resultado=potenciacao(b, a);
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="√") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                resultado=raiz(a, exp[i].getBaseOuExpoente());
                if(std::isnan(resultado)){
                    return "F";
                }
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);

            }


            if(exp[i].getNome()=="ln") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();


                resultado=logaritmo(a, exp[i].getBaseOuExpoente());
                if(std::isnan(resultado)){
                    return "F";
                }
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);

            }

            if(exp[i].getNome()=="log") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                resultado=logaritmo(a, exp[i].getBaseOuExpoente());
                if(std::isnan(resultado)){
                    return "F";
                }
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="sen") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                if(!getGrau()) {

                    a=graus_para_radianos(a);
                }

                resultado=seno(a);
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="arcsen") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();
                if(a>1 || a<-1) {
                    return "F";
                }

                resultado=arcsen(a);

                if(std::isnan(resultado)){

                    return "F";
                }

                if(getGrau()) {
                    resultado = radianos_para_graus(resultado);
                }

                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="arccos") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();
                if(a>1 || a<-1) {
                    return "F";
                }
                resultado=arccos(a);

                if(getGrau()) {
                    resultado = radianos_para_graus(resultado);
                }

                if(std::isnan(resultado)){
                    return "F";
                }
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="tg") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                if(!getGrau()) {

                    a=graus_para_radianos(a);
                }

                resultado=tangente(a);

                if(std::isnan(resultado)){
                    return "F";
                }
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome() == "arctg") {
                aS = pilha.top();
                pilha.pop();
                a = aS.toDouble();
                resultado = arctg(a);

                if(std::isnan(resultado)){

                    return "F";
                }

                if(getGrau()) {
                    resultado = radianos_para_graus(resultado);
                }

                resultadoS = QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="cos") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                if(!getGrau()) {

                    a=graus_para_radianos(a);
                }

                resultado=cosseno(a);
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="!") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();
                if(a<0) {
                    return "F";
                }

                resultado=fatorial(a);
                if(std::isnan(resultado)){
                    return "F";
                }
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

            if(exp[i].getNome()=="⁻¹") {

                aS=pilha.top();
                pilha.pop();
                a=aS.toDouble();

                resultado=x_sobre_um(a);
                if(std::isnan(resultado)){
                    return "F";
                }
                resultadoS= QString::number(resultado);
                pilha.push(resultadoS);
            }

        }

    }

    return resultadoS;
}

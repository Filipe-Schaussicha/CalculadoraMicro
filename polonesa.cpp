#include "polonesa.h"
#include<stack>
#include "pacoteDaExpressao.h"

int polonesa::ateOndeEOperador( std::vector<pacoteDaExpressao>& l, int pos) {
    pos+=1;
    int cont=0;

    while(pos<l.size() && l[pos].getProcedencia()==0) {
        pos+=1;
        cont+=1;
    }

    return cont;
}

void polonesa::concatenaInteiros(std::vector<pacoteDaExpressao>& lista, int pos, int max) {

    QString buffer=lista[pos].getNome();

    for(int i=pos+1; i<=max;i++) {

        if(lista[i].getNome()==',') {
            lista[i].setNome(".");
        }

        buffer+=lista[i].getNome();
    }

    lista[pos].setNome(buffer);
}

std::vector<pacoteDaExpressao> polonesa::polonese( std::vector<pacoteDaExpressao>& pseudoString) {

    std::stack<pacoteDaExpressao> pOperadores;
    std::vector<pacoteDaExpressao> saida;
    int parenteses=0;

    for(int i=0 ;i<pseudoString.size() ;i++) {

        //é operando
        if(pseudoString[i].getProcedencia()==0) {

            int pulo=this->ateOndeEOperador(pseudoString, i);
            this->concatenaInteiros(pseudoString,i, i+pulo);
            saida.push_back(pseudoString[i]);
            i+=pulo;

        //é operador
        } else if(pseudoString[i].getProcedencia()>0 && pseudoString[i].getProcedencia()<5) {

            while(pOperadores.size()>0 && pOperadores.top().getNome()!="(" &&
                   pOperadores.top().getProcedencia() >= pseudoString[i].getProcedencia() ) {

                saida.push_back(pOperadores.top());
                pOperadores.pop();
            }

            pOperadores.push(pseudoString[i]);

        //é parentese
        } else if(pseudoString[i].getNome()=="(") {

            parenteses++;
            pOperadores.push(pseudoString[i]);

        } else {

            parenteses--;

            while(!pOperadores.empty() && pOperadores.top().getNome()!="(") {

                saida.push_back(pOperadores.top());
                pOperadores.pop();
            }

            if(!pOperadores.empty()) {
                if(pOperadores.top().getNome()=="(") {
                    pOperadores.pop();
                }
            }

            if(pOperadores.empty()) {

                std::vector<pacoteDaExpressao> p;
                pacoteDaExpressao erro;
                erro.setProcedencia(-1);
                p.push_back(erro);
                return p;
            }
        }
    } //fatal <_>

    while(pOperadores.size()>0) {

        saida.push_back(pOperadores.top());
        pOperadores.pop();
    }

    if(parenteses==0) {

        return saida;
    } else {

        std::vector<pacoteDaExpressao> p;
        pacoteDaExpressao erro;
        erro.setProcedencia(-1);
        p.push_back(erro);
        return p;
    }


}

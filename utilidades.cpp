#include "utilidades.h"

// Serve para converter uma string de números em uma versão sobrescrita
QString Utilidades::numParaSobrescrito(QString val){
    if(val == "π") return "ᵖⁱ";

    for(auto& c: val){
        QString original = "0123456789e,-";
        QString substituto = "⁰¹²³⁴⁵⁶⁷⁸⁹ᵉ˒⁻";

        for(int i = 0; i < original.size(); i++){
            if(c == original[i]){
                c = substituto[i];
            }
        }
    }

    return val;
}

// Serve para converter uma string de números em uma versão subscrita
QString Utilidades::numParaSubscrito(QString val){
    if(val == "π") return "ₚᵢ";

    for(auto& c: val){
        QString original = "0123456789e,-";
        QString substituto = "₀₁₂₃₄₅₆₇₈₉ₑ‚₋";

        for(int i = 0; i < original.size(); i++){
            if(c == original[i]){
                c = substituto[i];
            }
        }
    }

    return val;
}
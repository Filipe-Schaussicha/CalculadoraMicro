#ifndef PACOTEDAEXPRESSAO_H
#define PACOTEDAEXPRESSAO_H

#include<QString>
#include<vector>

class pacoteDaExpressao {
private:

    int procedencia;
    QString nome;
    float baseOuExpoente;


public:
    pacoteDaExpressao();
    pacoteDaExpressao(QString nome, int procedencia, float baseOuExpoente);
    float getBaseOuExpoente();
    void setBaseOuExpoente(float baseOuExpoente);
    int getProcedencia();
    QString getNome();
    void setProcedencia(int procedencia);
    void setNome(QString nome);

    QString transformaEmTexto(const std::vector<pacoteDaExpressao>& lista);
};

#endif // PACOTEDAEXPRESSAO_H

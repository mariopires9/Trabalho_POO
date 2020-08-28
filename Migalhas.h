#ifndef MIGALHAS_H
#define MIGALHAS_H

#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Migalhas {
    int energiaInicialMigalhas=0;
    int energiaMigalhas;
    int numeroMigalhas;
    int maxMigalhas;
    int linhas, colunas;
    int idMigalha;
    static int idMigalhaAnterior;
    int numeroPosicoesVazias;
public:
    //CONSTRUTOR
    Migalhas(int linha, int coluna);
    
    //GETS
    int getId() const;
    int getAcrescentarMigalhas()const;
    int getEnergiaInicialMigalhas() const;
    int getEnergiaMigalha() const;
    int getLinhas() const;
    int getColunas() const;
    
    //SETS
    void setEnergiaInicialMigalhas(int energia);
    void setMaxMigalhas(int max);
    void setAcrescentarMigalhas(int valor);
    void setEnergiaMigalhas(int energia);
    void setLinhas(int l);
    void setColunas(int c);
};

#endif /* MIGALHAS_H */


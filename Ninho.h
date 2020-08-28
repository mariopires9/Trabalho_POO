#ifndef NINHO_H
#define NINHO_H

#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Formigas.h"

using namespace std;

class Mundo;
class Formigas;

class Ninho {
    int idNinho;
    static int idNinhoAnterior;
    int energiaNinho;
    int energiaInicial=0;
    int energiaCriarFormiga=0;
    int linhas, colunas;
    int unidadesEnergia;
    static int unidadesEnergiaInicial;
    Mundo* ondeEsta;
    vector <Formigas *> formiga;
    
public:
    //CONSTRUTOR
    Ninho(int linha, int coluna);
    void addFormigaAleatoria(Formigas *f);
    void addFormigaFixa(Formigas * f);
    virtual string listaNinho(int id) const;
     
    //GETS
    int getIdNinho() const;
    int getEnergiaNinho() const;
    int getEnergiaInicial() const;
    int getTranseferirEnergiaNinhoFormiga() const;
    int getCriarFormiga()const;
    int getVector() const;
    int getLinha() const;
    int getColuna() const;
    
    //SETS
    void setEnergiaNinho(int energia);
    void setEnergiaInicial(int energia);
    void setCriarFormiga(int energia);
    void setTransferirEnergiaNinhoFormiga(int valor);
    void setOndeEstou(Mundo* m);
    
};

//ostream & operator<<(ostream &o, const Ninho &n);

#endif /* NINHO_H */


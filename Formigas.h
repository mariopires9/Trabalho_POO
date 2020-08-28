#ifndef FORMIGAS_H
#define FORMIGAS_H

#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Migalhas.h"
#include "Regra.h"

using namespace std;

class Mundo;
class Ninho;

class Formigas {
    int F;
    int idFormiga;
    static int idFormigaAnterior;
    bool viva;
    int linhas, colunas;
    int visao, movimento, energiaInicial;
    vector<Ninho *> ninho;
    Ninho *pNinho;
    vector<Migalhas *> migalhas;
    Migalhas *pMigalhas;
    vector<Regra* > regras;
public:
    //CONSTRUTOR
    Formigas(Ninho& n, int linhas,int colunas, int F,int visao,int movimento,int energiaInicialFormiga);
    
    //GETS
    int getIdFormiga()const;
    string getTipo()const;
    int getVisao()const;
    int getMovimento()const;
    int getEnergia()const;
    int getLinha() const;
    int getColuna() const;
    
    
    //SETS
    void setIdFormiga(int id);
    void setTipoFormiga(const string &tipo);
    void setVisao(int visao);
    void setMovimento(int mov);
    void setEnergia(int energia);
    void setLinha(int l);
    void setColuna(int c);
    
    //FUNCOES DA FORMIGA
    bool estaViva()const;
    virtual string toString() const;
    void comeMigalha();
    virtual void escolheRegras() const = 0;
};

ostream & operator<<(ostream &o, const Formigas &f);

#endif /* FORMIGAS_H */


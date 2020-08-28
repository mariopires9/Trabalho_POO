#ifndef MUNDO_H
#define MUNDO_H

#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#include "Migalhas.h"
#include "Comunidade.h"
#include "Ninho.h"

using namespace std;

class Mundo {
    vector<Formigas *> formigas;
    vector <Migalhas *> migalhas;
    vector<Comunidade*> comunidade;
    vector<Ninho*> ninho;
    Formigas *pFormiga;
    
    const string nomeMundo;
    int limite = 0;
    int instanteAtual = 0;
    int nLinhaFoco = 0;
    int nColunaFoco = 0;
    int nZoom = 0;
    int nComunidades = 0;
    
public:
    //CONSTRUTOR
    Mundo(const string &n, int l);
    
    //FUNCOES NECESSARIAS PARA O DESENVOLVIMENTO
    void imprimeMundo(int limite);
    void addNinho(int linha, int coluna);
    void addMigalha(int linha, int coluna);
    void removeNinho(int idNinho);
    void avancaInstanteAtual();
    void avancaInstanteAtualN(int n);
    void removeFormiga(int linha,int coluna);
    void limpaMortos();
    string listaMundo() const;
    
    Mundo(const Mundo & outro);
    Mundo & operator= (const Mundo & outro);
    
    //GETS
    int getNumLimite() const;
    string getNomeMundo() const;
    int getnLinhaFoco() const;
    int getnColunaFoco() const;
    
    //SETS
    void setNumLimite(int l); 
    void setFoca(int l, int c);
    void setNomeMundo(const string & nome);
};
#endif /* MUNDO_H */


#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H

#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <istream>
#include <ctime>
#include <fstream>
#include "Mundo.h"
#include "Migalhas.h"
#include "Ninho.h"

using namespace std;

class Ninho;
class Mundo;
class Migalhas;

class Configuracao {
    Ninho *pNinho;
    vector<Ninho*> ninho;
    Mundo *pMundo;
    vector<Mundo*> mundo;
    Migalhas *pMigalhas;
    vector<Migalhas *> migalhas;
public:
    Configuracao();
    void trataMenuConfiguracao();
    int apresentarMenuConfiguracao();
    void defmundo();
    void defen();
    void defpc();
    void defvt();
    void defmi();
    void defme();
    void defnm();
    void executa();
    bool lerComandosDeFicheiroDeTexto(string nomeFicheiro);
    void interpretaLinha(string linha);
    void escreverDadosComandos(string nome, int valor);
    void inicio();
};

#endif /* CONFIGURACAO_H */


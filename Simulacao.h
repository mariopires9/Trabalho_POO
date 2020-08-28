#ifndef SIMULACAO_H
#define SIMULACAO_H


#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

#include "Cuidadora.h"
#include "Vigilante.h"
#include "Assaltante.h"
#include "Exploradora.h"
#include "Surpresa.h"
#include "Ninho.h"

using namespace std;

class Ninho;
class Mundo;
class Migalhas;
class Configuracao;
class Formigas;

class Simulacao {
    Mundo *pMundo;
    Ninho *pNinho;
    Formigas *pFormigas;
    Migalhas *pMigalhas;
    vector <Ninho* > ninhos;
    vector <string> comandos = {"sair", "ninho", "criaf", "cria1", "migalha", "foca", "tempo", "tempoN", "energninho",
        "energformiga", "mata", "inseticida", "listamundo", "listaninho", "listaposicao", "guarda", "muda", "apaga" , "configurar"};  
    Configuracao *pConfiguracao;
public:
    //CONSTRUTOR
    Simulacao(Mundo *novoMundo, Ninho *novoNiho, Migalhas *novaMigalha);
    
    void leComando();
    int escolherComandoSimulacao(istringstream &iss);
    
    //COMANDOS DE SIMULACAO
    void ninho(istringstream &iss);
    void criaf(istringstream &iss);
    void cria1(istringstream &iss);
    void migalha(istringstream &iss);
    void foca(istringstream &iss);
    void tempo(istringstream &iss);
    void tempoN(istringstream &iss);
    void energinho(istringstream &iss);
    void energformiga(istringstream &iss);
    void mata(istringstream &iss);
    void inseticida(istringstream &iss);
    void listamundo(istringstream &iss);
    void listaninho(istringstream &iss);
    void listaposicao(istringstream &iss);
    void guarda(istringstream &iss);
    void muda(istringstream &iss);
    void apaga(istringstream &iss);
    void sair(istringstream &iss);
};

#endif /* SIMULACAO_H */


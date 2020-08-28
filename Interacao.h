#ifndef INTERACAO_H
#define INTERACAO_H

#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Ninho;
class Mundo;
class Comunidade;
class Formigas;

class Interacao {
    Mundo *pMundo;
    vector <string> comandos = {"sair", "ninho", "criaf", "cria1 ", "migalha", "foca", "tempo", "tempo", "energninho", 
    "energformiga", "mata", "inseticida", "listamundo", "listaninho", "listaposicao", "guarda", "muda", "apaga"};  
    vector <string> v_linha;
public:
    Interacao(Mundo *novoMundo);
    void imprimeMundo(int limite);
    void leComando();
    int escolherComandoSimulacao(istringstream &iss);
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
    
};

#endif /* INTERACAO_H */


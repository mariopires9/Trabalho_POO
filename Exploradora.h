#ifndef EXPLORADORA_H
#define EXPLORADORA_H

#include <string>
#include <vector>
#include "Formigas.h"

class Exploradora :public Formigas{
    string tipo;
public:
    Exploradora(Ninho& n,string tipo, int linhas, int colunas, int F,int visao,int movimento,int energiaInicialFormiga);
    virtual string ToString() const;
    void escolheRegras() const;
};

#endif /* EXPLORADORA_H */


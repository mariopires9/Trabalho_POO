#ifndef CUIDADORA_H
#define CUIDADORA_H

#include <string>
#include <vector>
#include "Formigas.h"

class Cuidadora :public Formigas{
    string tipo;
public:
    Cuidadora(Ninho& n,string tipo, int linhas, int colunas, int F,int visao,int movimento,int energiaInicialFormiga);
    virtual string ToString() const;
    void escolheRegras() const;
};

#endif /* CUIDADORA_H */


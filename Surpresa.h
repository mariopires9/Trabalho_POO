
#ifndef SURPRESA_H
#define SURPRESA_H

#include <string>
#include <vector>
#include "Formigas.h"

class Surpresa :public Formigas{
    string tipo;
public:
    Surpresa(Ninho& n,string tipo, int linhas, int colunas, int F,int visao,int movimento,int energiaInicialFormiga);
    virtual string ToString() const;
    void escolheRegras() const;
};

#endif /* SURPRESA_H */


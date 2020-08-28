#ifndef VIGILANTE_H
#define VIGILANTE_H

#include <string>
#include <vector>
#include "Formigas.h"

class Vigilante :public Formigas{
    string tipo;
public:
    Vigilante(Ninho& n,string tipo, int linhas, int colunas, int F,int visao,int movimento,int energiaInicialFormiga);
    virtual string ToString() const;
    void escolheRegras() const;
};

#endif /* VIGILANTE_H */


#ifndef ASSALTANTE_H
#define ASSALTANTE_H

#include <string>
#include <vector>
#include "Formigas.h"

class Assaltante :public Formigas{
    string tipo;
public:
    Assaltante(Ninho& n, string tipo, int linhas, int colunas, int F,int visao,int movimento,int energiaInicialFormiga);
    virtual string ToString() const;
    void escolheRegras() const;
};
#endif /* ASSALTANTE_H */


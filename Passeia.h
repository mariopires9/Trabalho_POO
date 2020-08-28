#ifndef PASSEIA_H
#define PASSEIA_H

#include "Regra.h"

class Passeia :public Regra {
    string tipoRegra;
public:
    Passeia(bool condicao, string acao, string tipo);
};

#endif /* PASSEIA_H */


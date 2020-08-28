#ifndef PROTEGE_H
#define PROTEGE_H

#include "Regra.h"

class Protege :public Regra{
    string tipoRegra;
public:
    Protege(bool condicao, string acao, string tipo);
};

#endif /* PROTEGE_H */


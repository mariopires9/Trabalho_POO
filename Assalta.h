#ifndef ASSALTA_H
#define ASSALTA_H

#include "Regra.h"

class Assalta : public Regra{
    string tipoRegra;
public:
    Assalta(bool condicao, string acao, string tipo);
};

#endif /* ASSALTA_H */


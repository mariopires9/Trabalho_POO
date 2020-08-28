#ifndef FOGE_H
#define FOGE_H

#include "Regra.h"

class Foge :public Regra{
    string tipoRegra;
public:
    Foge(bool condicao, string acao, string tipo);
private:

};

#endif /* FOGE_H */


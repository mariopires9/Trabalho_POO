#ifndef PERSEGUE_H
#define PERSEGUE_H

#include "Regra.h"

class Persegue :public Regra{
     string tipoRegra;
public:
    Persegue(bool condicao, string acao, string tipo);
};

#endif /* PERSEGUE_H */


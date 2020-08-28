#ifndef COMEMIGALHA_H
#define COMEMIGALHA_H

#include "Regra.h"

class ComeMigalha :public Regra{
    string tipoRegra;
public:
    ComeMigalha(bool condicao, string acao, string tipo);
};

#endif /* COMEMIGALHA_H */


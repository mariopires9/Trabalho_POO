#ifndef PROCURAMIGALHA_H
#define PROCURAMIGALHA_H

#include "Regra.h"

class ProcuraMigalha :public Regra {
     string tipoRegra;
public:
    ProcuraMigalha(bool condicao, string acao, string tipo);
};

#endif /* PROCURAMIGALHA_H */


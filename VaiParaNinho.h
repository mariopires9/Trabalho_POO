#ifndef VAIPARANINHO_H
#define VAIPARANINHO_H

#include "Regra.h"

class VaiParaNinho :public Regra{
    string tipoRegra;
public:
    VaiParaNinho(bool condicao, string acao, string tipo);
};

#endif /* VAIPARANINHO_H */


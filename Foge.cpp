#include "Foge.h"

Foge::Foge(bool condicao, string acao, string tipo): Regra(condicao, acao){
    cout << "Regra foge a ser construida..." << endl;
}



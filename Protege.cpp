#include "Protege.h"

Protege::Protege(bool condicao, string acao, string tipo): Regra(condicao, acao){
    cout << "Regra protege a ser construida..." << endl;
}


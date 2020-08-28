#include "Persegue.h"

Persegue::Persegue(bool condicao, string acao, string tipo): Regra(condicao, acao){
    cout << "Regra persegue a ser construida..." << endl;
}


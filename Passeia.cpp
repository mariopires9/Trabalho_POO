#include "Passeia.h"

Passeia::Passeia(bool condicao, string acao, string tipo): Regra(condicao, acao){
    cout << "Regra passeia a ser construida..." << endl;
}
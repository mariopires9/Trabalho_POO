#ifndef REGRA_H
#define REGRA_H

#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;



class Regra {
    
    bool condicao;
    string acao;
    
public:
    Regra(bool condicao, string acao);
};

#endif /* REGRA_H */


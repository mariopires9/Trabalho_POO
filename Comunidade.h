#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
//#include "Formigas.h"

#ifndef COMUNIDADE_H
#define COMUNIDADE_H

using namespace std;

class Comunidade {
    //vector <Formigas *> formiga;
    
public:
    
    string toString()const;
};

ostream & operator<<(ostream &o, const Comunidade &c);
#endif /* COMUNIDADE_H */


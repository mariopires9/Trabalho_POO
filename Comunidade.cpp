#include "Comunidade.h"


string Comunidade::toString()const{
    
}

ostream & operator<<(ostream &o, const Comunidade &c){
    o<< c.toString();
    return o;
}
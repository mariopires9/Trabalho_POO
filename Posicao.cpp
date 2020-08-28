#include "Posicao.h"

Posicao::Posicao() {}

Posicao::~Posicao() {}

Posicao::Posicao(Posicao * p){
    x = p->getX();
    y = p->getY();
    comunidade = p->getComunidade();
    ninho = p->getNinho();
    formiga = p->getFormiga();
    migalha = p->getMigalha();
}

Posicao::Posicao(char comunidade, bool ninho, bool formiga, int x, int y, char migalha){
    this->comunidade = comunidade;
    this->ninho = ninho;
    this->formiga = formiga;
    this->x = x;
    this->y = y;
    this->migalha = migalha;
}

Posicao::Posicao(char comunidade, int x, int y, bool formiga){
    this->comunidade = comunidade;
    this->x = x;
    this->y = y;
    this->formiga = formiga;
}

char Posicao::getMigalha()const{
    return this->migalha;
}

bool Posicao::getFormiga()const{
    return this->formiga;
}

bool Posicao::getNinho()const{
    return this->ninho;
}


void Posicao::setFormiga(bool formiga){
    this->formiga = formiga;
}

void Posicao::setMigalha(char migalha){
    this->migalha = migalha;
}

int Posicao::getX()const{
    return this->x;
}

void Posicao::setX(int x){
    this->x = x;
}

int Posicao::getY()const{
    return this->y;
}

void Posicao::setY(int y){
    this->y = y;

}

char Posicao::getComunidade()const{
    return this->comunidade;
}

void Posicao::setComunidade(char comunidade){
    this->comunidade = comunidade;
}
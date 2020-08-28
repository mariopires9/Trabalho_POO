#include <map>

#include "Ninho.h"
#include "Consola.h"
#include "Mundo.h"

int Ninho::idNinhoAnterior = 0;
int Ninho::unidadesEnergiaInicial = 1;

Ninho::Ninho(int linha, int coluna){
    linhas = linha;
    colunas = coluna;
    energiaNinho = energiaInicial;
    idNinhoAnterior++;
    idNinho = idNinhoAnterior;
    unidadesEnergia = unidadesEnergiaInicial++;
    ondeEsta=nullptr;
    Consola::setTextColor(Consola::BRANCO);
    Consola::gotoxy(73,4);
    cout << "A construir Ninho..." ;
}

void Ninho::addFormigaAleatoria(Formigas * f){
   
    //if(energiaNinho >= energiaCriarFormiga){
    formiga.push_back(f);
    //}
    //else
      //  cout << "O ninho nao tem energia suficiente para criar uma formiga!" << endl;
}

void Ninho::addFormigaFixa(Formigas * f){
    formiga.push_back(f);
}

int Ninho::getEnergiaInicial() const{
    return energiaInicial;
}

int Ninho::getEnergiaNinho() const {
    return energiaNinho;
}

int Ninho::getLinha() const{
    return linhas;
}

int Ninho::getColuna() const{
    return colunas;
}

int Ninho::getVector() const{
    return formiga.size();
}

int Ninho::getIdNinho() const{
    return idNinho;
}

void Ninho::setEnergiaNinho(int energia){
    energiaNinho = energia;
}

void Ninho::setEnergiaInicial(int e){
    energiaInicial = e;
}

int Ninho::getCriarFormiga() const{return energiaCriarFormiga;}

void Ninho::setCriarFormiga(int energia){
    energiaCriarFormiga = energia;
}

int Ninho::getTranseferirEnergiaNinhoFormiga() const{return unidadesEnergia;}

void Ninho::setTransferirEnergiaNinhoFormiga(int valor){
    unidadesEnergia = valor;
}

void Ninho::setOndeEstou(Mundo* m){
    ondeEsta=m;
}

string Ninho::listaNinho(int id) const{
    ostringstream ninho;
    int count =0;
    
    ninho<<"Ninho - idNinho: " << id;
    ninho<<" | Linha: " << getLinha() << " | Coluna: " << getColuna(); 
    ninho<<" | Formigas: ";
            count = formiga.size();
    ninho<< count;
    ninho<<" | Energia: " << getEnergiaNinho() << endl;
           
    return ninho.str();
}

//ostream & operator<<(ostream &o, const Ninho &n){
//    o<< n.listaNinho();
//    return o;
//}

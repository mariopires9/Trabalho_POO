#include "Formigas.h"
#include "Mundo.h"
#include "Ninho.h"
#include "Consola.h"

int Formigas::idFormigaAnterior=0;

Formigas::Formigas(Ninho & n, int linhas,int colunas, int F,int visao,int movimento,int energiaInicialFormiga){
            idFormiga = idFormigaAnterior++;
            pNinho = &n;
            this->visao = visao;
            this->movimento = movimento;
            this->energiaInicial = energiaInicialFormiga;
            this->linhas = linhas;
            this->colunas = colunas;
}


//FUNCAO DA CLASSE REGRACOMEMIGALHA
void Formigas::comeMigalha(){
    int comer = 10;
    
    if(getLinha() == pMigalhas->getLinhas() && getColuna() == pMigalhas->getColunas()){
        for(int i = 0; i < migalhas.size() ; i++){
            if (migalhas[i]->getEnergiaMigalha() <= 10){
			delete migalhas[i];
            }
            else
            {
                int energiaMigalha = migalhas[i]->getEnergiaMigalha();
                energiaMigalha = comer - energiaMigalha;
                migalhas[i]->setEnergiaMigalhas(energiaMigalha);
                
                int energiaFormiga = comer + getEnergia();
                setEnergia(energiaFormiga);
            }
        }
        
        
    }
}

int Formigas::getIdFormiga()const{return idFormiga;}

bool Formigas::estaViva()const{
    if(viva==false)
        return false;
    else
        return true;  
}

int Formigas::getVisao()const{return visao;}

int Formigas::getLinha() const{
    return linhas;
}

int Formigas::getColuna() const{
    return colunas;
}

int Formigas::getMovimento() const{return movimento;}

int Formigas::getEnergia() const{return energiaInicial;}

void Formigas::setIdFormiga(int id){idFormiga = id;}

void Formigas::setLinha(int l){
    linhas = l;
}

void Formigas::setColuna(int c){
    colunas = c;
}

void Formigas::setVisao(int visao){this->visao = visao;}

void Formigas::setMovimento(int mov){movimento = mov;}

void Formigas::setEnergia(int energia){energiaInicial = energia;}

string Formigas::toString() const{
    ostringstream formiga;
    formiga<<"Informacao da Formiga: "
           <<"\n Id: "<< idFormiga
           <<"\n Vida: "<< viva 
           <<"\n Visao: "<< visao 
           <<"\n Movimento: "<< movimento
           <<"\n Energia: "<< energiaInicial<< endl;
    return formiga.str();
}

ostream & operator<<(ostream &o, const Formigas &f){
    o<< f.toString();
    return o;
}
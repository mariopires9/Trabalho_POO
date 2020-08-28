#include "Mundo.h"
#include "Consola.h"
#include <time.h>

//DIMENSAO MAXIMA DO MUNDO 40*40
Mundo::Mundo(const string &n, int l):nomeMundo(n){
    limite = l;
    cout << "Construir mundo...\n";
}

void Mundo::limpaMortos(){
	for (int i = 0; i < ninho.size(); i++)
		if (ninho[i]->getEnergiaNinho() <= 0){
			delete ninho[i];
		}

	for (int i = 0; i < formigas.size(); i++)
		if (formigas[i]->getEnergia() <= 0){
			delete formigas[i];
		}
        
        for(int i = 0; i < migalhas.size() ; i++){
            if (migalhas[i]->getEnergiaMigalha() <= 0){
			delete migalhas[i];
		}
        }
}

Mundo::Mundo(const Mundo & outro){
    ninho = nullptr;
    *this = outro;
}

Mundo & Mundo::operator =(const Mundo& outro){
    return *this;
}

void Mundo::removeNinho(int idNinho){ 
    //eliminar um ninho
	for (unsigned int i = 0; i < ninho.size(); i++) {
		if (ninho[i]->getIdNinho() == idNinho)
		{
			delete ninho[i];
			ninho.erase(ninho.begin() + i);
		}
	}
}

void Mundo::removeFormiga(int linha,int coluna){
    //eliminar uma formiga
	for (unsigned int i = 0; i < formigas.size(); i++) {
		if (formigas[i]->getLinha() == linha && formigas[i]->getColuna() == coluna)
		{
			delete formigas[i];
			formigas.erase(formigas.begin() + i);
		}
	}
}

void Mundo::avancaInstanteAtual(){
	
        instanteAtual = instanteAtual + 1;
	
        
        for (Formigas *x : formigas){
            pFormiga->escolheRegras();
        }
        
	this->limpaMortos();
}

void Mundo::avancaInstanteAtualN(int n){
	for (int i = 0; i < n; i++) {
		instanteAtual++;
	}
        
        for (Formigas *x : formigas){
            pFormiga->escolheRegras();
        }
	this->limpaMortos();
}

void Mundo::imprimeMundo(int limite){
    
    Consola::gotoxy(9, 2);
    Consola::setTextColor(Consola::BRANCO_CLARO);
    cout<<"Simulacao de Populacoes de Formigas";
    
    char **matrizMundo = new char*[limite];
    
    for(int i = 0; i < limite ; i++)
        matrizMundo[i] = new char[limite];
    
    for(int Y = 0; Y < limite ; Y++){
        for(int X = 0; X < limite; X++){
            Consola::setTextColor(Consola::BRANCO_CLARO);
            Consola::gotoxy(7 + X, 4 + Y);
            matrizMundo[Y][X] = (char)177; 
            cout << matrizMundo[Y][X];
        }
        cout << endl;
    } 
   
    //LINHA VERTICAL
    for (int i = 0; i<25 ; i++){
        Consola::gotoxy(72, i);
        cout << (char)(219);
    } 
    
    //LINHA HORIZONTAL
    for (int i = 0; i< 120 ; i++){
        Consola::gotoxy(i, 25);
        cout << (char)(223);
    } 
}

void Mundo::addNinho(int linha, int coluna){
    Ninho* novoNinho = new Ninho(linha, coluna);
    ninho.push_back(novoNinho);
        
    Consola::setTextColor(Consola::VERDE);
    Consola::gotoxy(73, 5);
    cout << "N";
    
    Consola::setTextColor(Consola::BRANCO);
    Consola::gotoxy(74,5);
    cout << " - O ninho esta na posicao: (" << linha << "," << coluna << ")" << endl;
}

void Mundo::addMigalha(int linha, int coluna){
    
    Migalhas* novaMigalha = new Migalhas(linha, coluna);
    migalhas.push_back(novaMigalha);
        
    Consola::setTextColor(Consola::VERDE);
    Consola::gotoxy(60, 5);
    cout << "M";
    
    Consola::setTextColor(Consola::BRANCO);
    Consola::gotoxy(61,5);
    cout << " - A migalha esta na posicao: (" << linha << "," << coluna << ")" << endl;
}

string Mundo::listaMundo() const{
    ostringstream mundo;
    int count =0;
    
    mundo<<"Mundo - Ninhos: ";
            for(int i=0;i<ninho.size();i++){
                mundo << ninho[i]->getIdNinho();
            }
    mundo << " | Migalhas: ";
            for(int i=0;i<migalhas.size();i++){
                migalhas[i]->getId();
                count++;
            }
    mundo << count <<" | Tempo: " << instanteAtual << endl;
           
    return mundo.str();
}

int Mundo::getNumLimite() const{
    return limite;
}

int Mundo::getnLinhaFoco() const{
    return nLinhaFoco;
}

int Mundo::getnColunaFoco() const{
    return nColunaFoco;
}

string Mundo::getNomeMundo() const{
    return nomeMundo;
}

void Mundo::setNumLimite(int l){
    limite = l;
}

void Mundo::setFoca(int l, int c){
    this->nLinhaFoco = l;
    this->nColunaFoco = c;
}

#include "Migalhas.h"
#include "Consola.h"

int Migalhas:: idMigalhaAnterior = 0;

Migalhas::Migalhas(int linha, int coluna){
    linhas = linha;
    colunas = coluna;
    idMigalha = idMigalhaAnterior++;
    energiaMigalhas = energiaInicialMigalhas;
    Consola::setTextColor(Consola::BRANCO);
    Consola::gotoxy(60,4);
    cout << "Migalha a ser construida..." << endl;
}

int Migalhas::getEnergiaInicialMigalhas() const{
    return energiaInicialMigalhas;
}

int Migalhas::getId() const{
    return idMigalha;
}

int Migalhas::getEnergiaMigalha() const{
    return energiaMigalhas;
}

int Migalhas::getLinhas() const{
    return linhas;
}

int Migalhas::getColunas()const{
    return colunas;
}

void Migalhas::setEnergiaInicialMigalhas(int energia){
    energiaInicialMigalhas = energia;
}

void Migalhas::setEnergiaMigalhas(int energia){
    energiaMigalhas = energia;
}

void Migalhas::setLinhas(int l){
    linhas = l;
}

void Migalhas::setColunas(int c){
    colunas = c;
}

void Migalhas::setMaxMigalhas(int max){
    maxMigalhas = max;
}

int Migalhas::getAcrescentarMigalhas()const{return numeroPosicoesVazias;}

void Migalhas::setAcrescentarMigalhas(int valor){
    numeroPosicoesVazias = valor;
}

#include "Cuidadora.h"
#include "Consola.h"
#include "Formigas.h"

Cuidadora::Cuidadora(Ninho& n, string tipo, int linhas, int colunas, int F,int visao,int movimento,int energiaInicialFormiga): Formigas(n, linhas, colunas, F, visao, movimento, energiaInicialFormiga) {
    this->tipo = tipo;
    for(int i = 0; i<F ; i++){
        Consola::setTextColor(Consola::BRANCO);
        Consola::gotoxy(30,i+4);
        cout << "A construir formiga do tipo Cuidadora..." << endl;
    }
}

string Cuidadora::ToString() const
{
	ostringstream oss;
	oss << Formigas::toString() << " - " << tipo ;
	return oss.str();
}

void Cuidadora::escolheRegras() const {
    cout << "RegraFoge, RegraComeMigalha, RegraProcuraMigalha, RegraVaiParaNinho, RegraPasseia" << endl;
}


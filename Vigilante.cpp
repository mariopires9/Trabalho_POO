#include "Vigilante.h"
#include "Consola.h"


Vigilante::Vigilante(Ninho& n,string tipo, int linhas, int colunas, int F,int visao,int movimento,int energiaInicialFormiga): Formigas(n, linhas, colunas, F,visao,movimento,energiaInicialFormiga) {

    this->tipo = tipo;
    for(int i=0; i<F;i++){
        Consola::setTextColor(Consola::BRANCO);
        Consola::gotoxy(30,i+4);
        cout << "A construir formiga do tipo Vigilante..." << endl;
    }
}

string Vigilante::ToString() const
{
	ostringstream oss;
	oss << Formigas::toString() << " - " << tipo ;
	return oss.str();
}

void Vigilante::escolheRegras() const {
    cout << "RegraProtege, RegraComeMigalha, RegraProcuraMigalha, RegraPasseia" << endl;
}


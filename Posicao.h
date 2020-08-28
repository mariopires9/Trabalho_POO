#ifndef POSICAO_H
#define POSICAO_H


#include <string>
#include <iostream>

using namespace std;

class Posicao {
	//int ID = 0;
	int x = 0;
	int y = 0;
	char comunidade = 'c';
	bool ninho = false;
	bool formiga = false;
	char migalha = '.';
public:
    //CONSTRUTORES
        Posicao();
        Posicao(Posicao * p);
        Posicao(char comunidade, bool ninho, bool formiga, int x, int y, char migalha);
        Posicao(char comunidade, int x, int y, bool formiga);
        
        //DESTRUTORES
        ~Posicao();
        
        //GETS
        char getMigalha() const;
        bool getFormiga() const;
        bool getNinho()const;
        int getX()const;
        int getY()const;
        char getComunidade()const;
        
        //SETS
        void setFormiga(bool formiga);
        void setMigalha(char migalha);
        void setX(int x);
        void setY(int y);
        void setComunidade(char comunidade);
};

#endif /* POSICAO_H */


#include "Interacao.h"
#include "Consola.h"
#include "Mundo.h"
#include "Ninho.h"
#include "Formigas.h"

Interacao::Interacao(Mundo *novoMundo){
    cout << "Fase de Configuracao correu bem, passamos agora para a fase de simulacao\n";
    pMundo=novoMundo;
}

void Interacao::imprimeMundo(int limite){
    
    Consola::gotoxy(9, 2);
    Consola::setTextColor(Consola::BRANCO_CLARO);
    cout<<"Simulacao de Populacoes de Formigas";
    
    for(int Y = 0; Y < limite ; Y++){
        for(int X = 0; X < limite; X++){
            Consola::setTextColor(Consola::BRANCO_CLARO);
            Consola::gotoxy(7 + X, 4 + Y);
            cout << (char)177;
        }
        cout << (char)177;
    } 
   
    for (int i = 0; i<25 ; i++){
        Consola::gotoxy(54, i);
        cout << (char)(219);
    } 
    
    for (int i = 0; i< 120 ; i++){
        Consola::gotoxy(i, 25);
        cout << (char)(223);
    } 
}

void Interacao::leComando(){
    string linha;
    int iComando = 0;
    
    istringstream iss;
    iss.str(linha);
    
    int limite = pMundo->getNumLimite();
    pMundo->imprimeMundo(limite);
    
    do{
        pMundo->imprimeMundo(limite);
        Consola::gotoxy(1,27);
        Consola::setTextColor(Consola::BRANCO_CLARO);
        cout << "Comando: ";
        getline(cin, linha);
        
        istringstream iss;
        iss.str(linha);
                
        iComando=escolherComandoSimulacao(iss);
        
        switch(iComando){  
            case 0: 
                break;
            case 1:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(60,3);
                cout<<"Comando Criar Ninho:\n";
                ninho(iss);
                break;
            case 2:
                cout<<"Criar formiga do tipo T numa posicao aleatoria\n";
                criaf(iss);
                break;
            case 3:
                cout<<"Criar formiga do tipo T numa posicao especifica\n";
                cria1(iss);
                break;
            case 4:
                cout<<"Cria migalha na posicao x,y \n";
                migalha(iss);
                break;
            case 5:
                cout<<"Foca grelha\n";
                foca(iss);
                break;
            case 6:
                cout<<"Tempo - passa uma iteracao\n";
                tempo(iss);
                break;
            case 7:
                cout<<"Tempo N - n iteracaoes\n";
                tempoN(iss);
                break;
            case 8:
                cout<<"Acrescentar um valor de energia E ao ninho N";
                energinho(iss);
                break;
            case 9:
                cout<<"Acrescenta um valor de energia E à formiga que estiver na posicao x,y \n";
                energformiga(iss);
                break;
            case 10:
                cout<<"Mata a formiga na posicao x,y \n";
                mata(iss);
                break;
            case 11:
                cout<<"Elimina o ninho N e a sua Comunidade \n";
                inseticida(iss);
                break;
            case 12:
                cout<<"Lista tudo no mundo \n";
                listamundo(iss);
                break;
            case 13:
                cout<<"Lista ninho \n";
                listaninho(iss);
                break; 
            case 14:
                cout<<"Lista posicao - apresenta os elementos que estao na posicao \n";
                listaposicao(iss);
                break;  
            case 15:
                cout<<"Guarda o mundo fazendo uma cópia \n";
                guarda(iss);
                break;
            case 16:
                cout<<"Muda para uma cópia \n";
                muda(iss);
                break;
            case 17:
                cout<<"Apaga uma copia \n";
                apaga(iss);
                break;    
        }
        //system("sleep 2");
    }while(iComando != 0);
    Consola::clrscr();
    Consola::gotoxy(5,5);
    
    cout<<"Acabou a simulacao\n";
}

void Interacao::ninho(istringstream &iss){
    int linha, coluna;
    iss >> linha >> coluna;
    
    pMundo->addNinho(linha, coluna);      
}
void Interacao::criaf(istringstream &iss){
    int F;
    string T;
    int N;
    
    iss >> F >> T >> N;
    
    pMundo->acrescentarFormigaNinho(F, T, N);   
}
void Interacao::cria1(istringstream &iss){
    
}
void Interacao::migalha(istringstream &iss){
    
}
void Interacao::foca(istringstream &iss){
    
}
void Interacao::tempo(istringstream &iss){
    
}
void Interacao::tempoN(istringstream &iss){
}
void Interacao::energinho(istringstream &iss){
    
}
void Interacao::energformiga(istringstream &iss){
    
}
void Interacao::mata(istringstream &iss){
    
}
void Interacao::inseticida(istringstream &iss){
    
}
void Interacao::listamundo(istringstream &iss){
    
}
void Interacao::listaninho(istringstream &iss){
    
}
void Interacao::listaposicao(istringstream &iss){
    
}
void Interacao::guarda(istringstream &iss){
    
}
void Interacao::muda(istringstream &iss){
    
}
void Interacao::apaga(istringstream &iss){
    
}

int Interacao::escolherComandoSimulacao(istringstream &iss){
    string comando;
    iss >> comando;
    Consola::gotoxy(60,1);
    cout << "iComando: "<< comando ;
    for(int i=0; i<comandos.size(); i++){
        if(comando == comandos[i])
            return i;
    }
    return -1;
}


#include "Simulacao.h"
#include "Consola.h"
#include "Mundo.h"
#include "Ninho.h"
#include "Migalhas.h"
#include "Formigas.h"
#include "Configuracao.h"

Simulacao::Simulacao(Mundo *novoMundo, Ninho *novoNinho, Migalhas *novaMigalha){
    cout << "Fase de Configuracao correu bem, passamos agora para a Fase de Simulacao\n";
    pMundo=novoMundo;
    pNinho=novoNinho;
    pMigalhas=novaMigalha;
}

void Simulacao::leComando(){
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
                sair(iss);
                break;
            case 1:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Comando Criar Ninho:\n";
                ninho(iss);
                break;
            case 2:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(73,2);
                cout<<"Criar formiga do tipo T numa posicao aleatoria\n";
                criaf(iss);
                break;
            case 3:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(73,2);
                cout<<"Criar formiga do tipo T numa posicao especifica\n";
                cria1(iss);
                break;
            case 4:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Cria migalha na posicao x,y \n";
                migalha(iss);
                break;
            case 5:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Foca grelha\n";
                foca(iss);
                break;
            case 6:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Tempo - passa uma iteracao\n";
                tempo(iss);
                break;
            case 7:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Tempo N - n iteracaoes\n";
                tempoN(iss);
                break;
            case 8:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(73,2);
                cout<<"Acrescentar um valor de energia E ao ninho N";
                energinho(iss);
                break;
            case 9:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(73,2);
                cout<<"Acrescenta um valor de energia E: ";
                Consola::gotoxy(73,3);
                cout<<" à formiga que estiver na posicao x,y \n";
                energformiga(iss);
                break;
            case 10:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Mata a formiga na posicao x,y \n";
                mata(iss);
                break;
            case 11:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Elimina o ninho N e a sua Comunidade \n";
                inseticida(iss);
                break;
            case 12:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Lista tudo no mundo \n";
                listamundo(iss);
                break;
            case 13:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Lista ninho \n";
                listaninho(iss);
                break; 
            case 14:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(73,2);
                cout<<"Apresenta os elementos que estao na posicao \n";
                listaposicao(iss);
                break;  
            case 15:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(73,2);
                cout<<"Guarda o mundo fazendo uma cópia \n";
                guarda(iss);
                break;
            case 16:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Muda para uma cópia \n";
                muda(iss);
                break;
            case 17:
                Consola::clrscr();
                Consola::setTextColor(Consola::VERDE);
                Consola::gotoxy(74,2);
                cout<<"Apaga uma copia \n";
                apaga(iss);
                break;  
            case 18:
                Consola::clrscr();
                Consola::gotoxy(73,2);
                pConfiguracao->trataMenuConfiguracao();
        }
        //system("sleep 2");
    }while(iComando != 0);
    Consola::clrscr();
    Consola::gotoxy(5,5);
    
    cout<<"Acabou a simulacao\n";
}

void Simulacao::ninho(istringstream &iss){
    int linha, coluna;
    iss >> linha >> coluna;
    
    pMundo->addNinho(linha, coluna);
}

void Simulacao::criaf(istringstream &iss){
    int F;
    string T;
    int N;
    
    iss >> F >> T >> N;
    int i = 0;
    
  
    int visao=0, movimento=0, energiaInicialFormiga=0;
    
    //pNinho = pMundo->procuraNinho(N);
    ninhos.push_back(pNinho);
    
    for(int i = 0; i < F ; i++){
        int linhas = rand()%100;
        int colunas = rand()%100;
        
        if(T == "cuidadora" || T == "Cuidadora"){
            
            visao = 5; movimento =3; energiaInicialFormiga = 100; 
            Cuidadora* cuidadora = new Cuidadora(*ninhos[N-1], T, linhas, colunas, F, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, i+4);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,i+4);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(cuidadora);  
        } 
        else if(T == "vigilante" || T == "Vigilante"){
            visao = 7; movimento =5; energiaInicialFormiga = 150; 
            Vigilante* vigilante = new Vigilante(*ninhos[N-1],T, linhas, colunas, F, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, i+4);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,i+4);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(vigilante);  

        }
        else if(T == "assaltante" || T == "Assaltante"){
            visao = 8; movimento =4; energiaInicialFormiga = 80; 
            Assaltante* assaltante = new Assaltante(*ninhos[N-1],T, linhas, colunas, F, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, i+4);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,i+4);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(assaltante);

        }
        else if(T == "exploradora" || T == "Exploradora"){
            visao = 10; movimento =8; energiaInicialFormiga = 200; 
            Exploradora* exploradora = new Exploradora(*ninhos[N-1],T, linhas, colunas, F, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, i+4);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,i+4);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(exploradora);

        }
        else if(T == "surpresa" || T == "Surpresa"){
            visao = 10; movimento =10; energiaInicialFormiga = 50; 
            Surpresa* surpresa = new Surpresa(*ninhos[N-1],T, linhas, colunas, F, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, i+4);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,i+4);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(surpresa);

        }
        else
            cout <<  "Nao existe nenhuma formiga com este Tipo: " << T << endl;
        
    }
}

void Simulacao::cria1(istringstream &iss){
    string T= "";
    int N = 0;
    int linhas = 0, colunas =0;
    
    iss >> T >> N >> linhas >> colunas;
    
    pNinho = pMundo->procuraNinho(N);
    ninhos.push_back(pNinho);
    
    int x = 4;
    
    int visao=0, movimento=0, energiaInicialFormiga=0;
    
    if(T == "cuidadora" || T == "Cuidadora"){
            visao = 5; movimento =3; energiaInicialFormiga = 100;
            Cuidadora* cuidadora = new Cuidadora(*ninhos[N-1],T, linhas, colunas, 1, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, x);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,x);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(cuidadora);  
        } 
        else if(T == "vigilante" || T == "Vigilante"){
            visao = 7; movimento =5; energiaInicialFormiga = 150; 
            Vigilante* vigilante = new Vigilante(*ninhos[N-1],T, linhas, colunas, 1, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, x);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,x);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(vigilante);  

        }
        else if(T == "assaltante" || T == "Assaltante"){
            visao = 8; movimento =4; energiaInicialFormiga = 80; 
            Assaltante* assaltante = new Assaltante(*ninhos[N-1],T, linhas, colunas, 1, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, x);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,x);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(assaltante);

        }
        else if(T == "exploradora" || T == "Exploradora"){
            visao = 10; movimento =8; energiaInicialFormiga = 200; 
            Exploradora* exploradora = new Exploradora(*ninhos[N-1],T, linhas, colunas, 1, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, x);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,x);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(exploradora);

        }
        else if(T == "surpresa" || T == "Surpresa"){
            visao = 10; movimento =10; energiaInicialFormiga = 50;
            Surpresa* surpresa = new Surpresa(*ninhos[N-1],T, linhas, colunas, 1, visao, movimento, energiaInicialFormiga);
            
            Consola::setTextColor(Consola::VERDE);
            Consola::gotoxy(74, x);
            cout << "F";

            Consola::setTextColor(Consola::BRANCO);
            Consola::gotoxy(75,x);
            cout << " - A formiga esta na posicao: (" << linhas << "," << colunas << ")" << endl;   
            
            pNinho->addFormigaAleatoria(surpresa);

        }
        else
            cout <<  "Nao existe nenhuma formiga com este Tipo: " << T << endl;     
}

void Simulacao::migalha(istringstream &iss){
    int linha, coluna;
    iss >> linha >> coluna;
    
    pMundo->addMigalha(linha, coluna); 
}

void Simulacao::foca(istringstream &iss){
    int linha, coluna;
    
    iss >> linha >> coluna;
    
    pMundo->setFoca(linha, coluna);
}

void Simulacao::tempo(istringstream &iss){
    pMundo->avancaInstanteAtual();
}

void Simulacao::tempoN(istringstream &iss){
    int num;
    
    iss >> num;
    pMundo->avancaInstanteAtualN(num);
}
void Simulacao::energinho(istringstream &iss){
    
}
void Simulacao::energformiga(istringstream &iss){
    
}
void Simulacao::mata(istringstream &iss){
    int linha, coluna;
    
    iss >> linha >> coluna;
    
    pMundo->removeFormiga(linha, coluna);
}
void Simulacao::inseticida(istringstream &iss){
    int idNinho;
    
    iss >> idNinho;
    
    pMundo->removeNinho(idNinho); 
}
void Simulacao::listamundo(istringstream &iss){
    int linha, coluna;
    
    iss >> linha >> coluna;
    
    Consola::setTextColor(Consola::BRANCO);
    Consola::gotoxy(74,4);
    cout << pMundo->listaMundo();
    Consola::setTextColor(Consola::BRANCO);
    Consola::gotoxy(74,5);
    cout << "Formigas: " << pNinho->getVector();
   
}
void Simulacao::listaninho(istringstream &iss){
    int id;
    
    iss >> id ;
    
    Consola::setTextColor(Consola::BRANCO);
    Consola::gotoxy(74,4);
    cout << pNinho->listaNinho(id);
}
void Simulacao::listaposicao(istringstream &iss){
    int linha, coluna;
    
    iss >> linha >> coluna;
    
    //pMundo->listaPosicao();
}
void Simulacao::guarda(istringstream &iss){
    
}

void Simulacao::muda(istringstream &iss){
    
}

void Simulacao::apaga(istringstream &iss){
    
}

void Simulacao::sair(istringstream &iss){
    delete pNinho;
    delete pFormigas;
    delete pMigalhas;
    delete pMundo;
}

int Simulacao::escolherComandoSimulacao(istringstream &iss){
    string comando;
    iss >> comando;
    for(int i=0; i<comandos.size(); i++){
        if(comando == comandos[i])
            return i;
    }
    return -1;
}




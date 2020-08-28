#include "Configuracao.h"
#include "Ninho.h"
#include "Mundo.h"
#include "Simulacao.h"
#include "Migalhas.h"
#include "Consola.h"

Configuracao::Configuracao(){
    pMigalhas = nullptr;
    pMundo = nullptr;
    pNinho = nullptr;
    trataMenuConfiguracao(); 
}

int Configuracao::apresentarMenuConfiguracao(){
   int opcaoMenu, flagMenu=0;
   
    do{
        Consola::clrscr();
        Consola::gotoxy(2, 2);
        cout<<"MENU:\n";
        cout<<"\t1-defmundo <limite>\n";
        cout<<"\t2-defen <energia>\n";
        cout<<"\t3-defpc <valor>\n";
        cout<<"\t4-defvt <valor>\n";
        cout<<"\t5-defmi <valor de 0 a 100>\n";
        cout<<"\t6-defme <energia>\n";
        cout<<"\t7-defnm <max>\n";
        cout<<"\t8-executa <nomeFicheiro>\n";
        cout<<"\t9-inicio\n";
        cout<<"\t0-Sair\n";
        cout<<"\nEscolha a opcao: ";
        cin>>opcaoMenu;
        cout<<"\n\n";

        if(opcaoMenu==0 || opcaoMenu==1 || opcaoMenu==2 || opcaoMenu==3 || opcaoMenu==4 || opcaoMenu==5 || opcaoMenu==6 
                || opcaoMenu==7 || opcaoMenu==8 || opcaoMenu==9)
            flagMenu=1;
    }while(!flagMenu);

    return opcaoMenu; 
}

void Configuracao::trataMenuConfiguracao(){
    int escolhaMenuConfiguracao=0;
    
    while(1){
        escolhaMenuConfiguracao = apresentarMenuConfiguracao();
        Consola::clrscr();
        switch(escolhaMenuConfiguracao)
        {
            case 0:
                exit(0);
                break;
            case 1: 
                Consola::clrscr();
                defmundo();
                break;
            case 2: 
                Consola::clrscr();
                defen();
                break;
            case 3: 
                Consola::clrscr();
                defpc();
                break;
            case 4: 
                Consola::clrscr();
                defvt();
                break;
            case 5: 
                Consola::clrscr();
                defmi();
                break;
            case 6: 
                Consola::clrscr();
                defme();
                break;
            case 7: 
                Consola::clrscr();
                defnm();
                break;
            case 8: 
                Consola::clrscr();
                executa();
                break;
            case 9: 
                Consola::clrscr();
                inicio();
                break;
                
        }          
    }
}

void Configuracao::defmundo(){
    
    int limite;
    
    do{
        cout << "Limite do mundo? " ;
        cin >> limite;
    }while(limite < 10); 
    
    if(pMundo == nullptr){
        Mundo* novoMundo = new Mundo("simulacao", 10);
        pMundo = novoMundo;
        pMundo->setNumLimite(limite);
    }
    else
        pMundo->setNumLimite(limite);  
}

void Configuracao::defen(){
    int energia;
    
    cout << "Valor inicial da energia dos ninhos? ";
    cin >> energia;
   
    if(pNinho == nullptr){
        Ninho* novoNinho = new Ninho(10, 10);
        pNinho = novoNinho;
        pNinho->setEnergiaInicial(energia);
    }
    else
        pNinho->setEnergiaInicial(energia);
}

void Configuracao::defpc(){
    int valor;
    
    cout << "Valor da energia inicial a partir do qual o ninho faz uma formiga? ";
    cin >> valor;
    
    if(pNinho == nullptr){
        Ninho* novoNinho = new Ninho(10, 10);
        pNinho = novoNinho;
        pNinho->setCriarFormiga(valor);
    }
    else
       pNinho->setCriarFormiga(valor);
}

void Configuracao::defvt(){
    int valor;
    
    cout << "Numero de unidades de energia transferidas entre o ninho e formiga por iteracao? ";
    cin >> valor;
    
    if(pNinho == nullptr){
        Ninho* novoNinho = new Ninho(10, 10);
        pNinho = novoNinho;
        pNinho->setTransferirEnergiaNinhoFormiga(valor);
    }
    else
       pNinho->setTransferirEnergiaNinhoFormiga(valor);
}

void Configuracao::defmi(){
    int valor_0_100;
    
    cout << "Percentagem inicial posicoes vazias que tem (inicialmente) migalhas? ";
    cin >> valor_0_100;
    
    if(pMigalhas == nullptr){
        Migalhas* novasMigalhas = new Migalhas(10, 10);
        pMigalhas = novasMigalhas;
        pMigalhas->setAcrescentarMigalhas(valor_0_100);  
    }
    else
       pMigalhas->setAcrescentarMigalhas(valor_0_100);    
}

void Configuracao::defme(){
    int energia;
    
    cout << "Energia inicial das novas migalhas? ";
    cin >> energia;
    
    if(pMigalhas == nullptr){
        Migalhas* novasMigalhas = new Migalhas(10, 10);
        pMigalhas = novasMigalhas;
        pMigalhas->setEnergiaInicialMigalhas(energia);
    }
    else
       pMigalhas->setEnergiaInicialMigalhas(energia);
}

void Configuracao::defnm(){
    int max;
    
    cout << "Numero maximo de migalhas a serem criadas a cada instante? ";
    cin >> max;
    
    if(pMigalhas == nullptr){
        Migalhas* novasMigalhas = new Migalhas(10, 10);
        pMigalhas = novasMigalhas;
        //sortear o numero de migalhas novas entre 0 e max
        pMigalhas->setMaxMigalhas(max);
    }
    else
       //sortear o numero de migalhas novas entre 0 e max
        pMigalhas->setMaxMigalhas(max);
}

void Configuracao::executa(){
    string nomeFicheiro;
    
    cout << "Nome do Ficheiro para executar? ";
    cin >> nomeFicheiro;
    
    if (lerComandosDeFicheiroDeTexto(nomeFicheiro)) {
                    cout << " Ficheiro lido com sucesso\n";
                } else {
                    cout << " Erro ao ler o ficheiro\n";
                }    
}

void Configuracao::inicio(){
    if(pMundo->getNumLimite() != 0){
        //if(ninho->getEnergiaInicial() != 0){
            //if(migalhas->getEnergiaInicialMigalhas() != 0){
                int limite = pMundo->getNumLimite();
                if(pMundo == nullptr)
                    Mundo *novoMundo = new Mundo("Simulacao", limite);
                else{
                    Simulacao *simulacao = new Simulacao(pMundo, pNinho, pMigalhas);
                    system("sleep 3");
                    Consola::clrscr();
                    simulacao->leComando();
                }
            //}
           // else
               // cout << "Nao foi preenchida a energia inicial das migalhas!\n";
        //}
        //else
          //  cout << "Nao foi preenchida a energia inicial dos ninhos!\n";
    }
    else
        cout << "Nao foi preenchida a dimensao do mundo!\n";
}

bool Configuracao::lerComandosDeFicheiroDeTexto(string nomeFicheiro){
    ifstream dados(nomeFicheiro);
    string linha;

    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        
        interpretaLinha(linha);
    }
    dados.close();
    return true;
}

void Configuracao::interpretaLinha(string linha) {
    
    istringstream iss(linha);
    string nome;
    int valor;
    
    iss >> nome >> valor;

    if (iss) {
        escreverDadosComandos(nome, valor);
    }
}

void Configuracao::escreverDadosComandos(string nome, int valor){
    if (nome == "defmundo"){
        if(pMundo == nullptr){
        Mundo* novoMundo = new Mundo("simulacao", 10);
        pMundo = novoMundo;
        pMundo->setNumLimite(valor);
        }
        else
            pMundo->setNumLimite(valor);
    }
    if (nome == "defen"){
        if(pNinho == nullptr){
        Ninho* novoNinho = new Ninho(10, 10);
        pNinho = novoNinho;
        pNinho->setEnergiaInicial(valor);
        }
        else
            pNinho->setEnergiaInicial(valor);
    }
    if (nome == "defpc"){
        if(pNinho == nullptr){
        Ninho* novoNinho = new Ninho(10, 10);
        pNinho = novoNinho;
        pNinho->setCriarFormiga(valor);
        }
        else
           pNinho->setCriarFormiga(valor);
    }
    if (nome == "defvt"){
        if(pNinho == nullptr){
        Ninho* novoNinho = new Ninho(10, 10);
        pNinho = novoNinho;
        pNinho->setTransferirEnergiaNinhoFormiga(valor);
        }
        else
           pNinho->setTransferirEnergiaNinhoFormiga(valor);
    }
    if (nome == "defmi"){
        if(pMigalhas == nullptr){
        Migalhas* novasMigalhas = new Migalhas(10, 10);
        pMigalhas = novasMigalhas;
        pMigalhas->setAcrescentarMigalhas(valor);  
        }
        else
           pMigalhas->setAcrescentarMigalhas(valor); 
    }
    if (nome == "defme"){
        if(pMigalhas == nullptr){
        Migalhas* novasMigalhas = new Migalhas(10, 10);
        pMigalhas = novasMigalhas;
        pMigalhas->setEnergiaInicialMigalhas(valor);
        }
        else
           pMigalhas->setEnergiaInicialMigalhas(valor);
    }
    if (nome == "defnm"){
        if(pMigalhas == nullptr){
        Migalhas* novasMigalhas = new Migalhas(10, 10);
        pMigalhas = novasMigalhas;
        //sortear o numero de migalhas novas entre 0 e max
        pMigalhas->setMaxMigalhas(valor);
        }
        else
           //sortear o numero de migalhas novas entre 0 e max
            pMigalhas->setMaxMigalhas(valor);
    }
    if (nome == "inicio"){
        if(pMundo->getNumLimite() != 0){
            //if(pNinho->getEnergiaInicial() != 0){
                //if(pMigalhas->getEnergiaInicialMigalhas() != 0){
                    int limite = pMundo->getNumLimite();
                    if(pMundo == nullptr)
                        Mundo *novoMundo = new Mundo("Simulacao", limite);
                    else{
                        Simulacao *simulacao = new Simulacao(pMundo, pNinho, pMigalhas);
                        system("sleep 4");
                        Consola::clrscr();
                        simulacao->leComando();
                    }
                //}
                //else
                   // cout << "Nao foi preenchida a energia inicial das migalhas!\n";
            //}
            //else
               // cout << "Nao foi preenchida a energia inicial dos ninhos!\n";
        }
        else
            cout << "Nao foi preenchida a dimensao do mundo!\n";
    }
}

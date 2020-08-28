#include "Interface.h"
#include "Configuracao.h"
#include "Consola.h"

void Interface::trataMenuPrincipal(){
    int escolhaMenuPrincipal=0, escolherComandoConfiguracao=0;
    
    while(1){
        escolhaMenuPrincipal = apresentarMenuPrincipal();
        switch(escolhaMenuPrincipal)
        {
            case 0:
                exit(0);
                break;
                
            case 1: 
                Configuracao *configuracao = new Configuracao();
                break;
        }          
    }
}

int Interface::apresentarMenuPrincipal(){
    
    int opcaoMenu, flagMenu=0;
    
    Consola::clrscr();
    Consola::gotoxy(2, 2);
    cout<<"\tTRABALHO PRATICO DE PROGRAMACAO ORIENTADA A OBJETOS - 2017\n\n";
    cout<<"\tELIANA FERNANDES E MARIO PIRES\t\tDATA: " <<__DATE__<<endl;
    cout<<"\t\t\t\t\t\tHORA: "<<__TIME__<<"\n\n\n\n";


    cout<<"\t======================================================\n";
    cout<<"\t\tSIMULACAO DE POPULACOES DE FORMIGAS  \n";
    cout<<"\t======================================================\n\n\n";
    do{
        cout<<"MENU:\n";
        cout<<"\t1-Fase de Configuracao\n";
        cout<<"\t0-Sair\n";
        cout<<"\nEscolha a opcao: ";
        cin>>opcaoMenu;
        cout<<"\n\n";

        if(opcaoMenu==0 || opcaoMenu==1 )
            flagMenu=1;
    }while(!flagMenu);

    return opcaoMenu;
}



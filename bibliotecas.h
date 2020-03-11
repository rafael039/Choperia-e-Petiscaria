#include<iostream>//cout e cin
#include "controleFuncionarios.h"

#include <string.h>//strcmp,strcpy
#include<conio2.h>//gotoxy e sleep
#include<windows.h>//system
#include<stdio.h>//fflush
#include<time.h>//horas


#define TAM 5
/*
using namespace std;

void logo();
void cadFunc(struct cadastro varParametro[]);
int telaEntrada();
int buscaFuncionario(char cpf[], int senha, int &verificaCadastro, int &verificaId);
int telaBloqueioTemporario(int &tentativas);


// ABAS DOS FUNCIONARIOS
void garcom(int id);

void caixa();
int acaoOpcao(int selecionaOpcao, int &verificaAcao, int id);

void dadosFuncionarios(int id);
void listarFuncionarios();
int buscaCpf();
int buscaNome();
void listarFuncionarios(int i,int cont);
void procuraFuncionario();
int controleFuncionario ();

double cardapio();
void selecionarMesa(int id);

// BORDAS E LAYOUTS
void bordaPadraoFunc();
void bordaDadosFuncionarios();
void bordaSelecionaMesas();


//-------------------------------------------------------------------------------
                    //  LOGO DA CHOPPERIA
//-------------------------------------------------------------------------------

/*
//-------------------------------------------------------------------------------
                    //  QUADRO DE FUNCIONARIOS
//-------------------------------------------------------------------------------

                    //  CADASTRO DE FUNCIONARIOS

struct cadastro funcionarios[TAM];
void cadFunc(struct cadastro varParametro[]){
      //id =1 : garçom
      //id =2 : caixa
      //FAZER POR REFERENCIA
      //funcionario 1
        strcpy(varParametro[1].nome,"Luiz Carlos");
        strcpy(varParametro[1].sobrenome,"Costa Moitinho");
        strcpy(varParametro[1].cpf,"07462030552");
        strcpy(varParametro[1].cargo,"Garcom");
        strcpy(varParametro[1].telefone,"99 9999 9999");
        varParametro[1].salario=1500.00;
        varParametro[1].comissao=0;
        varParametro[1].idade =20;
        varParametro[1].id = 1;
        varParametro[1].senha=12345;

        //funcionario 2
        strcpy(varParametro[2].nome,"Rafael");
        strcpy(varParametro[2].sobrenome,"Silveira");
        strcpy(varParametro[2].cpf,"12312312312");
        strcpy(varParametro[2].cargo,"Caixa");
        strcpy(varParametro[2].telefone,"99 9999 9999");
        varParametro[2].salario=1300.00;
        varParametro[2].comissao=0;
        varParametro[2].idade =23;
        varParametro[2].id = 2;
        varParametro[2].senha=54321;

    // funcionario 3
        strcpy(varParametro[3].nome,"Isac");
        strcpy(varParametro[3].sobrenome,"Silva");
        strcpy(varParametro[3].cpf,"12312312313");
        strcpy(varParametro[3].telefone,"99 9999 9999");
        strcpy(varParametro[3].cargo,"Garcom");
        varParametro[3].salario=1500.00;
        varParametro[3].comissao=0;
        varParametro[3].idade =20;
        varParametro[3].id = 3;
        varParametro[3].senha=29876;

}
*/

/*
                        //TELA ENTRADA
int id,tentativas=0;

int telaEntrada(){
    logo();
    cadFunc(funcionarios);// VER ISSO AQUI!! A REFERENCIA NAO FUNCIONA
    int opcaoSeguranca=2,verificaCadastro=0,verificaId,posicao;
    char cpf[12];
    int senha;
      //ver o tempo de acesso
          do{


               //exibe opcoes para acessar o programa interno

                gotoxy(37,4);
                cout<<"LOGIN";
                gotoxy(30,6);
                cout<<"CPF   : ";
                gotoxy(30,8);
                cout<<"SENHA : ";

                gotoxy(39,6);
                cin>>cpf;
                gotoxy(39,8);
                cin>>senha;

                fflush(stdin);

                //pega a posicao do vetor do funcionario
                posicao = buscaFuncionario(cpf,senha,verificaCadastro,verificaId);
                if (verificaCadastro==1){
                      system("cls");
                      opcaoSeguranca=0;

                      if (strcmp(funcionarios[posicao].cargo,"Garcom")==0){
                         id=verificaId;
                         garcom(verificaId);
                      }
                      else{
                          id=verificaId;
                          caixa();
                      }
                }
                else{
                  gotoxy(30,10);
                  cout<<"Restam "<<opcaoSeguranca<<" tentativas"<<endl<<endl;
                  system("pause");
                  system("cls");
                  if (opcaoSeguranca==0){
                      telaBloqueioTemporario(tentativas);
                  }
                }
                opcaoSeguranca--;
          }while(opcaoSeguranca>=0);

      cout<<"\n\n\n";
      return 0;
}
*/
                             //VALÍDA FUNCIONARIO

/*
int buscaFuncionario(char cpf[], int senha, int &verificaCadastro, int &verificaId){
  int i,posicao=-1;
  for (i=1;i<5;i++){
      if ( (strcmp(funcionarios[i].cpf , cpf)==0) && (funcionarios[i].senha==senha)){
            verificaCadastro++;
            posicao=i;
            verificaId = funcionarios[i].id;

      }
  }
  return posicao;

}
*/
int buscaFuncionario(char cpf[],int& cont){
  cadFunc(funcionarios);

  int i,posicao=-1;
      for (i=1,cont=0;i<5;i++){
          if ( (strcmp(funcionarios[i].cpf , cpf)==0)){
                posicao=i;
                cont++;
          }
      }
      return posicao;
}

                              //TELA BLOQUEIO

int telaBloqueioTemporario(int &tentativas){
  int tempo;
  if (tentativas <1){
      for(tempo=5;tempo>=0;tempo--){
        gotoxy(4,9);
        cout<<"Voce excedeu o limite de tentativas! Aguarde ate que possa tentar novamente";
        gotoxy(32,11);
        cout<<"Tempo restante : "<<tempo;
        Sleep(1000);
        system("cls");
      }
      tentativas++;
      telaEntrada();
  }
  else{
    gotoxy(4,12);
    cout<<"O usuario nao pode mais tentar entrar no sistema, contate um dos gerentes!"<<endl;
  }
}
                            // DADOS DOS FUNCIONARIOS
void dadosFuncionarios(int id){
      char horas[1];
      _strtime(horas);
      gotoxy(2,4);
      cout<<"Hora entrada: "<<horas;
      gotoxy(2,5);
      cout<<"Nome  : "<<funcionarios[id].nome<<" "<< funcionarios[id].sobrenome<<endl;
      gotoxy(2,6);
      cout<<"CPF   : "<<funcionarios[id].cpf<<endl;
      gotoxy(2,7);
      cout<<"Cargo : "<<funcionarios[id].cargo<<endl;

}



//-------------------------------------------------------------------------------
                            // GARÇOM
//-------------------------------------------------------------------------------


void garcom(int id){

     logo();
     //dados funcionario
     bordaDadosFuncionarios();
     dadosFuncionarios(id);
     bordaSelecionaMesas();
     selecionarMesa(id);
}

//-------------------------------------------------------------------------------
                            // CAIXA
//-------------------------------------------------------------------------------

void caixa(){
   int selecionaOpcao,verificaAcao=1;
      logo();
      bordaDadosFuncionarios();
      dadosFuncionarios(id);
      bordaPadraoFunc();

      gotoxy(17,9);
      cout<<"CAIXA";

      gotoxy(5,12);
      cout<<"#1 VIZUALIZAR MESAS"; //chama uma função que exibe as mesas

      gotoxy(5,13);
      cout<<"#2 EFETUAR PAGAMENTO";//efetua o pagamento da conta e libera a mesa

      gotoxy(5,14);
      cout<<"#3 CONTROLE DE FUNCIONARIOS";//exibe o relatorio de funcionarios
       gotoxy(5,15);
      cout<<"#4 SAIR DO SISTEMA";//exibe o relatorio de funcionarios

      gotoxy(8,18);
      cout<<"# Digite a opcao : ";
      cin>>selecionaOpcao;
      acaoOpcao(selecionaOpcao,verificaAcao,id);

}
          // CONFERE A OPCAO SELECIONADA

int acaoOpcao(int selecionaOpcao, int &verificaAcao,int id){
     char confirmaSaidaPrograma;
      do{
      switch (selecionaOpcao){
        case 1:
          bordaSelecionaMesas();
          selecionarMesa(id);
          verificaAcao=1;
        break;
        case 2:
          verificaAcao=1;

        break;
        case 3:
          verificaAcao=1;
          system("cls");
          controleFuncionario();
        break;
        case 4:
          verificaAcao=1;
          gotoxy(5,21);
          cout<<"Deseja realmente sair [s / n] ? ";
          cin>>confirmaSaidaPrograma;
          if (confirmaSaidaPrograma=='s' || confirmaSaidaPrograma=='S'){
              system("cls");
              telaEntrada();
          }
        break;

        default:
          verificaAcao=0;
          cout<<"A opcao digitada e´ invalida";
          system("pause");
      }
      system("cls");

    }while(verificaAcao==0 || (confirmaSaidaPrograma=='n' || confirmaSaidaPrograma=='N') );

}

                            // CONTROLE DE FUNCIONARIOS


int controleFuncionario (){

  int opcaoPesquisa,verificacao=1;
  do{
      cadFunc(funcionarios);
      gotoxy(28,1);
      cout<<"CONTROLE DE FUNCIONARIOS\n";
      gotoxy(29,3);
      cout<<"#1 LISTAR FUNCIONARIOS \n";
      gotoxy(29,4);
      cout<<"#2 BUSCA ESPECIFICA \n";
      gotoxy(29,6);
      cout<<"Selecione uma opcao: ";
      cin>>opcaoPesquisa;
        switch(opcaoPesquisa){
          case 1:
            system("cls");
            listarFuncionarios();
          break;
          case 2:
            system("cls");
            procuraFuncionario();
          break;
          default:
            cout<<"Opcao digitada e´ invalida! tente novamente!";
            system("pause");
            verificacao=0;

      }
    }while(verificacao==0);
}
void procuraFuncionario(){
  int opcaoSelecionada,verificacao=1;
  do{
      fflush(stdin);
      gotoxy(28,1);
      cout<<"CONTROLE DE FUNCIONARIOS\n";
      gotoxy(28,3);
      cout<<"\n#1 CPF\n";
      //cout<<"#2 Nome\n";
      cin>>opcaoSelecionada;
      switch(opcaoSelecionada){
        case 1:
            buscaCpf();
        break;
        case 2:
           // buscaNome();
        break;
        default:
            cout<<"Opcao digitado e´ invalida, tente novamente!\n";
            system("pause");
            verificacao=0;
      }


  }while(verificacao==0);
}
/*
int buscaNome(){
  char nomeFuncionario[20];
  int posicao[TAM],i;
  cout<<"\nInforme o nome do funcionario : ";
  cin>>nomeFuncionario;
  for (i=1;i<5;i++){
        if ( (strcmp(funcionarios[i].nome , nomeFuncionario)<=0)){
            posicao[TAM]=i;
        }
  }
  if (posicao==-1){
      cout<<"Funcionario nao cadastrado!";
  }
  else{
      listarFuncionarios(posicao);
  }
  system("cls");


}*/

int buscaCpf(){
  char cpfFuncionario[12];
  int posicao,cont;
  cout<<"\nInforme o cpf do funcionario : ";
  cin>>cpfFuncionario;
  posicao = buscaFuncionario(cpfFuncionario,cont);
    system("cls");
    listarFuncionarios(posicao,cont);


}
void listarFuncionarios(int posicao,int cont){
      int j,k=4,l=4,m,opcaoSelecionada;
      for (m=0;m<cont;m++){
           gotoxy(28,1);
          cout<<"CONTROLE DE FUNCIONARIOS\n";
          for(j=1;j<=1;j++){
            gotoxy(1,l++);
            cout<<"NOME    : "<<funcionarios[posicao].nome<<" "<<funcionarios[posicao].sobrenome<<endl;
            gotoxy(1,l++);
            cout<<"CARGO   : "<<funcionarios[posicao].cargo<<endl;
            gotoxy(1,l++);
            cout<<"SALARIO : "<<funcionarios[posicao].salario <<endl;
            gotoxy(1,l++);
            cout<<"COMISSAO: "<<funcionarios[posicao].comissao<<endl;
            //do outro lado
            gotoxy(50,k++);
            cout<<"DATA NASCIMENTO : ";
            gotoxy(50,k++);
            cout<<"IDADE           : "<<funcionarios[posicao].idade;
            gotoxy(50,k++);
            cout<<"CPF             : "<<funcionarios[posicao].cpf;
            gotoxy(50,k++);
            cout<<"TELEFONE        : "<<funcionarios[posicao].telefone;
            gotoxy(50,k++);
            cout<<"DATA DE ENTRADA : \n";
         }
           for (j=1;j<=80;j++){
            gotoxy(j,k);
            cout<<"-";
           }
                cout<<"#1 VOLTAR AO CONTROLE DE FUNCIONARIO"<<endl;
  //cout<<"#2 PARA ALTERAR DADO DO FUNCIONARIO"<<endl;
  cout<<"#2 PARA VOLTAR AO CAIXA"<<endl;
  cin>>opcaoSelecionada;
    switch(opcaoSelecionada){
        case 1:
            system("cls");
            controleFuncionario();

        break;
        case 2:
           system("cls");
           caixa();
        break;

    }

  }

}


void listarFuncionarios(){
  gotoxy(28,1);
  cout<<"CONTROLE DE FUNCIONARIOS\n";
  int i,j,k=4,l=6,opcaoSelecionada;
  for (i=1;i<4;i++){
      for(j=1;j<=1;j++){
        gotoxy(1,l);
        cout<<"NOME    : "<<funcionarios[i].nome<<" "<<funcionarios[i].sobrenome<<endl;
        gotoxy(1,l++);
        cout<<"CARGO   : "<<funcionarios[i].cargo<<endl;
        gotoxy(1,l++);
        cout<<"SALARIO : "<<funcionarios[i].salario <<endl;
        gotoxy(1,l++);
        cout<<"COMISSAO: "<<funcionarios[i].comissao<<endl;
        //do outro lado
        gotoxy(50,k++);
        cout<<"DATA NASCIMENTO : ";
        gotoxy(50,k++);
        cout<<"IDADE           : "<<funcionarios[i].idade;
        gotoxy(50,k++);
        cout<<"CPF             : "<<funcionarios[i].cpf;
        gotoxy(50,k++);
        cout<<"TELEFONE        : "<<funcionarios[i].telefone;
        gotoxy(50,k++);
        cout<<"DATA DE ENTRADA : \n";
      }
    }
    for (j=1;j<=80;j++){
        gotoxy(j,k);
        cout<<"-";
    }
     k++;
     l++;
      cout<<"#1 VOLTAR AO CONTROLE DE FUNCIONARIO"<<endl;
      //cout<<"#2 PARA ALTERAR DADO DO FUNCIONARIO"<<endl;
      cout<<"#2 PARA VOLTAR AO CAIXA"<<endl;
      cin>>opcaoSelecionada;
        switch(opcaoSelecionada){
            case 1:
                system("cls");
                controleFuncionario();

            break;
            case 2:
               system("cls");
               caixa();
            break;

      }

}





//-------------------------------------------------------------------------------
                            // CARDAPIO
//-------------------------------------------------------------------------------




double cardapio(){
  logo();
  //menu de opcoes
  gotoxy(16,9);
	printf("CARDAPIO\n");
	gotoxy(3,11);
	printf(" [1] - Bebidas\n");
	gotoxy(3,12);
	printf(" [2] - Entradas\n");
	gotoxy(3,13);
	printf(" [3] - Sobremesas\n");
	gotoxy(3,14);
	printf(" [4] - Lanches\n");
	gotoxy(3,15);
	printf(" [5] - Massas\n");
	gotoxy(3,16);
	printf(" [6] - Refeicoes\n");
	gotoxy(3,17);
	printf(" [7] - Prato da Casa");
}
//-------------------------------------------------------------------------------
                            // MESAS
//-------------------------------------------------------------------------------
void selecionarMesa(int id){
    bordaSelecionaMesas();
    int selecionaMesa;
            gotoxy(60,4);
            cout <<"MESAS";
            gotoxy(52,6);
            cout<<"NUMERO";
            gotoxy(67,6);
            cout<<"STATUS";

            //todas as mesas:
              //nomes
               gotoxy(54,8);
               cout<<" 1 ";
               gotoxy(54,9);
               cout<<" 2 ";
               gotoxy(54,10);
               cout<<" 3 ";
               gotoxy(54,11);
               cout<<" 4 ";
               gotoxy(54,12);
               cout<<" 5 ";
             //status
              gotoxy(67,8);
              cout<<"LIVRE";
              gotoxy(67,9);
              cout<<"LIVRE";
              gotoxy(67,10);
              cout<<"LIVRE";
              gotoxy(67,11);
              cout<<"LIVRE";
              gotoxy(67,12);
              cout<<"LIVRE";

              //liberar, abrir.

              gotoxy(50,19);
              cout<<"OBS: Digite '2' a qualquer";
              gotoxy(50,20);
              cout<<" momento para sair!";

              gotoxy(52,14);
              cout<<"# ACESSAR MESA NUM: ";
              cin>>selecionaMesa;
              if (selecionaMesa==2)
                  system("cls");
                  if (id==1)
                      garcom();
                  else
                      caixa();


}


//-------------------------------------------------------------------------------
                            // LAYOUTS E TABELAS
//-------------------------------------------------------------------------------
/*
void bordaPadraoFunc(){
  int i,j;
  for (i=1;i<40;i++){
      //cabeçalho MENU
      gotoxy(i,8);
      //delimita o fim da linha do cabeçalho
      cout<<"-";
      gotoxy(i,10);

      cout<<"-";
      //fecha a parte inferior da tabela
      gotoxy(i,19);
      cout<<"-";
      for(j=8;j<20;j++){
          gotoxy(1,j);
          cout<<"|";
          gotoxy(40,j);
          cout<<"|";

      }

  }
}

void bordaDadosFuncionarios(){
  int i,j;
  for (i=1;i<40;i++){
      gotoxy(i,3);
      cout<<"-";
      gotoxy(i,8);
      cout<<"-";
      for(j=3;j<9;j++){
          gotoxy(1,j);
          cout<<"|";
          gotoxy(40,j);
          cout<<"|";



      }
  }

}

void bordaSelecionaMesas(){
  int i,j;

  for (i=50;i<=74;i++){
      //borda cabeçalho
      gotoxy(i,3);
      cout<<"-";
      //borda total
        gotoxy(i,5);
        cout<<"-";
        gotoxy(i,18);
        cout<<"-";
      for (j=3;j<=18;j++){
        //bordas dos lados

          gotoxy(50,j);
          cout<<"|";
          gotoxy(74,j);
          cout<<"|";



      }

  }
}








*/

*/


#include<iostream>
#include<string.h>
#include<windows.h>//system
#include<stdio.h>


#define QTDFUNC 4
using namespace std;
cadastro funcionarios[QTDFUNC];



int pesquisaFuncionarios();
void relacaoFuncionario(char cpf[],int &status,int &posicao);
void dadosFuncionarios(int posicao);

void buscaNome();
int buscaCpf();

int listarFuncionarios(int i);
int listarFuncionarios();

namespace cadastros{
    void cadFunc(cadastro varParametro[]){
          //funcionario 1
            strcpy(varParametro[1].nome,"Luiz Carlos");
            strcpy(varParametro[1].sobrenome,"Costa Moitinho");
            strcpy(varParametro[1].cpf,"07462030552");
            strcpy(varParametro[1].cargo,"Garcom");
            strcpy(varParametro[1].telefone,"99 9999 9999");
            varParametro[1].salario=1500.00;
           // varParametro[1].comissao=0;
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
           // varParametro[2].comissao=0;
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
            //varParametro[3].comissao=0;
            varParametro[3].idade =20;
            varParametro[3].id = 1;
            varParametro[3].senha=29876;

    }
}

namespace funcionario{
void relacaoFuncionario(char cpf[], int senha,int &id, int &posicao,int &status){
    int i;
    for (i=1;i<QTDFUNC;i++){
        if ( (strcmp(funcionarios[i].cpf , cpf)==0) && (funcionarios[i].senha==senha)){
              id= funcionarios[i].id;
              posicao=i;
              status++;
        }
    }
  }
}

//busca a posicao do funcionario
void relacaoFuncionario(char cpf[],int &status,int &posicao){
  int i;
  for (i=1;i<QTDFUNC;i++){
      if (strcmp(funcionarios[i].cpf , cpf)==0){
            posicao=i;
            status++;
      }
  }
}


void dadosFuncionarios(int posicao){
      char horas[1];
      _strtime(horas);
      gotoxy(21,5);
      cout<<"Hora  : "<<horas;
      gotoxy(21,6);
      cout<<"Nome  : "<<funcionarios[posicao].nome<<" "<< funcionarios[posicao].sobrenome<<endl;
      gotoxy(21,7);
      cout<<"CPF   : "<<funcionarios[posicao].cpf<<endl;
      gotoxy(21,8);
      cout<<"Cargo : "<<funcionarios[posicao].cargo<<endl;
}

int pesquisaFuncionarios(){
  int opcaoPesquisa;
  logoPrincipal();
  do{
      criaMenu(3,70,4,5,BLACK,WHITE);
      gotoxy(30,6);
      cout<<"CONTROLE DE FUNCIONARIOS\n";
      criaMenu(12,70,4,9,WHITE,BLACK);
      gotoxy(20,10);
      cout<<"1 - Listar todos os funcionários \n";
      gotoxy(20,12);
      cout<<"2 - Busca específica de funcionários \n";
      gotoxy(20,14);
      cout<<"3 - Voltar ao caixa \n";
      gotoxy(20,16);
      cout<<"Selecione uma opcao: ";
      cin>>opcaoPesquisa;
      if (opcaoPesquisa<1 || opcaoPesquisa>3 ){
         gotoxy(20,18);
         textcolor(COR_ALERTA);
         cout<<"Opção digitada é inválida!";
         Sleep(1000);
         gotoxy(20,18);
         clreol();
         gotoxy(20,116);
         clreol();
         fflush(stdin);
         textcolor(COR_LETRA);
       }
      }while(opcaoPesquisa!=1 && opcaoPesquisa!=2 &&  opcaoPesquisa!=3);

      switch(opcaoPesquisa){
          case 1:
            system("cls");
            listarFuncionarios();
          break;
          case 2:
            system("cls");
            buscaCpf();
          break;
          case 3:
            //retorna ao menu
            return 1;
          break;
      }
}
//busca personalizada
int buscaCpf(){
 char cpfFuncionario[12];
  int posicao,status=0;
  do{
      logoPrincipal();
      criaMenu(3,79,1,5,BLACK,WHITE);
      gotoxy(25,6);
      cout<<"BUSCA PERSONALIZADA DE FUNCIONARIOS\n";
      criaMenu(4,79,1,9,WHITE,BLACK);
      gotoxy(20,10);
      cout<<">> Informe o cpf do funcionario : ";
      cin>>cpfFuncionario;
       relacaoFuncionario(cpfFuncionario,status,posicao);
      if(status==0){
        gotoxy(30,12);
        textcolor(COR_ALERTA);
        cout<<"CPF digitado é inválido!";
        Sleep(1000);
        system("cls");
      }
      else{
        clrscr();
        return listarFuncionarios(posicao);
      }
  }while(status==0);
}

//sobrecarga
int listarFuncionarios(){
    int i,j,c,l,opcaoSelecionada;

    do{
        logoPrincipal();
      c=11,l=11;
      criaMenu(3,79,1,5,BLACK,WHITE);
      gotoxy(30,6);
      cout<<"LISTAGEM DE FUNCIONARIOS\n";
      for (i=1;i<4;i++){
      criaMenu(4,79,1,l-1,COR_DETALHE,WHITE);
          for(j=1;j<=1;j++){
            gotoxy(4,l++);
            cout<<"NOME    : "<<funcionarios[i].nome<<" "<<funcionarios[i].sobrenome<<endl;
            gotoxy(4,l++);
            cout<<"CARGO   : "<<funcionarios[i].cargo<<endl;
            gotoxy(4,l++);
            cout<<"SALARIO : "<<funcionarios[i].salario <<endl;
            gotoxy(50,c++);
            cout<<"IDADE           : "<<funcionarios[i].idade;
            gotoxy(50,c++);
            cout<<"CPF             : "<<funcionarios[i].cpf;
            gotoxy(50,c++);
            cout<<"TELEFONE        : "<<funcionarios[i].telefone;
          }
            l+=4;
            c+=4;
      }
      criaMenu(4,80,1,l-1,WHITE,BLACK);
      gotoxy(21,l+1);
      cout<<"1 - Voltar ao controle de funcionários";
      gotoxy(21,l+2);
      cout<<"2 - Voltar ao Caixa"<<endl;
      gotoxy(21,l+3);
      cout<<">> Selecione uma opcao: ";
      cin>>opcaoSelecionada;
      if (opcaoSelecionada !=1 && opcaoSelecionada!=2){
          textcolor(COR_ALERTA);
          cout<<"Opção digitada é inválida!";
          Sleep(1000);
          system("cls");
          textcolor(COR_LETRA);
      }
    }while(opcaoSelecionada !=1 && opcaoSelecionada!=2);

        switch(opcaoSelecionada){
            case 1:
                system("cls");
                pesquisaFuncionarios();
            break;
            case 2:
                return 1;
            break;
        }
}

int listarFuncionarios(int i){
  int opcaoSelecionada;
   do{
        logoPrincipal();
        criaMenu(2,79,1,5,BLACK,WHITE);
        gotoxy(30,6);
        cout<<"LISTAGEM DE FUNCIONARIOS\n";
        criaMenu(6,79,1,9,COR_DETALHE,WHITE);
        gotoxy(1,12);
        cout<<"NOME    : "<<funcionarios[i].nome<<" "<<funcionarios[i].sobrenome<<endl;
        gotoxy(1,13);
        cout<<"CARGO   : "<<funcionarios[i].cargo<<endl;
        gotoxy(1,14);
        cout<<"SALARIO : "<<funcionarios[i].salario <<endl;
        gotoxy(50,12);
        cout<<"IDADE           : "<<funcionarios[i].idade;
        gotoxy(50,13);
        cout<<"CPF             : "<<funcionarios[i].cpf;
        gotoxy(50,14);
        cout<<"TELEFONE        : "<<funcionarios[i].telefone;
        criaMenu(8,79,1,16,WHITE,BLACK);
        gotoxy(20,17);
        cout<<"1- Controle de funcionários"<<endl;
        gotoxy(20,18);
        cout<<"2- Voltar ao Caixa"<<endl;
        gotoxy(20,21);
        cout<<">>Selecione uma opcao: ";
        cin>>opcaoSelecionada;
        if (opcaoSelecionada !=1 && opcaoSelecionada!=2){
          gotoxy(20,23);
          textcolor(COR_ALERTA);
          cout<<"Opcao digitada e invalida!";
          Sleep(1000);
          system("cls");
          textcolor(COR_LETRA);
       }
    }while(opcaoSelecionada!=1 && opcaoSelecionada!=2);
        switch(opcaoSelecionada){
            case 1:
              system("cls");
              pesquisaFuncionarios();
            break;
            case 2:
              return 1;
            break;
        }
}





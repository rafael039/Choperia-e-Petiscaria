#include<iostream>
#include<time.h>
#include<conio2.h>
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include <math.h>

#define COR_CABECALHO LIGHTRED
#define COR_CORPO LIGHTGRAY
#define COR_ALERTA LIGHTRED
#define COR_LETRA WHITE
#define COR_DETALHE CYAN


#include "layouts.h"
#include "struct.h"
#include "controleFunc.h"
using namespace funcionario;
#include "telaPrincipal.h"
#include "mesas.h"
#include "operacional.h"

using namespace std;

using namespace cadastros;

int main (){
    setlocale(LC_ALL,"portuguese");
    int id,posicao,conexao=0;
    cadFunc(funcionarios);
    dadosCardapio(mesa);
    do{
        textcolor(WHITE);
        textbackground(COR_CORPO);
        clrscr();
        telaEntrada(id,posicao);
        if(id==1){
         do{
            // tela do garcom
            system("cls");
            logoPrincipal();
            criaMenu(4,40,20,5,COR_DETALHE,COR_LETRA);
            dadosFuncionarios(posicao);
            conexao = garcom();
          }while(conexao==1);
        }
        else{
          do{
             system("cls");
             logoPrincipal();
             criaMenu(4,40,20,5,COR_DETALHE,COR_LETRA);
             dadosFuncionarios(posicao);
             conexao = caixa();

          }while(conexao==1);
           gotoxy(17,10);
           cout<<"CAIXA";
        }
          system("cls");
     }while(conexao==0);
   return 0;
}


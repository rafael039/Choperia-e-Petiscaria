int cardapioMesas(int opcaoMesa);
void dadosCardapio(Cardapio mesa[]);
int calculaPedido(int i,int opcaoMesa);
void listaPedidos(int indicePedido, int qtd,int opcaoMesa);
int listaPedidos(int opcaoMesa);
void listaPedidos(int opcaoMesa,int &linha);
int menuFinalizaCompra(int linha, int &saida,int opcaoMesa,int valorTotal);
void opcoesCardapio(int &saida);

//globais
Cardapio mesa[5];
int enumeraPedidos[6]={0,0,0,0,0,0};

int efetuaPagamento(){
  int opcaoMesa,linha,escolhaPagamento,saida=1;
  int opcaoCartao,parcelas,i;
  float desconto,valorTotal;
  do {
      system("cls");
      logoPrincipal();
      criaMenu(3,70,5,4,BLACK,WHITE);
      gotoxy(36,5);
      cout<<"PAGAMENTO";
      criaMenu(11,70,5,7,COR_LETRA,BLACK);
      gotoxy(20,8);
      cout<<"Informe o número da mesa: ";
      cin>>opcaoMesa;
      if (opcaoMesa<1 || opcaoMesa>4){
        gotoxy(20,9);
        cout<<"Número da mesa informada é inválido!";
        Sleep(1000);
        saida=0;
      }
      else if (enumeraPedidos[opcaoMesa]==0){
          criaMenu(4,60,10,10,WHITE,BLACK);
          gotoxy(20,11);
          textcolor(COR_CABECALHO);
          cout<<"Não há pedidos realizados por esta mesa!!\n\n";
          textcolor(BLACK);
          Sleep(2000);
          return 1;
      }
      else{
          criaMenu(11,70,5,7,WHITE,BLACK);
          linha=enumeraPedidos[opcaoMesa]+7;
          for (i=1;i<=enumeraPedidos[opcaoMesa];i++,linha++){
            criaMenu(10,70,5,linha++,COR_LETRA,BLACK);
            gotoxy(6,linha);
            cout<< mesa[opcaoMesa].pedidos[ mesa[opcaoMesa].listaCompras[i] ];
            gotoxy(40,linha);
            cout<<mesa[opcaoMesa].qtdPedidos[i];
            gotoxy(60,linha);
            cout<<"R$ "<<mesa[opcaoMesa].precos[ mesa[opcaoMesa].listaCompras[i] ];
            criaMenu(1,60,10,linha+1,WHITE,BLACK);
          }
          criaMenu(linha+10,70,5,linha+1,WHITE,BLACK);
          gotoxy(53,linha+2);
          textcolor(COR_ALERTA);
          cout<<"Preco Total: R$ "<<mesa[opcaoMesa].precoTotal;
          gotoxy(30,linha+3);
          textcolor(BLACK);
          cout<<"Formas de pagamento";
          gotoxy(20,linha+5);
          cout<<"1 - Dinheiro............7% de desconto";
          gotoxy(20,linha+6);
          cout<<"2 - Cartão..............2% de desconto débito";
          gotoxy(20,linha+7);
          cout<<">>Informe a forma de pagamento: ";
          cin>>escolhaPagamento;
          //dinheiro
          if (escolhaPagamento==1){
            desconto=mesa[opcaoMesa].precoTotal * 0.07;
            gotoxy(20,linha+9);
            cout<<"Valor total da consumação: "<< mesa[opcaoMesa].precoTotal;
            gotoxy(20,linha+11);
            valorTotal = mesa[opcaoMesa].precoTotal-desconto;
            cout<<"Valor com desconto: "<<valorTotal;
            return menuFinalizaCompra(linha,saida,opcaoMesa,valorTotal);
          //cartao
          }
         else if (escolhaPagamento==2){
            gotoxy(20,linha+13);
            cout<<"1- Débito......2% de desconto";
            gotoxy(20,linha+14);
            cout<<"2- Crédito.....ate 3x sem juros";
            gotoxy(20,linha+15);
            cout<<">>Selecione uma opção: ";
            cin>>opcaoCartao;
            if (opcaoCartao!=1 && opcaoCartao!=2)
                saida=0;
            else{
                switch(opcaoCartao){
                   case 1:
                      desconto=mesa[opcaoMesa].precoTotal * 0.02;
                      valorTotal =mesa[opcaoMesa].precoTotal-desconto;
                      gotoxy(20,linha+15);
                      cout<<"Valor total da consumação: "<< valorTotal;
                      return menuFinalizaCompra(linha,saida,opcaoMesa,valorTotal);
                    break;
                    case 2:
                      do{
                        gotoxy(20,linha+17);
                        cout<<"Quantas vezes deseja dividir a compra (até 3x): ";
                        cin>>parcelas;
                        if (parcelas<1 || parcelas>3){
                          gotoxy(25,linha+18);
                          cout<<"Número de parcelas é inválido!!";
                          Sleep(1000);
                          gotoxy(20,linha+17);
                          clreol();
                          gotoxy(20,linha+18);
                          clreol();
                        }
                        else{
                          gotoxy(20,linha+17);
                          valorTotal =mesa[opcaoMesa].precoTotal /parcelas;
                          cout<<"Valor parcelado : "<<parcelas<<" de "
                          << mesa[opcaoMesa].precoTotal;
                         return menuFinalizaCompra(linha,saida,opcaoMesa,valorTotal);

                        }
                      }while(parcelas<1 || parcelas>3);


                    break;


                }
            }
          }
      }
  }while(saida==0);

}
int menuFinalizaCompra(int linha, int &saida,int opcaoMesa,int valorTotal){
  int finalizaCompra,i;
  do {
        gotoxy(30,linha+21);
        cout<<"1 -  Para finalizar compra";
        gotoxy(30,linha+22);
        cout<<"2 -  Para retornar ao Caixa";
        gotoxy(30,linha+23);
        cout<<">> Informe a opção: ";
        cin>>finalizaCompra;
        if (finalizaCompra==1){
            system("cls");
            gotoxy(24,12);
            textcolor(BLACK);
            cout<<"Compra finalizada com sucesso!";
            Sleep(2000);
            enumeraPedidos[opcaoMesa]=0;
            valorTotal=0;
            mesa[opcaoMesa].precoTotal=0;
            mesa[opcaoMesa].status="LIVRE";
            for (i=1;i<enumeraPedidos[opcaoMesa];i++);
                mesa[opcaoMesa].listaCompras[i]=0;
            return 1;
        }
        else if (finalizaCompra==2)
            return 1;
        else{
            gotoxy(35,linha+15);
            cout<<"Opção digitada é inválida!";
            Sleep(1000);
            saida=0;
        }
        system("cls");
  }while(saida==0);
}




void listaPedidos(int indicePedido, int qtd,int opcaoMesa){
    int i=opcaoMesa;
        enumeraPedidos[i]++;
        //amazena o numero do pedido num vetor que é reservado para cada mesa
        mesa[i].listaCompras[ enumeraPedidos[i] ] = indicePedido;
        mesa[i].qtdPedidos[ enumeraPedidos[i] ]   = qtd;
}
void listaPedidos(int opcaoMesa,int &linha){
  int i;
   system("cls");
   logoPrincipal();
   criaMenu(3,79,1,4,BLACK,WHITE);
   gotoxy(28,5);
   cout<<"LISTAGEM DE PEDIDOS MESA : "<<opcaoMesa;
   criaMenu(3,79,1,7,COR_DETALHE,WHITE);
   gotoxy(5,8);
   cout<<"PEDIDOS";
   gotoxy(35,8);
   cout<<"QUANTIDADE";
   gotoxy(60,8);
   cout<<"PREÇO";
   for (i=1,linha=10;i<=enumeraPedidos[opcaoMesa];i++,linha++){
          criaMenu(i,70,4,linha+8,COR_LETRA,BLACK);
          gotoxy(5,linha);
          cout<< mesa[opcaoMesa].pedidos[ mesa[opcaoMesa].listaCompras[i] ];
          gotoxy(40,linha);
          cout<<mesa[opcaoMesa].qtdPedidos[i];
          gotoxy(60,linha);
          cout<<"R$ "<<mesa[opcaoMesa].precos[ mesa[opcaoMesa].listaCompras[i] ];
    }
    gotoxy(53,linha+2);
    cout<<"Preco Total: R$ "<<mesa[opcaoMesa].precoTotal;
}


int listaPedidos(int opcaoMesa){
  int opcaoSelecionada,i,linha;
   system("cls");
   logoPrincipal();
   criaMenu(3,70,4,5,BLACK,WHITE);
   gotoxy(28,6);
   cout<<"LISTAGEM DE PEDIDOS MESA : "<<opcaoMesa;
   criaMenu(3,70,4,8,COR_DETALHE,WHITE);
   gotoxy(5,9);
   cout<<"PEDIDOS";
   gotoxy(35,9);
   cout<<"QUANTIDADE";
   gotoxy(60,9);
   cout<<"PREÇO";
   //criaMenu(8,70,4,10,COR_LETRA,BLACK);
    if (enumeraPedidos[opcaoMesa]==0){
      criaMenu(4,70,4,10,WHITE,BLACK);
      gotoxy(20,11);
      textcolor(COR_CABECALHO);
      cout<<"Não há pedidos realizados por esta mesa!!\n\n";
      textcolor(BLACK);

      do{
        gotoxy(30,13);
        cout<<"Tecle 1 para voltar : ";
        cin>> opcaoSelecionada;
        if (opcaoSelecionada!=1){
              textcolor(COR_ALERTA);
              gotoxy(30,16);
              textcolor(COR_ALERTA);
              cout<<"Opção digitada é inválida!!";
              Sleep(1000);
              gotoxy(30,13);
              clreol();
              gotoxy(30,16);
              clreol();
              textcolor(BLACK);
              }
              else{
                return 1;
              }

          }while(opcaoSelecionada!=1);
    }
    else{
       criaMenu(enumeraPedidos[opcaoMesa]+8,70,4,11,COR_LETRA,BLACK);
       for (i=1,linha=12;i<=enumeraPedidos[opcaoMesa];i++,linha++){

              gotoxy(5,linha);
              cout<< mesa[opcaoMesa].pedidos[ mesa[opcaoMesa].listaCompras[i] ];
              gotoxy(40,linha);
              cout<<mesa[opcaoMesa].qtdPedidos[i];
              gotoxy(60,linha);
              cout<<"R$ "<<mesa[opcaoMesa].precos[ mesa[opcaoMesa].listaCompras[i] ];
          }

         gotoxy(50,linha+2);
         cout<<"Preco Total: R$ "<<mesa[opcaoMesa].precoTotal;
          do{
             gotoxy(30,linha+4);
             cout<<"Tecle 1 para voltar : ";
             cin>> opcaoSelecionada;
              if (opcaoSelecionada!=1){
                  textcolor(COR_ALERTA);
                  gotoxy(30,linha+5);
                  cout<<"Opção digitada é inválida!!";
                  Sleep(1000);
                  gotoxy(30,linha+4);
                  clreol();
                  gotoxy(30,linha+5);
                  clreol();
                 textcolor(BLACK);
              }
              else{
                return 1;

              }

          }while(opcaoSelecionada!=1);
    }
}

void dadosCardapio(Cardapio mesa[]){
        int i;
        for (i=1;i<=4;i++){
            mesa[i].pedidos[1] = "Escondidinho de Bacalhau";
                mesa[i].precos[1] = 12;
            mesa[i].pedidos[2] = "Estrogonofe.............";
                mesa[i].precos[2] = 11;
            mesa[i].pedidos[3] = "Filé à Parmegiana.......";
                mesa[i].precos[3] = 15;
            mesa[i].pedidos[4] = "Picanha.................";
                mesa[i].precos[4] = 20;
            mesa[i].pedidos[5] = "Risoto de camarão.......";
                mesa[i].precos[5] = 12;
            mesa[i].pedidos[6] = "Amendoim................";
                mesa[i].precos[6] = 2;
            mesa[i].pedidos[7] = "Mandioca Frita..........";
                mesa[i].precos[7] = 5;
            mesa[i].pedidos[8] = "Batata Frita............";
                mesa[i].precos[8] = 3;
           //preco de bebidas
            mesa[i].pedidos[10]= "Água...................500 ml ";
                 mesa[i].precos[10] = 3.00;
            mesa[i].pedidos [11]= "Água de coco..........        ";
                  mesa[i].precos[11] = 5.00;
            mesa[i].pedidos [12]= "Chopp.................450ml   ";
                  mesa[i].precos[12]=  8.00;
            mesa[i].pedidos[13]= "Torre-Chopp............2l     ";
                  mesa[i].precos[13] = 40.00;
            mesa[i].pedidos [14]= "Red Label ............Dose    ";
                  mesa[i].precos[14] = 20.00;
            mesa[i].pedidos [15]= "Heineken..............750ml   ";
                  mesa[i].precos[15] = 15.00;
            mesa[i].pedidos [16]= "Corona................390ml   ";
                  mesa[i].precos[16] = 12.00;
            mesa[i].pedidos [17]= "Coca - Cola...........1l      ";
                mesa[i].precos[17] = 5.00;
            mesa[i].pedidos [18]= "Guaraná...............1l      ";
                mesa[i].precos[18] = 5.00;
            mesa[i].pedidos [19]= "Suco de laranja.......500ml   ";
                mesa[i].precos[19] = 4.00;
            mesa[i].pedidos [20]= "Suco de Abacaxi.......500ml   ";
                mesa[i].precos[20] = 3.50;
            //preco de sobremesa
            mesa[i].pedidos[22] = "Pudim.................100ml   ";
                  mesa[i].precos[22] = 4.5;
            mesa[i].pedidos[23] = "Pavê de chocolate.....250ml   ";
                  mesa[i].precos[23] = 5.00;
            mesa[i].pedidos[24] = "Pavê de Biscoito......250ml   ";
                  mesa[i].precos[24] = 6.00;
            mesa[i].pedidos[25] = "açaí..................500ml   ";
                 mesa[i].precos[25] = 10.00;
            mesa[i].pedidos[26] = "mousse de maracujá....250ml   ";
                mesa[i].precos[26] = 6.5;
            mesa[i].pedidos[27]= "Doce de leite.........250ml   ";
                mesa[i].precos[27]= 4.5;
      }
}


int relacaoMesa(){
  int selecionaMesa;
    do{
      criaMenu(2,40,20,9,BLACK,COR_LETRA);
      gotoxy(36,10);
      cout <<"MESAS";
      criaMenu(11,40,20,12,COR_LETRA,BLACK);
      gotoxy(25,13);
      cout<<"NUMERO";
      gotoxy(47,13);
      cout<<"STATUS";
      //nomes
      gotoxy(27,15);
        mesa[1].status=="LIVRE"? textcolor(GREEN):textcolor(LIGHTRED);
        cout<<" 1 ";
      gotoxy(27,16);
        mesa[2].status=="LIVRE"? textcolor(GREEN):textcolor(LIGHTRED);
        cout<<" 2 ";
      gotoxy(27,17);
        mesa[3].status=="LIVRE"? textcolor(GREEN):textcolor(LIGHTRED);
        cout<<" 3 ";
      gotoxy(27,18);
        mesa[4].status=="LIVRE"? textcolor(GREEN):textcolor(LIGHTRED);
        cout<<" 4 ";
      //status

      gotoxy(48,15);
        mesa[1].status=="LIVRE"? textcolor(GREEN):textcolor(LIGHTRED);
        cout<<mesa[1].status;
      gotoxy(48,16);
        mesa[2].status=="LIVRE"? textcolor(GREEN):textcolor(LIGHTRED);
        cout<<mesa[2].status;
      gotoxy(48,17);
        mesa[3].status=="LIVRE"? textcolor(GREEN):textcolor(LIGHTRED);
        cout<<mesa[3].status;
      gotoxy(48,18);
        mesa[4].status=="LIVRE"? textcolor(GREEN):textcolor(LIGHTRED);
        cout<<mesa[4].status;
      //liberar, abrir.
      textcolor(BLACK);
      gotoxy(26,21);
        cout<<">>Selecione a opcao: ";
        cin>>selecionaMesa;
        fflush(stdin);
        if (selecionaMesa<1 || selecionaMesa>4){
            gotoxy(25,22);
            textcolor(COR_ALERTA);
            cout<<"Opcao digitado e invalida!!";
            Sleep(1000);
            gotoxy(20,21);
            clreol();
            gotoxy(20,22);
            clreol();
            textcolor(COR_LETRA);
        }
        else{
          return cardapioMesas(selecionaMesa);
        }
    }while(selecionaMesa<1 || selecionaMesa>4 );

}



int cardapioMesas(int opcaoMesa){
    int opcaoSelecionada,escolhaPrato,statusCompras,i,saida;
    do {
      do{

          saida=-1;
          system("cls");
          logoPrincipal();
          criaMenu(4,42,20,5,BLACK,WHITE);
          gotoxy(36,6);
          cout<<"CARÁPIO";
          gotoxy(30,8);
          cout<<"MESA SELECIONADA : "<<opcaoMesa;
          criaMenu(8,42,20,10,WHITE,BLACK);
          gotoxy(30,11);
          cout<<"#1 Comidas";
          gotoxy(30,12);
          cout<<"#2 Bebidas";
          gotoxy(30,13);
          cout<<"#3 Sobremesas";
          gotoxy(30,14);
          cout<<"#4 Lista de pedidos";
          gotoxy(30,15);
          cout<<"#5 Voltar ao menu inicial";
          gotoxy(30,17);
          cout<<">> Selecione uma opcao: ";
          fflush(stdin);
          scanf("%d",&opcaoSelecionada);

          if (opcaoSelecionada<1 || opcaoSelecionada>5){
            gotoxy(32,18);
            textcolor(COR_ALERTA);
            cout<<"Opcao digitada é invalida";
            Sleep(1000);
            system("cls");
            textcolor(COR_LETRA);

          }
        }while(opcaoSelecionada<1 || opcaoSelecionada>5);

         switch (opcaoSelecionada){
              //pratos
              case 1:
                  do{
                     system("cls");
                     logoPrincipal();
                     criaMenu(3,50,15,5,BLACK,WHITE);
                     gotoxy(32,6);
                     cout << "CARDÁPIO - PRATOS";

                     criaMenu(14,50,15,8,WHITE,BLACK);
                     for (i=1;i<=8;i++){
                         gotoxy(20,i+8);
                         cout <<i<<" - " << mesa[opcaoMesa].pedidos[i];
                         printf(" R$ %2.2f\n",mesa[opcaoMesa].precos[i]);
                     }
                     gotoxy(24,19);
                     cout << "Escolha a opção de prato :";
                     cin >> escolhaPrato;

                     if (escolhaPrato<1 || escolhaPrato>8){
                        textcolor(COR_ALERTA);
                        gotoxy(25,22);
                        cout<<"A opção digitada é invalida!!";
                        Sleep(2000);
                        system("cls");
                        saida=2;
                        textcolor(COR_LETRA);
                     }
                     else{
                          statusCompras = calculaPedido(escolhaPrato,opcaoMesa);
                          switch (statusCompras){
                              case 1:
                                  //verifica o status da mesa
                                  textcolor(BLUE);
                                  gotoxy(25,12);
                                  cout << "Pedido confirmado!\n";
                                  mesa[opcaoMesa].status="OCUPADA";
                                  gotoxy(25,14);
                                  cout<<"Valor a pagar: R$" << mesa[opcaoMesa].precoTotal;
                                  Sleep(2000);
                                  gotoxy(25,14);
                                  clreol();
                                  opcoesCardapio(saida);
                                  textcolor(BLACK);
                              break;
                              case 2:
                                  textcolor(COR_ALERTA);
                                  gotoxy(25,14);
                                  cout << "Pedido cancelado!\n";
                                  Sleep(2000);
                                  gotoxy(25,14);
                                  clreol();
                                  opcoesCardapio(saida);
                                  textcolor(BLACK);
                              break;

                          }
                      }
                }while (saida==2);
              break;

              case 2:
              //bebidas
                do{

                   system("cls");
                   logoPrincipal();
                   criaMenu(3,50,15,5,BLACK,WHITE);
                   gotoxy(32,6);
                   cout << "CARDAPIO - BEBIDAS \n\n";
                   criaMenu(14,50,15,8,WHITE,BLACK);
                   for (i=10;i<=20;i++){
                        gotoxy(20,i-1);
                        cout <<i<<"-" << mesa[opcaoMesa].pedidos[i];
                        printf(" R$ %2.2f\n",mesa[opcaoMesa].precos[i]);
                   }
                   gotoxy(24,21);
                   cout << "Escolha a opção de prato :";
                   cin >> escolhaPrato;
                    if (escolhaPrato<10 || escolhaPrato>20){
                        textcolor(COR_ALERTA);

                        gotoxy(25,20);
                        cout<<"A opção digitada é invalida!!";
                        Sleep(2000);
                        system("cls");
                        saida=2;
                        textcolor(COR_LETRA);
                    }
                    else{
                         statusCompras = calculaPedido(escolhaPrato,opcaoMesa);
                          switch (statusCompras){
                              case 1:

                                  textcolor(BLUE);
                                  gotoxy(25,12);
                                  cout << "Pedido confirmado!\n";
                                  mesa[opcaoMesa].status="OCUPADA";
                                  gotoxy(25,14);
                                  cout<<"Valor a pagar: R$" << mesa[opcaoMesa].precoTotal;
                                  Sleep(2000);
                                  gotoxy(25,14);
                                  clreol();
                                  textcolor(COR_LETRA);
                                  opcoesCardapio(saida);

                              break;
                              case 2:

                                  textcolor(COR_ALERTA);
                                  textbackground(WHITE);
                                  gotoxy(25,14);
                                  cout << "Pedido cancelado!\n";
                                  gotoxy(25,14);
                                  clreol();
                                  opcoesCardapio(saida);
                                  textcolor(COR_LETRA);

                              break;
                          }
                    }
                }while (saida==2);

              break;

              case 3:
              //sobremesas
                 do{
                       system("cls");
                       logoPrincipal();
                       criaMenu(3,50,15,5,BLACK,WHITE);
                       gotoxy(32,6);
                       cout << "CARDAPIO \n\n";
                       criaMenu(14,50,15,8,WHITE,BLACK);
                       for (i=22;i<=27;i++){
                            gotoxy(20,i-13);
                            cout <<i<<"-" << mesa[opcaoMesa].pedidos[i];
                            printf(" R$ %3.2f\n",mesa[opcaoMesa].precos[i]);
                       }

                       gotoxy(24,20);
                       cout << "Escolha a opção de prato :";
                       cin >> escolhaPrato;
                       if (escolhaPrato<22 || escolhaPrato>27){
                            textcolor(COR_ALERTA);
                            textbackground(WHITE);
                            gotoxy(22,21);
                            cout<<"A opcao digitada é invalida!!";
                            Sleep(2000);
                            saida=2;
                            system("cls");
                            textcolor(COR_LETRA);

                       }
                       else{
                         statusCompras = calculaPedido(escolhaPrato,opcaoMesa);
                              switch (statusCompras){
                                  case 1:
                                      textcolor(BLUE);
                                      textbackground(WHITE);
                                      gotoxy(25,12);
                                      cout << "Pedido confirmado!\n";
                                      mesa[opcaoMesa].status="OCUPADA";
                                      gotoxy(25,14);
                                      cout<<"Valor a pagar: R$" << mesa[opcaoMesa].precoTotal;
                                      Sleep(2000);
                                      gotoxy(25,14);
                                      clreol();
                                      opcoesCardapio(saida);
                                      textcolor(COR_LETRA);
                                  break;
                                  case 2:
                                      textcolor(COR_ALERTA);
                                      gotoxy(25,14);
                                      cout << "Pedido cancelado!\n";
                                      Sleep(2000);
                                      gotoxy(25,14);
                                      clreol();
                                      opcoesCardapio(saida);
                                  break;

                              }
                      }
                 }while (saida==2);
              break;
              case 4:
                saida = listaPedidos(opcaoMesa);
              break;
              case 5:
                return 1;
              break;
         }
    }while(saida==1);
}

int calculaPedido(int indicePedido,int opcaoMesa){
  int qtdPedido,opcaoSelecionada,saida;
        gotoxy(24,22);
        cout <<"Informe a quantidade: ";
        cin >> qtdPedido;
    do{
        saida=0;
        abs(qtdPedido);
        system("cls");
        logoPrincipal();
        criaMenu(8,50,15,6,WHITE,BLACK);
        gotoxy(25,7);
        cout<<"1- Confirmar pedido";
        gotoxy(25,9);
        cout<<"2- Cancelar Pedido";
        gotoxy(25,11);
        cout<<">>Selecione uma opcao: ";
        cin >> opcaoSelecionada;
        if (opcaoSelecionada!=1 && opcaoSelecionada!=2){
            textcolor(COR_ALERTA);
            gotoxy(25,13);
            cout<<"A opcao digitada é invalida!!";
            Sleep(1000);
            system("cls");
            saida=1;
            textcolor(COR_LETRA);
        }
        else if(opcaoSelecionada==1){
            mesa[opcaoMesa].precoTotal += mesa[opcaoMesa].precos[indicePedido] * qtdPedido;
            listaPedidos(indicePedido,qtdPedido,opcaoMesa);//preenche a lista
        }
      fflush(stdin);
      }while(saida==1);
      gotoxy(25,11);
      clreol();
      return opcaoSelecionada;

}


void opcoesCardapio(int &saida){
    logoPrincipal();
    int opcaoSelecionada;
      gotoxy(25,7);
      clreol();
      gotoxy(25,9);
      clreol();
  do {
    criaMenu(8,50,15,6,WHITE,BLACK);

    gotoxy(25,7);
      cout<<"3- Continuar comprando";
    gotoxy(25,9);
      cout<<"4- Voltar ao cardápio";
    gotoxy(25,11);
      cout<<">>Selecione uma opcao: ";
      cin>>opcaoSelecionada;
      if (opcaoSelecionada!=3 && opcaoSelecionada!=4){
            textcolor(COR_ALERTA);
            gotoxy(25,13);
            cout<<"A opcao digitada é invalida!!";
            Sleep(1000);
            gotoxy(25,7);
            clreol();
            gotoxy(25,9);
            clreol();
            gotoxy(25,11);
            clreol();
            gotoxy(25,13);
            clreol();
            textcolor(COR_LETRA);
      }
      else{
          switch(opcaoSelecionada){
          case 3:
            saida=2;
          break;
          case 4:
            saida=1;
          break;
          }

      }
  }while(opcaoSelecionada!=3 && opcaoSelecionada!=4);
}





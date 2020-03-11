
int menuCaixa(int opcaoSelecionada);
int caixa(int opcaoSelecionada);
int garcom(int opcaoSelecionada);
int confirmaSaida();


int garcom(){
    int saida=-1,i,opcaoSelecionada;
    do{
        criaMenu(2,40,20,9,BLACK,WHITE);
        gotoxy(36,10);

        cout<<"GARCOM";
        criaMenu(11,40,20,12,COR_LETRA,BLACK);
        gotoxy(26,13);
        cout<<"1 - Mesas";
        gotoxy(26,16);
        cout<<"2 - Tela login";
        gotoxy(26,21);
        cout<<">> Selecione uma opcao: ";
        cin>>opcaoSelecionada;
        if(opcaoSelecionada!=1 && opcaoSelecionada!=2){
            gotoxy(28,19);
            cout<<"Opção digitada é inválida!";
            Sleep(1000);
            system("cls");
            return 1;
        }
        else{
          if (opcaoSelecionada==1){
            //apaga o menu inicial
            for (i=10;i<=21;i++){
                gotoxy(1,i);
                clreol();
            }
            relacaoMesa();
          }
          else
            confirmaSaida();
      }
    }while(saida==1);
}

int caixa(){
    int i,opcaoSelecionada;
    do{
      criaMenu(2,40,20,9,BLACK,WHITE);
      gotoxy(38,10);
      cout<<"CAIXA";
      criaMenu(11,40,20,12,COR_LETRA,BLACK);
      gotoxy(24,13);
      cout<<"1- Mesas"; //chama uma função que exibe as mesas
      gotoxy(24,15);
      cout<<"2- Efetuar pagamento";//efetua o pagamento da conta e libera a mesa
      gotoxy(24,17);
      cout<<"3- Controle funcionarios";//exibe o relatorio de funcionarios
      gotoxy(24,19);
      cout<<"4- Tela login";//exibe o relatorio de funcionarios
      gotoxy(24,21);
      cout<<"# Digite a opcao : ";
      cin>>opcaoSelecionada;
      if (opcaoSelecionada<1 || opcaoSelecionada>4 ){
          gotoxy(25,23);
          textcolor(COR_ALERTA);
          cout<<"Opcao digitada e invalida!!";
          Sleep(1000);
          //limpa a mensagem de alerta
          gotoxy(20,23);
          clreol();
          //limpa o teclado
          gotoxy(24,21);
          clreol();
          fflush(stdin);
          textcolor(COR_LETRA);
      }
      else if(opcaoSelecionada==1){
          for (i=10;i<=21;i++){
                gotoxy(1,i);
                clreol();
            }
           return menuCaixa(opcaoSelecionada);
      }
    }while(opcaoSelecionada<1 || opcaoSelecionada>4);

    menuCaixa(opcaoSelecionada);
}

int menuCaixa(int opcaoSelecionada){
      switch (opcaoSelecionada){
            case 1:
             criaMenu(11,40,20,12,COR_LETRA,BLACK);
             relacaoMesa();
            break;
            case 2:
               efetuaPagamento();
            break;
            case 3:
              system("cls");
              pesquisaFuncionarios();
            break;
            case 4:
              confirmaSaida();
            break;
      }
}

int confirmaSaida(){
char perguntaSaida;
    gotoxy(20,23);
    cout<<"Deseja realmente sair [s / n] ? ";
    cin>>perguntaSaida;
      if (perguntaSaida=='s' || perguntaSaida=='S'){
         return 0;
      }
      else{
          gotoxy(5,23);
          clreol();
          return 1;
      }
}

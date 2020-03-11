using namespace std;

void logo();
void login(char cpf[], int &senha);
void tentativasLogin(int &chancesLogin);
void  telaBloqueioTemporario(int &tentativas,int &chancesLogin);

void telaEntrada(int &id, int &posicao){
    int limiteAcesso=0;
    int chancesLogin=2,status=0;
    int senha;
    char cpf[12];

          do{
                logoPrincipal();
                textcolor(WHITE);
                textbackground(COR_CORPO);
                login(cpf,senha); // R <- F
                relacaoFuncionario(cpf,senha,id,posicao,status);
                //status : cadastrado ou nao
                if (status==1){//cadastrado
                    limiteAcesso=0;
                    chancesLogin=2;
                    return;
                }
                else{
                    //nao cadastrado
                    tentativasLogin(chancesLogin);
                    if (chancesLogin==0){
                       telaBloqueioTemporario(limiteAcesso,chancesLogin);
                    }
                    else
                       chancesLogin--;
                }

          }while(limiteAcesso<=1);
      cout<<"\n\n\n";

}

void login(char cpf[], int &senha){
  bordaLogin();
  gotoxy(28,11);
  cout<<"CPF   ";
  gotoxy(28,15);
  cout<<"SENHA ";
  gotoxy(39,11);
  cin>>cpf;
  gotoxy(39,15);
  cin>>senha;
  fflush(stdin);
}



void tentativasLogin(int &chancesLogin){
    textcolor(COR_CABECALHO);
    textbackground(WHITE);
    gotoxy(26,18);
    cout<<"CPF ou senha está incorreto!!";
    Sleep(1000);
    textcolor(COR_LETRA);
    textbackground(COR_CORPO);
    system("cls");

}



void telaBloqueioTemporario(int &limiteAcessos, int &chancesLogin){
  int tempo;
  if (limiteAcessos <1){
      for(tempo=5;tempo>=0;tempo--){
        textcolor(COR_LETRA);
        textbackground(COR_DETALHE);
        clrscr();
        gotoxy(4,9);
        cout<<"Voce excedeu o limite de tentativas! Aguarde ate que possa tentar novamente";
        gotoxy(32,11);
        cout<<"Tempo restante : "<<tempo;
        Sleep(1000);
        system("cls");
        textbackground(COR_CORPO);
        clrscr();
      }
      limiteAcessos++;
      chancesLogin=2;
      textcolor(COR_LETRA);
  }
  else{
    logoPrincipal();
    system("cls");
    textcolor(COR_LETRA);
    textbackground(COR_DETALHE);
    clrscr();
    gotoxy(4,10);
    cout<<"O usuario não pode mais tentar entrar no sistema, contate um dos gerentes!\n\n\n\n\n\n";
    exit(1);
  }

}

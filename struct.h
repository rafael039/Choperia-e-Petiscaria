#define TAM 100

struct cadastro{
          //id=1 : garçom
          //id=2 : caixa
              char cpf[12];
              char telefone[15];
              char nome[20];
              char cargo[20];
              char sobrenome[20];

              double salario;

              int senha;
              int idade;
              int id;

      };
struct Cardapio{
            string pedidos[TAM];
            string status="LIVRE";
            float precos[TAM];
            float precoTotal=0.0;
            int listaCompras[TAM];
            int qtdPedidos[TAM];

      };


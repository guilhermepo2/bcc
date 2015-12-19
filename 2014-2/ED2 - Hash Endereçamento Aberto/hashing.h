typedef struct {
                  char nome[30];
                  int idade;
               } TipoInfo;

typedef struct{
                  int Chave;
                  TipoInfo Info;
               } Registro;

struct nodo {
  Registro reg;
  int estado; //0 = vazio
              //1 = preenchido
              //-1 = removido
};

            
typedef struct nodo Dicionario;

int H(int chave, int N);
Dicionario * Inicializar(int N);
void Liberar_Dicionario(Dicionario *D);
int Inserir(Dicionario * D, Registro reg, int N);
Registro * Pesquisar(Dicionario D[], int chave, int N);
int Remover(Dicionario *D, int chave, int N);
void Exibir(Dicionario D[], int N);

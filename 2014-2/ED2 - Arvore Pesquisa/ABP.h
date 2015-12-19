
typedef struct{
                  char nome[30];
                  int idade;
               } TipoInfo;
               
typedef struct{
                  int Chave;
                  TipoInfo Info;
               } Registro;

typedef struct nodoABP ABP;


void Inicializa_ABP(ABP **Ptabp);

ABP* Pesquisa_ABP(ABP *Ptabp, int chave);

int E_Vazia(ABP *Ptabp);

int Insere_nodo(ABP **Ptabp, Registro reg);

int Remove_nodo(ABP **Ptabp, int chave);

//4.1
void achar_altura(ABP * ptab, int * maior);
//4.3
void Exibe_Arvore_Ordem_Crescente(ABP *Ptabp);
//4.4
void Exibe_Arvore_PreOrdem_Esquerda(ABP *Ptabp);
//4.5
void Exibe_Arvore_PosOrdem_Esquerda(ABP *Ptabp);
//4.6
void Exibe_Arvore_Ordem_Decrescente(ABP *Ptabp);
//4.7
void exibe_soma(ABP * ptabp, int * soma);
//4.8
void exibe_media(ABP * ptabp, int * soma, int * elementos);
//4.9
void exibe_maior(ABP * ptabp, int * maior);
//4.10
void exibe_menor(ABP * ptabp, int * menor);
//4.11
void exibe_folhas(ABP * ptabp);

ABP* Libera_ABP(ABP *Ptabp);




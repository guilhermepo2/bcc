typedef struct registrador REG;
typedef struct nodo AB;

void Cria_Arvore(AB **ab);

void Exibe_Arvore(AB *Ptab);

int Cria_Raiz(AB **Ptab, char item);

int E_Vazia(AB *Ptab);

int InserirFilhoaDireita(AB *Ptab, AB *pai, REG * item);

int InserirFilhoaEsquerda(AB *Ptab, AB *pai, REG * item);

void Busca(AB *Ptab, char item, AB ** pt);

AB* Libera_Arvore(AB *Ptab);

REG * cria_reg_operando(int operando);

REG * cria_reg_operador(char operador);

int resolve_expressao(AB * ptab, int * res);

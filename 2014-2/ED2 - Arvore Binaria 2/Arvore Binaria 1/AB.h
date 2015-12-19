typedef struct nodo AB;

void Cria_Arvore(AB **ab);

void Exibe_Arvore(AB *Ptab);

int Cria_Raiz(AB **Ptab, char item);

int E_Vazia(AB *Ptab);

int InserirFilhoaDireita(AB *Ptab, AB *pai, char item);

int InserirFilhoaEsquerda(AB *Ptab, AB *pai, char item);

void Busca(AB *Ptab, char item, AB **pt);

AB* Libera_Arvore(AB *Ptab);

int Remove_Folha(AB **Ptab, char item);

int Remove_FolhaV1(AB **Ptab, char item);

void achar_maior_elemento(AB * ptab, char * maior);

void achar_altura(AB * ptab, int * maior);

void exibir_nao_folha (AB * ptab);

typedef struct queue Fila;

Fila * criar_fila(void);
Fila * libera_fila(Fila * ptf);
Fila * inserir_fila(Fila * ptf, int elem);
Fila * remover_fila(Fila * ptf, int elem);
int consultar_fila(Fila * ptf, int * elem);
void exibe_fila(Fila * ptf);
int E_cheia(Fila * ptf);
int E_vazia(Fila * ptf);


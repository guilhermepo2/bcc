#include<stdlib.h>
#include<stdio.h>

struct nodo
{
  struct nodo *esq;
  char info;
  struct nodo * dir;
};

typedef struct nodo ARVORE_BINARIA;

void criar_arvore(ARVORE_BINARIA ** ptab);
int criar_raiz(ARVORE_BINARIA ** ptab, char item);
void buscar(ARVORE_BINARIA * ptab, char item, ARVORE_BINARIA ** pt);
int inserir_esquerda(ARVORE_BINARIA ** ptab, ARVORE_BINARIA * pai, char item);
int inserir_direita(ARVORE_BINARIA ** ptab, ARVORE_BINARIA * pai, char item);
int remover_folha(ARVORE_BINARIA ** ptab, char item);
void pre_ordem(ARVORE_BINARIA * ptab);
void pos_ordem(ARVORE_BINARIA * ptab);
void em_ordem(ARVORE_BINARIA * ptab);
ARVORE_BINARIA * liberar_arvore(ARVORE_BINARIA * ptab);

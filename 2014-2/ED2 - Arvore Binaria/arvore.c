#include "arvore.h"

void criar_arvore(ARVORE_BINARIA ** ptab)
{
  *ptab = NULL;
}

int criar_raiz(ARVORE_BINARIA ** ptab, char item)
{
  if(*ptab == NULL)
    return 0;
  *ptab = (ARVORE_BINARIA*)malloc(sizeof(ARVORE_BINARIA));
  if(*ptab != NULL)
    {
      (*ptab)->esq = NULL;
      (*ptab)->dir = NULL;
      (*ptab)->info = item;
      return 1;
    }
  return 0;
}

void buscar(ARVORE_BINARIA * ptab, char item, ARVORE_BINARIA ** pt)
{
  if(ptab == NULL || *pt != NULL)
    return;
  if(ptab->info != item)
    {
      buscar(ptab->esq,item,pt);
      if(*pt == NULL)
	buscar(ptab->dir,item,pt);
    }
  else *pt = ptab;
  return;
}

int inserir_esquerda(ARVORE_BINARIA ** ptab, ARVORE_BINARIA * pai, char item)
{
  ARVORE_BINARIA * pt;
  if(pai!=NULL & pai->esq == NULL)
    {
      pt = (ARVORE_BINARIA*)malloc(sizeof(ARVORE_BINARIA));
      if(pt == NULL)
	return 0;
      pt->esq = NULL;
      pt->dir = NULL;
      pt->info = item;
      pai->esq = pt;
      return 1;
    }
  else return 0;
}

int inserir_direita(ARVORE_BINARIA ** ptab, ARVORE_BINARIA * pai, char item)
{
  ARVORE_BINARIA * pt;
  if(pai!=NULL & pai->dir == NULL)
    {
      pt = (ARVORE_BINARIA*)malloc(sizeof(ARVORE_BINARIA));
      if(pt == NULL)
	return 0;
      pt->esq = NULL;
      pt->dir = NULL;
      pt->info = item;
      pai->dir = pt;
      return 1;
    }
  else return 0;
}

int remover_folha(ARVORE_BINARIA ** ptab, char item)
{
  ARVORE_BINARIA ** pai;
  if(*ptab != NULL && (*ptab)->info == item)
    {
      if((*ptab)->esq == NULL && (*ptab)->dir == NULL)
	{
	  free(*ptab);
	  *ptab = NULL;
	  return 1;
	}
    }
  if(*ptab!=NULL)
    {
      pai = NULL;
      localiza_paiV1(*ptab,item,pai);
      if(pai!=NULL)
	{
	  if((*pai)->esq == NULL && (*pai)->dir == NULL)
	    {
	      free(*pai);
	      *pai = NULL;
	      return 1;
	    }
	  else return 0; // nodo nao e folha
	}
      else return 0; //nodo nao existe
    }
  else return 0; //arvore vazia
}

void pre_ordem(ARVORE_BINARIA * ptab)
{
  if(ptab!=NULL)
    {
      printf("%c",ptab->info);
      pre_ordem(ptab->esq);
      pre_ordem(ptab->dir);
    }
}

void pos_ordem(ARVORE_BINARIA * ptab)
{
  if(ptab!=NULL)
    {
      pre_ordem(ptab->esq);
      pre_ordem(ptab->dir);
      printf("%c", ptab->info);
    }
}

void em_ordem(ARVORE_BINARIA * ptab)
{
  if(ptab!=NULL)
    {
      pre_ordem(ptab->esq);
      printf("%c", ptab->info);
      pre_ordem(ptab->dir);
    }
}

ARVORE_BINARIA * liberar_arvore(ARVORE_BINARIA * ptab)
{
  if(ptab!=NULL)
    {
      liberar_arvore(ptab->esq);
      liberar_arvore(ptab->dir);
      free(ptab);
    }
  return NULL;
}

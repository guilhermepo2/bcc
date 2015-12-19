#include"AB.h"
#include <stdio.h>
#include <stdlib.h>

struct registrador
{
  char operador;
  int operando;
  int tipo_dado;
};

struct nodo
{
  struct nodo* esq;
  struct registrador info;
  struct nodo* dir;
};

void Cria_Arvore(AB **Ptab)
{
     *Ptab = NULL;
}

int Cria_Raiz(AB **Ptab, char item)
{
  REG * novo = (REG*)malloc(sizeof(REG));
  novo->tipo_dado = 0;
  novo->operador=item;
    
   *Ptab=(AB*)malloc(sizeof(AB));
   if (*Ptab != NULL)
   {
      (*Ptab)->esq = NULL;
      (*Ptab)->info = *novo;
      (*Ptab)->dir = NULL;
      return 1;
   };
   return 0;
}

REG * cria_reg_operando(int operando)
{
  REG * novo = (REG*)malloc(sizeof(REG));
  novo->tipo_dado = 1;
  novo->operando = operando;
  novo->operador = '~';
  return novo;
}
REG * cria_reg_operador(char operador)
{
  REG * novo = (REG*)malloc(sizeof(REG));
  novo->tipo_dado = 0;
  novo->operador = operador;
  novo->operando = 0;

  return novo;
}

void Exibe_Arvore(AB *Ptab)
{
  
  if (Ptab == NULL)
      return;

  if(Ptab->info.tipo_dado ==0)  
    printf("%c ",Ptab->info.operador);
  else
    printf("%d ", Ptab->info.operando);
  Exibe_Arvore(Ptab->esq);
  Exibe_Arvore(Ptab->dir);
}

   
int E_Vazia(AB *Ptab)
{
  if (Ptab == NULL)
      return 1;
  else return 0;
}

int InserirFilhoaDireita(AB *Ptab, AB *pai, REG * item)
{
   AB *pt;
   if(pai != NULL && pai->dir == NULL)
   {
      pt = (AB*) malloc(sizeof(AB));
      if (pt == NULL)
        return 0;
      pt->esq = NULL;
      pt->info = *item;
      pt->dir = NULL;
      pai->dir = pt;
      return 1;
   }
   return 0;
}
  
int InserirFilhoaEsquerda(AB *Ptab, AB *pai, REG * item)
{
   AB *pt;
   if(pai != NULL && pai->esq == NULL)
   {
      pt = (AB*) malloc(sizeof(AB));
      if (pt == NULL)
        return 0;
      pt->esq = NULL;
      pt->info = *item;
      pt->dir = NULL;
      pai->esq = pt;
      return 1;
   }
   return 0;
}


void Busca(AB *Ptab, char item, AB ** pt)
{
        
       if (Ptab == NULL || *pt != NULL)
         return;
       if (Ptab->info.operador != item  )
             {
               Busca(Ptab->esq, item, pt);
               Busca(Ptab->dir, item, pt);
             }
       else  *pt = Ptab;                 
       return;           
}

 

AB* Libera_Arvore(AB *Ptab)
{
    if (Ptab!=NULL)
    {
        Libera_Arvore(Ptab->esq); /* libera subarvore  a esq */
        Libera_Arvore(Ptab->dir); /* libera subarvore a dir */
       free(Ptab); /* libera raiz */
    }
   return NULL;
} 

int resolve_expressao(AB * ptab, int * res)
{
  if(ptab!=NULL)
    {
      AB * filho_esq = ptab->esq;
      AB * filho_dir = ptab->dir;
      if(filho_esq->info.tipo_dado == 1 && filho_dir->info.tipo_dado == 1)
	{
	  switch(ptab->info.operador)
	    {
	    case '+':
	      ptab->info.operando = (filho_esq->info.operando + filho_dir->info.operando);
	      ptab->info.tipo_dado = 1;
	      break;
	    case '-':
	      	      ptab->info.operando = (filho_esq->info.operando - filho_dir->info.operando);
	      ptab->info.tipo_dado = 1;
	      break;
	    case '*':
	      	      ptab->info.operando = (filho_esq->info.operando * filho_dir->info.operando);
	      ptab->info.tipo_dado = 1;
	      break;
	    case '/':
	      	      ptab->info.operando = (filho_esq->info.operando / filho_dir->info.operando);
	      ptab->info.tipo_dado = 1;
	      break;
	    }
	  ptab->esq = NULL;
	  ptab->dir = NULL;
	  free(filho_esq);
	  free(filho_dir);
	  *res = ptab->info.operando;
	  return *res;
	}
      else
	{
	  if(filho_esq->info.tipo_dado == 0)
	    resolve_expressao(filho_esq, res);
	  if(filho_dir->info.tipo_dado == 0)
	    resolve_expressao(filho_dir, res);

	  resolve_expressao(ptab, res);
	}
    }
  return *res;
}

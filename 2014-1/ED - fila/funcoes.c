#include<stdlib.h>
#include<stdio.h>
#include "header.h"
#define MAX_FILA 100

struct queue
{
  int fila[MAX_FILA];
  int IF; //inicio da fila
  int FF; //fim da fila
  int n; //numero de elementos

  /*
    A remoção é feita somente deslocando o inicio da fila, e se o inicio for após o 0, o fim da fila volta para o 0.
   */
};

Fila * criar_fila(void)
{
  Fila * ptf;
  ptf = (Fila*)malloc(sizeof(Fila));
  ptf->IF = 0;
  ptf->FF = 0;
  ptf->n = 0;
  return ptf;
}

Fila * libera_fila(Fila * ptf)
{
  if (ptf == NULL)
    return ptf;
  
  free(ptf);
  return NULL;
}

Fila * inserir_fila(Fila * ptf, int elem)
{
  if(ptf == NULL)
    return ptf;

  if (ptf->FF == MAX_FILA)
    {
      if(ptf->IF > 0)
	ptf->FF = 0;
      else
	return ptf;
    }
  
  ptf->fila[ptf->FF] = elem;
  ptf->FF += 1;
  ptf->n += 1;
  return ptf;
}

Fila * remover_fila(Fila * ptf, int elem)
{
  if(ptf == NULL || ptf->n == 0)
    return ptf;

  ptf->IF += 1;
  ptf->n -= 1;
  return ptf;
}

int consultar_fila(Fila * ptf, int * elem)
{
  if (ptf == NULL || ptf->n == 0)
    return 0;
  *elem = ptf->fila[ptf->IF];
  return 1;
}

void exibe_fila(Fila * ptf)
{
  if (ptf == NULL || ptf->n == 0)
    printf("Lista Vazia!\n");
  else
    {
      int i, aux;
      for(i=0;i<ptf->n;i++)
	{
	  printf("%d ", (ptf->fila[(ptf->IF)+i]));
	}
    }
    
}

int E_cheia(Fila * ptf)
{
  if(ptf->n == MAX_FILA)
    return 1;
  else
    return 0;
}

int E_vazia(Fila * ptf)
{
  if(ptf->n == 0)
    return 1;
  else
    return 0;
}

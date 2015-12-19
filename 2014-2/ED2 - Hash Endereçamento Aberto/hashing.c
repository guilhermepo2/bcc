#include <stdlib.h>
#include <stdio.h>
#include "hashing.h"
 
int H(int chave, int N)
{
  return (chave%(2*N));
}

Dicionario * Inicializar(int N)
{
  Dicionario * dic;
  int i, M = 2*N;
  dic = (Dicionario*)malloc(M*sizeof(Dicionario));
  if (dic != NULL)
    {
      for(i=0;i<M;i++)
	{
	  dic[i].estado = 0;
	}
    }
  return dic;
}

// isso tem cara de estar errado
void Liberar_Dicionario(Dicionario *D)
{
  free(D);
}

int Inserir(Dicionario * D, Registro reg, int N)
{
   int entrada;
   int M = 2 * N;
   entrada = H(reg.Chave, N);
   do
     {
       if(D[entrada].estado == 0 || D[entrada].estado == -1)
	 {
	   D[entrada].reg = reg;
	   D[entrada].estado = 1;
	   return 1;
	 }
       else
	 entrada++;
       if(entrada >= M)
	 entrada = 0;
     }while(entrada<M);

   return 0;
}

Registro * Pesquisar(Dicionario D[], int chave, int N)
{
  int entrada;
  int M = 2*N;
  entrada = H(chave,N);

  do
    {
      if(D[entrada].reg.Chave == chave)
	return (&(D[entrada].reg));
      else
	entrada++;

      if(entrada>=M)
	entrada = 0;
    }while(D[entrada].estado != 0);
  
  return NULL;
}                    


int Remover(Dicionario *D, int chave, int N)
{
   int entrada;
   entrada = H(chave, N);
   int M = 2*N;

   do
     {
       if (D[entrada].reg.Chave == chave)
	 {
	   D[entrada].estado = -1;
	   return 1;
	 }
       else
	 entrada++;

       if(entrada>=M)
	 entrada = 0;
     }while(D[entrada].estado != 0);

   return 0;
}

void Exibir(Dicionario D[], int N)
{
  int i, M = 2*N;
  printf("\n");
  for (i = 0; i < M; i++)
    {
      if(D[i].estado == 0)
	printf("Posicao Vazia\n");
      if(D[i].estado == -1)
	printf("Posicao Removida\n");
      if(D[i].estado == 1)
	printf("Chave: %d\n",D[i].reg.Chave);
    }
  printf("\n");
}        

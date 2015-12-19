#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main()
{
  Fila * fila;
  int opc, elem, verf;
  fila = criar_fila();
  printf("Lista Criada.\nEndereco da fila: %p\n\n", fila);
  do
    {
      printf("\n===========================\n");
      printf("O que deseja fazer?\n");
      printf("1 - Inserir elemento na fila.\n");
      printf("2 - Remover Elemento da Fila.\n");
      printf("3 - Consultar a Fila.\n");
      printf("4 - Exibir a Fila.\n");
      printf("5 - Verificar se a fila está cheia.\n");
      printf("6 - Verificar se a fila está vazia.\n");
      printf("7 - Liberar Fila.\n");
      printf("8 - Sair do Programa.\n");
      printf("Opcao: ");
      scanf("%d", &opc);
      printf("\n============================\n");
      switch(opc)
	{
	case 1:
	  printf("Digite o elemento que deseja inserir: ");
	  scanf("%d", &elem);
	  fila = inserir_fila(fila,elem);
	  break;
	case 2:
	  fila = remover_fila(fila,elem);
	  break;
	case 3:
	  verf = consultar_fila(fila,&elem);
	  printf("Fila Consultada\nNumero Obtido: %d", elem);
	  break;
	case 4:
	  exibe_fila(fila);
	  break;
	case 5:
	  verf = E_cheia(fila);
	  if (verf)
	    printf("Lista Cheia!");
	  else
	    printf("Lista nao Cheia!");
	  break;
	case 6:
	  verf = E_vazia(fila);
	  if(verf)
	    printf("Lista Vazia!");
	  else
	    printf("Lista nao Vazia!");
	  break;
	case 7:
	  fila = libera_fila(fila);
	}
    }while(opc!=8);  
  
  return 0;
}

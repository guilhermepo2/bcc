#include <stdio.h>
#include "hashing.h"

int main(void)
{
  int N, opt, c;
  Dicionario * D;
  Registro r, * ptr;
  r.Chave = 0;
  
  printf("Digite o numero de registros: ");
  scanf("%d", &N);
  D = Inicializar(N);

  do
    {
      printf("1 - Inserir\n2 - Pesquisar\n3 - Remover\n4 - Exibir Dicionario\n5 - Liberar Dicionario\n6 - Sair\n");
      printf("Digite a Opcao que deseja: ");
      scanf("%d", &opt);

      switch(opt)
	{
	case 1:
	  printf("Digite a chave a ser inserida: ");
	  scanf("%d", &c);
	  r.Chave = c;
	  Inserir(D, r, N);
	  break;
	case 2:
	  printf("Digite a chave a ser pesquisada: ");
	  scanf("%d", &c);
	  ptr = Pesquisar(D,c,N);
	  printf("Endereco do Registro Encontrado: %p\n", ptr);
	  break;
	case 3:
	  printf("Digite a chave a ser removida: ");
	  scanf("%d", &c);
	  Remover(D, c, N);
	  break;
	case 4:
	  Exibir(D,N);
	  break;
	case 5:
	  Liberar_Dicionario(D);
	  break;
	}
    }while(opt!=6);

  return 1;
}

  
  

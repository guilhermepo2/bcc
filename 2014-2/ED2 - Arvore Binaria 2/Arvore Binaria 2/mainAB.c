#include<stdio.h>
#include<stdlib.h>
#include"AB.h"

AB * criar_arvore(AB * pt)
{
  Cria_Arvore(&pt);
  getchar();
  return pt;
}

AB * criar_raiz(AB * pt)
{
  char item;
  printf("entre com o valor da raiz (deve ser um operador) --> ");
  scanf(" %c", &item);
  Cria_Raiz(&pt, item);
  getchar();
  return pt;
}

AB * insere_esquerda(AB * pt, AB * pai)
{
  char operador_pai;
  REG * novo;
  printf("Digite o pai: (deve ser um operador): ");
  scanf(" %c", &operador_pai);
  pai = NULL;
  Busca(pt,operador_pai,&pai);
  if(pai==NULL)
    printf("Pai nao encontrado \n");
  else
    {
      printf("Deseja inserir\n1 - Operando\n2 - Operador\n");
      int opcao;
      scanf("%d", &opcao);
      if(opcao == 1)
	{
	  int operando;
	  printf("Digite o Operando: ");
	  scanf("%d", &operando);
	  novo = cria_reg_operando(operando);
	}
      else
	{
	  char operador;
	  printf("Digite o Operador: ");
	  scanf(" %c", &operador);
	  novo = cria_reg_operador(operador);
	}
      
      InserirFilhoaEsquerda(pt, pai, novo);
	
    }

  getchar();
  return pt;
}

AB * insere_direita(AB * pt, AB * pai)
{
  char operador_pai;
  REG * novo;
  printf("Digite o pai: (deve ser um operador): ");
  scanf(" %c", &operador_pai);
  pai = NULL;
  Busca(pt,operador_pai,&pai);
  if(pai==NULL)
    printf("Pai nao encontrado \n");
  else
    {
      printf("Deseja inserir\n1 - Operando\n2 - Operador\n");
      int opcao;
      scanf("%d", &opcao);
      if(opcao == 1)
	{
	  int operando;
	  printf("Digite o Operando: ");
	  scanf("%d", &operando);
	  novo = cria_reg_operando(operando);
	}
      else
	{
	  char operador;
	  printf("Digite o Operador: ");
	  scanf(" %c", &operador);
	  novo = cria_reg_operador(operador);
	}
      
      InserirFilhoaDireita(pt, pai, novo);
	
    }

  getchar();
  return pt;
}

AB * remove_folha(AB * pt)
{
  char item;
  int st;
  
  printf("entre com o valor do nodo a ser removido: ");
  scanf(" %c",&item);
  //st=Remove_FolhaV1(&pt,item);
  if (st == 1)
    printf("\n elemento removido \n");
  else printf("\n elemento nao exite ou nao eh nodo folha");
  getchar();
  return pt;
}

AB * main_resolve_expressao(AB * ptab)
{
  int res;
  printf("Resultado da Avaliacao: %d", resolve_expressao(ptab, &res));
  ptab=Libera_Arvore(ptab);
  printf("\nArvore destruida.");
  printf("\n\n");

  return ptab;
}

int main()
{
   AB* Ptab, *pai;
   int opcao;
   char * aux = (char*)malloc(sizeof(char));
   do{ system("cls");
       printf(" selelcione uma opcao:\n" 
       "\t 1- inicializa arvore \n" 
       "\t 2- cria raiz \n" 
       "\t 3- insere elemento a esquerda \n" 
       "\t 4- insere elemento a direita \n" 
       "\t 5- exibe arvore \n"
       "\t 6 - Resolver Expressao\n"
	      //"\t 6- busca elemento \n" 
       "\t 7- libera arvore \n" 
	      //"\t 8- remove folha \n"
       "\t 0-termina programa \n");
       scanf("%d", &opcao);
 //      executafuncao(opcao, Ptab);
     switch (opcao){
     case 1: Ptab = criar_arvore(Ptab);
             break;
     case 2: Ptab = criar_raiz(Ptab);
             break;
     case 3:Ptab = insere_esquerda(Ptab,pai);
            break;
     case 4:Ptab = insere_direita(Ptab,pai);
            break;
     case 5:Exibe_Arvore(Ptab);
            break;
     case 6: Ptab = main_resolve_expressao(Ptab);
       break;
     case 7: Ptab=Libera_Arvore(Ptab);
             if (E_Vazia(Ptab))
             printf("arvore vazia \n");
             getchar();
            break;
     case 8: //Ptab = remove_folha(Ptab);
            break;            
     default: printf("opcao errada, entre novamente \n");  
              getchar();  
    }            
     }while (opcao != 0);
     
      
}; 
   
 

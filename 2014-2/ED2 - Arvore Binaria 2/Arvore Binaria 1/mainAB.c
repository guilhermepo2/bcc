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
  printf("entre com o valor da raiz --> ");
  scanf(" %c", &item);
  Cria_Raiz(&pt, item);
  getchar();
  return pt;
}

AB * insere_esquerda(AB * pt, AB * pai)
{
  char item;
  printf("entre com o valor do pai onde item sera inserido a esq: ");
  scanf(" %c",&item);
  pai = NULL;
  Busca(pt, item, &pai);
  if (pai == NULL)
    printf("item nao encontrado \n");
  else {
    printf("entre com o valor do item a ser inserido: ");
    scanf(" %c",&item);
    InserirFilhoaEsquerda(pt,pai,item);
  }
  getchar();

  return pt;
}

AB * insere_direita(AB * pt, AB * pai)
{
  char item;
  printf("entre com o valor do pai onde item sera inserido: ");
  scanf(" %c",&item);
  pai = NULL;
  Busca(pt, item, &pai);
  if (pai == NULL)
    printf("item nao encontrado \n");
  else {
    printf("entre com o valor do item a ser inserido: ");
    scanf(" %c",&item);
    InserirFilhoaDireita(pt,pai,item);
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
  st=Remove_FolhaV1(&pt,item);
  if (st == 1)
    printf("\n elemento removido \n");
  else printf("\n elemento nao exite ou nao eh nodo folha");
  getchar();
  return pt;
}

void encontrar_altura(AB * pt)
{
  int * maior = (int*)malloc(sizeof(int));
  *maior = 0;
  achar_altura(pt,maior);
  printf("Altura da arvore: %d\n", *maior);
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
       "\t 6- busca elemento \n" 
       "\t 7- libera arvore \n" 
       "\t 8- remove folha \n"
       "\t 9 - Exibe maior elemento \n"
       "\t 10 - Exibir nodos nao folhas\n"
       "\t 11 - Exibir altura da arvore\n"
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
     case 6:break;
     case 7: Ptab=Libera_Arvore(Ptab);
             if (E_Vazia(Ptab))
             printf("arvore vazia \n");
             getchar();
            break;
     case 8: Ptab = remove_folha(Ptab);
            break;            
     case 9:achar_maior_elemento(Ptab, aux);
       printf("Maior elemento: %c\n\n", *aux);
            getchar();
            break;
     case 10: exibir_nao_folha(Ptab);
       break;
     case 11: encontrar_altura(Ptab);
       break;
     default: printf("opcao errada, entre novamente \n");  
              getchar();  
    }            
     }while (opcao != 0);
     
      
}
   
 

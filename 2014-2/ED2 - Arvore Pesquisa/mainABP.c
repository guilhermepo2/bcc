#include<stdio.h>
#include<stdlib.h>
#include"ABP.h"

void encontrar_altura(ABP * pt)
{
  int * maior = (int*)malloc(sizeof(int));
  *maior = 0;
  achar_altura(pt,maior);
  printf("Altura da arvore: %d\n", *maior);
}

void main_exibe_soma(ABP * pt)
{
  int soma = 0;
  exibe_soma(pt, &soma);
  printf("Soma dos elementos: %d\n\n", soma);
}

void main_exibe_media(ABP * pt)
{
  int soma = 0, elem = 0;
  exibe_media(pt, &soma, &elem);
  float media = (soma/elem);
  printf("Media dos elementos: %.2f\n\n", media);
}

void main_exibe_maior(ABP * pt)
{
  int maior = 0;
  exibe_maior(pt, &maior);
  printf("Maior elemento: %d.\n\n", maior);
}

void main_exibe_menor(ABP * pt)
{
  int menor = 999;
  exibe_menor(pt, &menor);
  printf("Maior elemento: %d.\n\n", menor);
}

int main()
{
   ABP *Ptabp, *pt;
   Registro reg;
   int opcao, chave, st;
   do{ system("cls");
     printf(" selelcione uma opcao:\n" 
	    "\t 1- inicializa arvore \n"        
	    "\t 2- insere elemento \n" 
	    "\t 3- exibe arvore em ordem crescente \n"
	    "\t 4- busca elemento \n" 
	    "\t 5- remove nodo\n" 
	    "\t 6- libera arvore  \n"
	    "\t 7 - exibe arvore em pre ordem esquerda\n"
	    "\t 8 - exibe arvore em pos ordem esquerda  \n"
	    "\t 9 - exibe arvore em ordem decrescente  \n"
	    "\t 10 - encontrar altura da arvore \n"
	    "\t 11 - encontrar a soma dos elementos \n"
	    "\t 12 - encontrar a media dos elementos\n"
	    "\t 13 - exibir maior\n"
	    "\t 14 - exibir menor\n"
	    "\t 15 - exibir folhas\n"
	    
	    "\t 0-termina programa \n");
     scanf("%d", &opcao);
     //      executafuncao(opcao, Ptab);
     switch (opcao){
     case 1: Inicializa_ABP(&Ptabp);
       break;
     case 2: printf("entre com o valor do nodo a ser inserido: ");
       printf("\n nome:");
       fflush(stdin);
       scanf("%s", reg.Info.nome);
       printf("\n idade: ");
       scanf("%d", &reg.Info.idade);
             printf("\n chave: ");
             scanf("%d", &reg.Chave);
             Insere_nodo(&Ptabp,reg);
             break;
     case 3:Exibe_Arvore_Ordem_Crescente(Ptabp);
       fflush(stdin);
       getchar();
       break;
	    
     case 4: printf(" \n entre com a chave a ser pesquisada: ");
       scanf("%d", &chave);
       pt = Pesquisa_ABP(Ptabp,chave);
       Imprime_nodo(pt);
             getchar();
             break;
             
     case 5:fflush(stdin);
       printf("entre com a chave a ser removida: ");
       scanf("%d",&chave);
       printf("\n leu a chave %d", chave);
       fflush(stdin);
       getchar();             
            Remove_nodo(&Ptabp,chave); 
            printf("\n sai do remove, PTABP = %p", Ptabp); 
            getchar();          
            break; 
            
     case 6:Ptabp = Libera_Arvore(Ptabp);
       if (E_Vazia(Ptabp))
	 printf("arvore vazia \n");
       fflush(stdin);
       getchar();
       break;
       
       
       
     case 7:
       Exibe_Arvore_PreOrdem_Esquerda(Ptabp);
       fflush(stdin);
       getchar();
       break;

     case 8:
       Exibe_Arvore_PosOrdem_Esquerda(Ptabp);
       fflush(stdin);
       getchar();
       break;

     case 9:
       Exibe_Arvore_Ordem_Decrescente(Ptabp);
       fflush(stdin);
       getchar();
       break;

     case 10:
       encontrar_altura(Ptabp);
       break;
     case 11:
       main_exibe_soma(Ptabp);
       break;
     case 12:
       main_exibe_media(Ptabp);
       break;
     case 13:
       main_exibe_maior(Ptabp);
       break;
     case 14:
       main_exibe_menor(Ptabp);
       break;
     case 15:
       exibe_folhas(Ptabp);
       break;
       
     default: printf("opcao errada, entre novamente \n");  
       fflush(stdin);
       getchar();  
     }            
   }while (opcao != 0);
   
   
}; 



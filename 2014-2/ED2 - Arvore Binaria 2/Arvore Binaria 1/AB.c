#include"AB.h"
#include <stdio.h>
#include <stdlib.h>


struct nodo{
             struct nodo* esq;
             char  info;
             struct nodo* dir;
            };

void Cria_Arvore(AB **Ptab)
{
     *Ptab = NULL;
}

int Cria_Raiz(AB **Ptab, char item)
{
    
   *Ptab=(AB*)malloc(sizeof(AB));
   if (*Ptab != NULL)
   {
      (*Ptab)->esq = NULL;
      (*Ptab)->info = item;
      (*Ptab)->dir = NULL;
      return 1;
   };
   return 0;
}

void Exibe_Arvore(AB *Ptab)
{
  
  if (Ptab == NULL)
      return;

  printf("%c ",Ptab->info);
  Exibe_Arvore(Ptab->esq);
  Exibe_Arvore(Ptab->dir);
}

   
int E_Vazia(AB *Ptab)
{
  if (Ptab == NULL)
      return 1;
  else return 0;
}

int InserirFilhoaDireita(AB *Ptab, AB *pai, char item)
{
   AB *pt;
   if(pai != NULL && pai->dir == NULL)
   {
      pt = (AB*) malloc(sizeof(AB));
      if (pt == NULL)
        return 0;
      pt->esq = NULL;
      pt->info = item;
      pt->dir = NULL;
      pai->dir = pt;
      return 1;
   }
   return 0;
}
  
int InserirFilhoaEsquerda(AB *Ptab, AB *pai, char item)
{
   AB *pt;
   if(pai != NULL && pai->esq == NULL)
   {
      pt = (AB*) malloc(sizeof(AB));
      if (pt == NULL)
        return 0;
      pt->esq = NULL;
      pt->info = item;
      pt->dir = NULL;
      pai->esq = pt;
      return 1;
   }
   return 0;
}

 
void Busca(AB *Ptab, char item, AB **pt)
{
        
       if (Ptab == NULL || *pt != NULL)
         return;
       if (Ptab->info != item  )
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

void Localiza_Pai(AB *Ptab, char item, AB  **pt, AB **pai)
{
   
}


int Remove_Folha(AB **Ptab, char item)
{
   AB *pai, *ptnodo;
   
   if(*Ptab != NULL && (*Ptab)->info == item) // remove raiz
   {
       if((*Ptab)->esq == NULL && (*Ptab)->dir == NULL)
       {
          free(*Ptab);
          *Ptab = NULL;
          return 1;
       }            
   }
   
   if (*Ptab != NULL)
        {  
           ptnodo = NULL;
           pai = NULL;
            
           Localiza_Pai(*Ptab,item,&ptnodo, &pai );
	   
           if (pai!=NULL)
           {
               printf("\n localizou pai-- %c", (pai)->info);
               fflush(stdin);
               getchar();
           }
	   
           if (ptnodo == NULL) 
              return 0; // nodo nao existe
	   
           if(ptnodo->esq == NULL && ptnodo->dir == NULL)
                if (pai->esq == ptnodo)
               {
                  free(pai->esq);
                  pai->esq = NULL;
                  return 1;
                }
               else  
                {
                free(pai->dir);
                pai->dir = NULL;
                return 1;
                }
           else return 0;  // nodo nao folha
        }
   else return 0; //nodo nao existe
}    
/*-----------------------------------------------*/

//Outra versao para localiza e remove folha mais compacta

// QUESTAO 2 DA LISTA - FUNÇÃO LOCALIZA PAI
void Localiza_PaiV1(AB *Ptab, char item, AB  *** pt)
{
  if(Ptab->dir == NULL && Ptab->esq == NULL)
    return;
  
  if(Ptab->dir != NULL)
    {
      if(Ptab->dir->info == item)
	{
	  (*pt) = &(Ptab->dir);
	  return;
	}
      else
	{
	  Localiza_PaiV1(Ptab->dir,item,pt);
	}
    }
  
  if(Ptab->esq != NULL)
    {
      if(Ptab->esq->info == item)
	{
	  (*pt) = &(Ptab->esq);
	  return;
	}
      else
	{
	  Localiza_PaiV1(Ptab->esq,item,pt);
	}
    }
  
}


int Remove_FolhaV1(AB **Ptab, char item)
{
   AB ** pai;
    
   if(*Ptab != NULL && (*Ptab)->info == item) // remove raiz
   {
       if((*Ptab)->esq == NULL && (*Ptab)->dir == NULL)
       {
          free(*Ptab);
          *Ptab = NULL;
          return 1;
       }            
   }
   
   
   if (*Ptab != NULL)
        {   
           pai = NULL;
           Localiza_PaiV1(*Ptab,item, &pai );
           
           if (pai != NULL)
           {
              printf("localizou %c", (*pai)->info);
              if((*pai)->esq == NULL && (*pai)->dir == NULL)
               {
                  free(*pai);
                 *pai = NULL;
                  return 1;
               }
               
             else return 0;  //nodo nao folha
           }
        
          else return 0; // nodo nao existe
  }
 else return 0; //arvore vazia
}

//QUESTAO 3.1 - ACHAR MAIOR ELEMENTO DA ARVORE

void achar_maior_elemento(AB * ptab, char * maior)
{
  if(ptab!= NULL)
    {
      if(ptab->info > *maior)
	*maior = ptab->info;
      achar_maior_elemento(ptab->esq,maior);
      achar_maior_elemento(ptab->dir,maior);
    }
}

//3.4 EXIBIR APENAS OS NODOS NÃO FOLHAS USANDO CAMINHAMENTO CENTRAL À ESQUERDA

void exibir_nao_folha(AB *ptab)
{
  
  if (ptab == NULL)
      return;
  
  exibir_nao_folha(ptab->esq);
  if(ptab->esq != NULL || ptab->dir != NULL)
    printf("%c ",ptab->info);
  exibir_nao_folha(ptab->dir);
  
  printf("\n");
}

//3.2 EXIBIR A ALTURA DA ARVORE

void achar_altura_aux(AB * ptab, int nivel, int * maior)
{
  if(ptab!=NULL)
    {
      if(nivel > *maior)
	*maior = nivel;
      achar_altura_aux(ptab->esq,(nivel+1),maior);
      achar_altura_aux(ptab->dir,(nivel+1), maior);
    }
}

void achar_altura(AB * ptab, int * maior)
{
  achar_altura_aux(ptab,0,maior);
}

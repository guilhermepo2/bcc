#include"ABP.h"
#include <stdio.h>
#include<stdlib.h>


struct nodoABP {
               Registro reg;
               struct nodoABP *esq; 
               struct nodoABP *dir;
               };


void Inicializa_ABP(ABP **Ptabp)
{
     *Ptabp = NULL;
}

int Insere_nodo(ABP **Ptabp, Registro reg)
{
    ABP *pt;
    if (*Ptabp == NULL)
    {
      pt=(ABP*)malloc(sizeof(ABP));
      if (pt == NULL)
       return -1;
   
      pt->esq = NULL;
      pt->reg = reg;
      pt->dir = NULL;
      *Ptabp = pt;   
      return 1;
    }
   
   if(reg.Chave < (*Ptabp)->reg.Chave)
      return Insere_nodo(&((*Ptabp)->esq),reg);
   else if (reg.Chave > (*Ptabp)->reg.Chave)
           return Insere_nodo(&((*Ptabp)->dir),reg);
        else return 0;
}

void antecessor(ABP *ptnodo, ABP **pai)
{
  printf("\n entrou no antecessor");
  if ((*pai)->dir != NULL)
    antecessor(ptnodo,&((*pai)->dir));  
  else {
    ptnodo->reg=(*pai)->reg;
    ptnodo = *pai;
    *pai =  (*pai)->esq;
    free(ptnodo);
  }             
  
}

int Remove_nodo(ABP **Ptabp, int chave)
{
  ABP *aux;
  
  printf("\n entrando no remove, Ptabp = %p",*Ptabp);
  getchar();
  if (*Ptabp == NULL)
    return 0;
  printf("valor da chave em remove = %d", (*Ptabp)->reg.Chave);
  getchar();
  if (chave < (*Ptabp)->reg.Chave)
    Remove_nodo(&((*Ptabp)->esq),chave);
  else if (chave > (*Ptabp)->reg.Chave)
    Remove_nodo(&((*Ptabp)->dir), chave);
  else if ((*Ptabp)->dir == NULL)
    {
      printf("\entrou remove direita");
      aux = *Ptabp;
      *Ptabp = (*Ptabp)->esq;
      free(aux);
      return 1;
      
      getchar();
    }
  else if ((*Ptabp)->esq == NULL)
    {
      aux = *Ptabp;
      *Ptabp = (*Ptabp)->dir;
      free(aux);
      return 1;
    }
  else antecessor(*Ptabp,&((*Ptabp)->esq));
  
}


//4.1 MOSTRAR ALTURA DA ARVORE

void achar_altura_aux(ABP * ptab, int nivel, int * maior)
{
  if(ptab!=NULL)
    {
      if(nivel > *maior)
	*maior = nivel;
      achar_altura_aux(ptab->esq,(nivel+1),maior);
      achar_altura_aux(ptab->dir,(nivel+1), maior);
    }
}

void achar_altura(ABP * ptab, int * maior)
{
  achar_altura_aux(ptab,0,maior);
}

//4.2 PESQUISAR ELEMENTO E MOSTRAR SEU NIVEL NA ARVORE


//4.3 EXIBIR ELEMENTOS EM PRE ORDEM ESQUERDA
void Exibe_Arvore_PreOrdem_Esquerda(ABP *Ptabp)
{
  
  if (Ptabp == NULL)
    return;
  
  printf("%4d ",Ptabp->reg.Chave);
  Exibe_Arvore_PreOrdem_Esquerda(Ptabp->esq);
  Exibe_Arvore_PreOrdem_Esquerda(Ptabp->dir);
}

//4.4 EXIBIR ELEMENTOS EM ORDEM CRESCENTE
void Exibe_Arvore_Ordem_Crescente(ABP *Ptabp)
{
  
  if (Ptabp == NULL)
    return;
  
  Exibe_Arvore_Ordem_Crescente(Ptabp->esq);
  printf("%4d ",Ptabp->reg.Chave);
  Exibe_Arvore_Ordem_Crescente(Ptabp->dir);
}

//4.5 EXIBIR ELEMENTOS POS ORDEM ESQUERDA
void Exibe_Arvore_PosOrdem_Esquerda(ABP *Ptabp)
{
  
  if (Ptabp == NULL)
    return;
  
  Exibe_Arvore_PosOrdem_Esquerda(Ptabp->esq);
  Exibe_Arvore_PosOrdem_Esquerda(Ptabp->dir);
  printf("%4d ",Ptabp->reg.Chave);
}

//4.6 EXIBIR ELEMENTOS EM ORDEM DECRESCENTE
void Exibe_Arvore_Ordem_Decrescente(ABP *Ptabp)
{
  
  if (Ptabp == NULL)
    return;
  
  Exibe_Arvore_Ordem_Decrescente(Ptabp->dir);
  printf("%4d ",Ptabp->reg.Chave);
  Exibe_Arvore_Ordem_Decrescente(Ptabp->esq);
}

//4.7 EXIBIR A SOMA DOS ELEMENTOS DA ARVORE
void exibe_soma(ABP * ptabp, int * soma)
{
  if(ptabp!=NULL)
    {
      *soma += ptabp->reg.Chave;
      exibe_soma(ptabp->esq,soma);
      exibe_soma(ptabp->dir,soma);
    }
}

//4.8 EXIBIR A MEDIA DOS ELEMENTOS NA ARVORE
void exibe_media(ABP * ptabp, int * soma, int * elementos)
{
  if(ptabp!=NULL)
    {
      *soma += ptabp->reg.Chave;
      *elementos += 1;
      exibe_media(ptabp->esq,soma,elementos);
      exibe_media(ptabp->dir,soma,elementos);
    }
}

//4.9 EXIBIR MAIOR ELEMENTO DA LISTA
void exibe_maior(ABP * ptabp, int * maior)
{
  if(ptabp!=NULL)
    {
      if(ptabp->reg.Chave > (*maior))
	*maior = ptabp->reg.Chave;
      exibe_maior(ptabp->esq,maior);
      exibe_maior(ptabp->dir,maior);
    }
}

//4.10 EXIBIR MENOR ELEMENTO DA LISTA
void exibe_menor(ABP * ptabp, int * menor)
{
  {
  if(ptabp!=NULL)
    {
      if(ptabp->reg.Chave < (*menor))
	*menor = ptabp->reg.Chave;
      exibe_menor(ptabp->esq,menor);
      exibe_menor(ptabp->dir,menor);
    }
}
}

//4.11 EXIBIR APENAS NOS FOLHAS
void exibe_folhas(ABP * ptabp)
{
  
  if (ptabp == NULL)
    return;

  if(ptabp->esq == NULL && ptabp->dir == NULL)
    printf("%4d ",ptabp->reg.Chave);
  exibe_folhas(ptabp->esq);
  exibe_folhas(ptabp->dir);
}

void Teste(ABP * Ptabp)
{
  printf("\n raiz = %d", Ptabp->reg.Chave);
  getchar();
}

int E_Vazia(ABP *Ptabp)
{
  if (Ptabp == NULL)
    return 1;
  else return 0;
}

ABP* Libera_Arvore(ABP *Ptabp)
{
  if (Ptabp!=NULL)
    {
      Libera_Arvore(Ptabp->esq); /* libera subarvore  a esq */
      Libera_Arvore(Ptabp->dir); /* libera subarvore a dir */
      free(Ptabp); /* libera raiz */
    }
  return NULL;
}

ABP *Pesquisa (ABP *Ptabp, int chave)
{
  if (Ptabp == NULL)
    return NULL;
  
  if (chave < Ptabp->reg.Chave)
    return Pesquisa (Ptabp->esq, chave);
  else if (chave > Ptabp->reg.Chave)
    return Pesquisa (Ptabp->dir,chave);
  else return Ptabp;
}

ABP *Pesquisa_ABP (ABP *Ptabp, int chave)
{
  if (Ptabp == NULL)
    return NULL;
  
  if (chave == Ptabp->reg.Chave)
    return Ptabp;
  else  if (chave < Ptabp->reg.Chave)
    return Pesquisa_ABP(Ptabp->esq, chave);
  else return Pesquisa_ABP(Ptabp->dir,chave);     
}

void Imprime_nodo(ABP *Ptabp)
{
  printf("nodo pesquisado = %s -- %d -- %d", Ptabp->reg.Info.nome,Ptabp->reg.Info.idade, Ptabp->reg.Chave);
  getchar();
}

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "header.h"
#include "header_windows.h"

struct disciplina
{
  char * nome;
  char * codigo;
  int creditos;
};

struct nodo_disciplina
{
  struct nodo_disciplina * anterior;
  struct disciplina info;
  struct nodo_disciplina * proximo;
};

/*
Tipo Abstrato de Dados: Lista Duplamente Encadeada - para que seja possivel fazer a inserção ordenada de elementos.
*/

DISCIPLINA * disciplina_criar_lista(void)
{
  return NULL;
}

disciplina_nodo * disciplina_criar_disciplina(char * nome, char * codigo, int creditos)
{
  disciplina_nodo * disciplina;
  size_t tamanho_s;
  disciplina = (disciplina_nodo*)malloc(sizeof(disciplina_nodo));
  tamanho_s = strlen(nome);
  disciplina->nome = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(disciplina->nome,nome);

  tamanho_s = strlen(codigo);
  disciplina->codigo = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(disciplina->codigo,codigo);

  disciplina->creditos = creditos;
  
  return disciplina;
}

//Função utilizada na inicialiação do programa, ao criar uma lista usando os dados que estão em um documento de texto
DISCIPLINA * disciplina_inserir_disciplina_arquivo(DISCIPLINA * ptl, disciplina_nodo * elemento)
{
  DISCIPLINA * novo;
  novo = (DISCIPLINA*)malloc(sizeof(DISCIPLINA));
  if (novo == NULL)
    return ptl;
  novo->info = *elemento;
  //Caso a lista seja vazia, o elemento é inserido
  if(ptl == NULL)
    {
      novo->proximo = NULL;
      novo->anterior = NULL;
      ptl = novo;
    }
  else //caso a lista nao seja vazia
    {
      DISCIPLINA * aux = ptl;
      while(strcmp(elemento->nome,aux->info.nome)>0) //vai procurar por nome tal que: o que vá ser inserido deva ficar antes do que está sendo procurado.
	{
	  if(aux->proximo == NULL)
	    break;
	  aux = aux->proximo;
	}
      if(strcmp(elemento->nome,aux->info.nome)<0) //verificando se o nome a ser inserido vem realmente antes do nome apontado por aux.
	{
	  aux=aux->anterior;
	}
      if(aux==NULL) //caso o nome que seja inserido venha a ser o primeiro da lista
	{
	  novo->proximo = ptl;
	  novo->anterior = NULL;
	  novo->proximo->anterior = novo;
	  ptl = novo;
	}
      else
	{
	  novo->proximo = aux->proximo;
	  aux->proximo = novo;
	  novo->anterior = aux;
	  if(novo->proximo != NULL)
	    novo->proximo->anterior = novo;
	}
    }
  return ptl;
}

//Função se inserção ordenada para casos gerais.
DISCIPLINA * disciplina_inserir_disciplina(DISCIPLINA * ptl, disciplina_nodo * elemento)
{
  DISCIPLINA * novo;
  novo = (DISCIPLINA*)malloc(sizeof(DISCIPLINA));
  if (novo == NULL)
    return ptl;
  novo->info = *elemento;
  //Caso a lista seja vazia, o elemento é inserido
  if(ptl == NULL)
    {
      novo->proximo = NULL;
      novo->anterior = NULL;
      ptl = novo;
    }
  else  //caso a lista nao seja vazia
    {
      DISCIPLINA * aux = ptl;
      while(strcmp(elemento->nome,aux->info.nome)>0) //vai procurar por nome tal que: o que vá ser inserido deva ficar antes do que está sendo procurado.
	{
	  if(aux->proximo == NULL)
	    break;
	  aux = aux->proximo;
	}
      if(strcmp(elemento->nome,aux->info.nome)<0) //verificando se o nome a ser inserido vem realmente antes do nome apontado por aux.
	{
	  aux=aux->anterior;
	}
      if(aux==NULL) //caso o nome que seja inserido venha a ser o primeiro da lista
	{
	  novo->proximo = ptl;
	  novo->anterior = NULL;
	  novo->proximo->anterior = novo;
	  ptl = novo;
	}
      else
	{
	  novo->proximo = aux->proximo;
	  aux->proximo = novo;
	  novo->anterior = aux;
	  if(novo->proximo != NULL)
	    novo->proximo->anterior = novo;
	}
    }
  return ptl;
}

DISCIPLINA * disciplina_remover_disciplina(DISCIPLINA * ptl, char * chave)
{
  if (ptl == NULL)
    return ptl;
  DISCIPLINA * atual = ptl;
  while(atual != NULL && strcmp(chave,atual->info.codigo)!=0)
    atual = atual->proximo;
  if (atual == NULL)
    return ptl;
  if (atual == ptl)
    {
      if(ptl->proximo == NULL)
	ptl = NULL;
      else
	{
	  ptl = atual->proximo;
	  ptl->anterior = NULL;
	} 
    }
  else
    {
      atual->anterior->proximo = atual->proximo;
      if(atual->proximo != NULL)
	atual->proximo->anterior = atual->anterior;
    }
  free(atual);
  return ptl;
}

void disciplina_imprimir_disciplinas(DISCIPLINA * ptl)
{
  DISCIPLINA * aux = ptl;
  while(aux!=NULL)
    {
      printf("Disciplina: ");
      puts(aux->info.nome);
      printf("Codigo: ");
      puts(aux->info.codigo);
      printf("Creditos: %d", aux->info.creditos);
      printf("\n\n");
      aux = aux->proximo;
    }
}

//Função que passa os dados de um arquivo para uma lista na inicialização do programa.
DISCIPLINA * disciplina_arquivo_para_lista(void)
{
  DISCIPLINA * lista = disciplina_criar_lista();
  disciplina_nodo * nova_disciplina = NULL;
  FILE * pArq;
  char linha[100];
  char * nome, * codigo, * creditos_aux;
  int creditos;
  pArq = fopen("disciplinas.txt","r");
  
  while((fgets(linha,sizeof(linha),pArq))!=NULL)
    {
      nome = strtok(linha,",");
      codigo = strtok(NULL,",");
      creditos_aux = strtok(NULL,"\n");
      creditos = atoi(creditos_aux);
      
      nova_disciplina = disciplina_criar_disciplina(nome,codigo,creditos);
      lista = disciplina_inserir_disciplina_arquivo(lista,nova_disciplina);
    }
  fclose(pArq);
  free(nova_disciplina);
  return lista;
}

//Função que salva a lista em um arquivo texto
void disciplina_gravar_em_arquivo(DISCIPLINA * ptl)
{
  DISCIPLINA * aux = ptl;
  FILE * pArq;
  pArq = fopen("disciplinas.txt","w");
  while(aux!=NULL)
    {
      fprintf(pArq,"%s,%s,%d\n", aux->info.nome,aux->info.codigo,aux->info.creditos);
      aux = aux->proximo;
    }
  free(aux);
  fclose(pArq);
}


//Função que verifica a existência de uma disciplina.
//Utilizada na hora de atribuir uma disciplina a ser cursada para um aluno.
int verificar_existencia_disciplina(DISCIPLINA * ptl, char * codigo, char * disciplina)
{
  DISCIPLINA * aux = ptl;
  while(aux!=NULL && strcmp(codigo,aux->info.codigo)!=0)
    {
      aux = aux->proximo;
    }
  if(aux == NULL)
    return 0;
  else
    {
      strcpy(disciplina,aux->info.nome);
      return 1;
    }
}

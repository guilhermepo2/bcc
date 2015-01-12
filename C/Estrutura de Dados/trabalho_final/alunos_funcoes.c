#include<stdlib.h>
#include<stdio.h>
#include "header.h"
#include "header_windows.h"
#include<string.h>

struct aluno
{
  char * nome;
  char * matricula;
};

struct nodo_aluno
{
  struct nodo_aluno * anterior;
  struct aluno info;
  struct nodo_aluno * proximo;
};

/*
Tipo Abstrato de Dados: Lista Duplamente Encadeada - para que seja possivel fazer a inserção ordenada de elementos.
*/

//Função que cria a lista atribuindo o endereço NULL a ela.
ALUNO * aluno_criar_lista(void)
{
  return NULL;
}

//Função que cria um novo nodo de aluno para que este seja inserido na lista.
aluno_nodo * aluno_criar_aluno(char * nome, char * matricula)
{
  aluno_nodo * aluno;
  size_t tamanho_s;
  aluno = (aluno_nodo*)malloc(sizeof(aluno_nodo));
  
  tamanho_s = strlen(nome);
  aluno->nome = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(aluno->nome,nome);

  tamanho_s = strlen(matricula);
  aluno->matricula = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(aluno->matricula,matricula);

  return aluno;
}


//Função que insere um aluno na lista quando a lista está sendo preenchida de um arquivo.

ALUNO * aluno_inserir_aluno_arquivo(ALUNO * ptl, aluno_nodo * elemento)
{
  ALUNO * novo;
  novo = (ALUNO*)malloc(sizeof(ALUNO));
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
  else
    {
      ALUNO * aux = ptl;
      while(strcmp(elemento->nome,aux->info.nome)>0)
	{
	  if(aux->proximo == NULL)
	    break;
	  aux = aux->proximo;
	}
      if(strcmp(elemento->nome,aux->info.nome)<0)
	{
	  aux=aux->anterior;
	}
      if(aux==NULL)
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

//Função que faz a inserção de um aluno na lista para casos gerais.

ALUNO * aluno_inserir_aluno(ALUNO * ptl, aluno_nodo * elemento)
{
  ALUNO * novo;
  novo = (ALUNO*)malloc(sizeof(ALUNO));
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
      ALUNO * aux = ptl;
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
  
  //criando arquivo individual para cada aluno (este é o motivo de haver funções diferentes, como a função acima)
  char buf[100];
  snprintf(buf,sizeof(buf), "alunos/%s.txt", elemento->matricula);
  FILE * arq = fopen(buf,"w");
  fprintf(arq,"%s,%s\n", novo->info.nome,novo->info.matricula);
  fclose(arq);
  //salvando a lista no arquivo
  aluno_gravar_em_arquivo(ptl);
  return ptl;
}

//Função que faz a remoção de um aluno através do seu código de matricula.

ALUNO * aluno_remover_aluno(ALUNO * ptl, char * chave)
{
  if (ptl == NULL)
    return ptl;
  ALUNO * atual = ptl;
  while(atual != NULL && strcmp(chave,atual->info.matricula)!=0)
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

//Função que faz a impressão dos alunos.

void aluno_imprimir_alunos(ALUNO * ptl)
{
  ALUNO * aux = ptl;
  while(aux!=NULL)
    {
      printf("Aluno: ");
      puts(aux->info.nome);
      printf("Matricula: ");
      puts(aux->info.matricula);
      printf("\n");
      aux = aux->proximo;
    }
}

// Função que é executada no inicio do programa.
// Seu intuito é passar o banco de dados do arquivo texto para o programa logo no seu inicio.
ALUNO * aluno_arquivo_para_lista(void)
{
  ALUNO * lista = aluno_criar_lista();
  aluno_nodo * novo_aluno = NULL;
  FILE * pArq;
  char linha[100];
  char * aluno, * matricula;
  pArq = fopen("alunos.txt","r");
  while((fgets(linha,sizeof(linha),pArq))!=NULL)
    {
      aluno = strtok(linha,",");
      matricula = strtok(NULL,"\n");
      novo_aluno = aluno_criar_aluno(aluno,matricula);
      lista = aluno_inserir_aluno_arquivo(lista,novo_aluno);
    }
  fclose(pArq);
  free(novo_aluno);
  return lista;
}

//Função que vai gravar a lista em um arquivo texto.

void aluno_gravar_em_arquivo(ALUNO * ptl)
{
  ALUNO * aux = ptl;
  FILE * pArq;
  pArq = fopen("alunos.txt","w");
  while(aux!=NULL)
    {
      fprintf(pArq,"%s,%s\n", aux->info.nome,aux->info.matricula);
      aux = aux->proximo;
    }
  free(aux);
  fclose(pArq);
}



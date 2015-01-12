#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "header.h"
#include "header_windows.h"
#define MAT 10

struct editar
{
  int estado; // 0 = cursando, 1 = aprovado, 2 = reprovado
  char * nome; //nome da materia
  char * codigo; //codigo da materia
  int nota; //nota do aluno;
  int vezes_cursadas; //quantas vezes o aluno cursou a disciplina
};

struct nodo_editar
{
  struct editar info;
  struct nodo_editar * proximo;
};

//Tipo Abstrato de Dados: - Lista Simplesmente Encadeada - por não haver nenhuma necessidade de inserção ordenada ou outra condição específica.

EDICAO * edicao_criar_lista(void)
{
  return NULL;
}

//Função utilizada para criar a disciplina quando o programa estiver começando a sua execução, ou seja, passando os dados do arquivo para a lista.
edicao_nodo * edicao_criar_disciplina(int estado,char * nome, char * codigo, int nota, int vezes_cursadas)
{
  edicao_nodo * disciplina_cursando;
  size_t tamanho_s;
  disciplina_cursando = (edicao_nodo*)malloc(sizeof(edicao_nodo));
  tamanho_s = strlen(nome);
  disciplina_cursando->nome = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(disciplina_cursando->nome,nome);
  
  tamanho_s = strlen(codigo);
  disciplina_cursando->codigo = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(disciplina_cursando->codigo,codigo);
  
  disciplina_cursando->estado = estado;
  disciplina_cursando->nota = nota;
  disciplina_cursando->vezes_cursadas = vezes_cursadas;
  
  return disciplina_cursando;
}

//Função utilizada para criar uma disciplina a ser cursada quando o aluno nunca a cursou antes.
edicao_nodo * edicao_criar_disciplina_cursando(char * nome, char * codigo)
{
  edicao_nodo * disciplina_cursando;
  size_t tamanho_s;
  disciplina_cursando = (edicao_nodo*)malloc(sizeof(edicao_nodo));
  tamanho_s = strlen(nome);
  disciplina_cursando->nome = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(disciplina_cursando->nome,nome);
  
  tamanho_s = strlen(codigo);
  disciplina_cursando->codigo = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(disciplina_cursando->codigo,codigo);
  
  disciplina_cursando->estado = 0;
  disciplina_cursando->nota = 0;
  disciplina_cursando->vezes_cursadas = 0;
  
  return disciplina_cursando;
}

//Função a ser utilizada para criar uma disciplina a ser cursada quando o aluno já a cursou e foi reprovado.
edicao_nodo * edicao_criar_disciplina_reprovado(char * nome, char * codigo, int vezes_cursadas)
{
  edicao_nodo * disciplina_cursando;
  size_t tamanho_s;
  disciplina_cursando = (edicao_nodo*)malloc(sizeof(edicao_nodo));
  tamanho_s = strlen(nome);
  disciplina_cursando->nome = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(disciplina_cursando->nome,nome);
  
  tamanho_s = strlen(codigo);
  disciplina_cursando->codigo = (char*)malloc(sizeof(char)*(tamanho_s+1));
  strcpy(disciplina_cursando->codigo,codigo);
  
  disciplina_cursando->estado = 0;
  disciplina_cursando->nota = 0;
  disciplina_cursando->vezes_cursadas = vezes_cursadas;
  
  return disciplina_cursando;
}

//Função que insere um nodo de disciplina na lista.
EDICAO * edicao_inserir_disciplina_lista(EDICAO * ptl, edicao_nodo * elemento)
{
  EDICAO * novo;
  novo = (EDICAO*)malloc(sizeof(EDICAO));
  if(novo == NULL)
    return ptl;
  novo->info = *elemento;
  if(ptl == NULL)
    {
      novo->proximo = NULL;
      ptl = novo;
    }
  else
    {
      novo->proximo = ptl;
      ptl = novo;
    }
  return ptl;
}


//Função que passa os dados do arquivo texto para uma lista dentro do programa.
EDICAO * edicao_arquivo_para_lista(char * matricula)
{
  EDICAO * lista = edicao_criar_lista();
  edicao_nodo * novo_nodo = NULL;
  FILE * arq;
  char buf[100];
  snprintf(buf,sizeof(buf), "alunos/%s.txt", matricula);
  arq = fopen(buf,"r");
  char linha[100];
  //informacoes do nodo
  char * nome, * codigo, * estado_aux, * nota_aux, * vezes_cursadas_aux;
  int estado, nota, vezes_cursadas;

  fgets(linha,sizeof(linha),arq);
  while((fgets(linha,sizeof(linha),arq)!=NULL))
    {
      estado_aux = strtok(linha,",");
      nome = strtok(NULL,",");
      codigo = strtok(NULL,",");
      nota_aux = strtok(NULL,",");
      vezes_cursadas_aux = strtok(NULL,"\n");
      estado = atoi(estado_aux);
      nota = atoi(nota_aux);
      vezes_cursadas = atoi(vezes_cursadas_aux);

      novo_nodo = edicao_criar_disciplina(estado,nome,codigo,nota,vezes_cursadas);
      lista = edicao_inserir_disciplina_lista(lista,novo_nodo);
    }
    fclose(arq);
    free(novo_nodo);
    return lista;
  
}

//Função que salva a lista na forma de arquivo.
void edicao_gravar_em_arquivo(EDICAO * disciplinas_cursadas, char * nome, char * matricula)
{
  EDICAO * aux = disciplinas_cursadas;
  
  char buf[100];
  snprintf(buf,sizeof(buf), "alunos/%s.txt", matricula);

  FILE * arq = fopen(buf,"w");
  fprintf(arq,"%s,%s\n",nome,matricula);
  
  while(aux!=NULL)
    {
      fprintf(arq,"%d,%s,%s,%d,%d\n",aux->info.estado,aux->info.nome,aux->info.codigo,aux->info.nota,aux->info.vezes_cursadas);
      aux=aux->proximo;
    }
  free(aux);
  fclose(arq);
}

void edicao_imprimir_disciplinas_aprovadas(EDICAO * disciplinas)
{
  EDICAO * aux = disciplinas;
  while(aux!=NULL)
    {
      if(aux->info.estado == 1)
	{
	  printf("Nome da Materia: %s\n",aux->info.nome);
	  printf("Codigo: %s\n", aux->info.codigo);
	  printf("Estado: ");
	  if(aux->info.estado == 0)
	    printf("Cursando\n");
	  if(aux->info.estado == 1)
	    printf("Aprovado\n");
	  if(aux->info.estado == 2)
	    printf("Reprovado\n");
	  printf("Nota: %d\n",aux->info.nota);
	  printf("\n");
	}
      aux = aux->proximo;
    }
}

void edicao_imprimir_disciplinas_reprovadas(EDICAO * disciplinas)
{
  EDICAO * aux = disciplinas;
  while(aux!=NULL)
    {
      if(aux->info.estado == 2)
	{
	  printf("Nome da Materia: %s\n",aux->info.nome);
	  printf("Codigo: %s\n", aux->info.codigo);
	  printf("Estado: ");
	  if(aux->info.estado == 0)
	    printf("Cursando\n");
	  if(aux->info.estado == 1)
	    printf("Aprovado\n");
	  if(aux->info.estado == 2)
	    printf("Reprovado\n");
	  printf("Nota: %d\n",aux->info.nota);
	  printf("\n");
	}
      aux = aux->proximo;
    }
}

void edicao_imprimir_disciplinas_cursando(EDICAO * disciplinas)
{
  EDICAO * aux = disciplinas;
  while(aux!=NULL)
    {
      if(aux->info.estado == 0)
	{
	  printf("Nome da Materia: %s\n",aux->info.nome);
	  printf("Codigo: %s\n", aux->info.codigo);
	  printf("Estado: ");
	  if(aux->info.estado == 0)
	    printf("Cursando\n");
	  if(aux->info.estado == 1)
	    printf("Aprovado\n");
	  if(aux->info.estado == 2)
	    printf("Reprovado\n");
	  printf("Nota: %d\n",aux->info.nota);
	  printf("\n");
	}
      aux = aux->proximo;
    }
}

EDICAO * edicao_alterar_nota(EDICAO * disciplinas, char * codigo, int nota)
{
  EDICAO * aux = disciplinas;
  while(aux != NULL && strcmp(codigo,aux->info.codigo)!=0)
    aux = aux->proximo;
  if (aux == NULL)
    return disciplinas;
  else
    {
      aux->info.nota = nota;
    }
  return disciplinas;
}

//Função para encerrar uma disciplina.
EDICAO * edicao_encerrar_disciplina(EDICAO * disciplinas, char * codigo)
{
  EDICAO * aux = disciplinas;
  while(aux != NULL && strcmp(codigo,aux->info.codigo)!=0)
    aux = aux->proximo;
  if(aux == NULL)
    return disciplinas;
  else
    {
      aux->info.vezes_cursadas += 1; //ao ser encerrada, a disciplina conta como cursada mais uma vez.
      if(aux->info.nota >= 60)
	aux->info.estado = 1; //aqui coloca como estado aprovado.
      else
	aux->info.estado = 2; //aqui coloca como estado reprovado.
    }
  return disciplinas;
}

//Função que verifica se o aluno já cursou a disciplina antes ou não
int verificar_disciplina(EDICAO * disciplinas, char * codigo)
{
  EDICAO * aux = disciplinas;
  int estado = 3; //O estado é inicializado em 3.
  while(aux != NULL)
    {
      if(strcmp(codigo,aux->info.codigo)==0)
	{
	  if(estado>=aux->info.estado) //Essa condição acontece desse modo e a inicialização é feita em 3, pois
	    estado = aux->info.estado; //dessa forma somente o menor valor será aguardado, assim, se um aluno tiver reprovado em uma matéria e a estiver cursando denovo
	}                              //ou já tiver sido aprovado, essa condição garante que a mesma matéria não poderá ser incluida novamente na lista de materias a 
    aux=aux->proximo;                  //ser cursadas.
    }
  if(estado == 3)
    return -1; //aluno nunca fez a materia
  else
    {
      if(estado == 0)
	return 0; //aluno cursando
      if(estado == 1)
	return 1; //aluno aprovado
      if(estado == 2)
	return 2; //aluno reprovado
    }
  return -1;
}

//Função que retorna para o programa quantas vezes uma certa disciplina já foi cursada por um determinado aluno.
int verificar_quantidade_cursada(EDICAO * disciplinas, char * codigo)
{
  EDICAO * aux = disciplinas;
  while(aux!=NULL && strcmp(codigo,aux->info.codigo)!=0)
    aux=aux->proximo;
  if(aux == NULL)
    return 0;
  else
    return (aux->info.vezes_cursadas);
}

//Função que retorna para o programa quantas disciplinas um determinado aluno está cursando no momento.
int quantidade_disciplinas_sendo_cursadas(EDICAO * disciplinas)
{
  int contador = 0;
  EDICAO * aux = disciplinas;
  while(aux!=NULL)
    {
      if(aux->info.estado == 0)
	contador++;
      aux = aux->proximo;
    }
  return contador;
}

/*
Trabalho de Análise e Estrutura de Dados I 
Aluno: Guilherme Pacheco de Oliveira - 11411BCC051 
Arquivo Main - Arquivo central que é o ponto de inicio e reune tudo necessário para a execução do programa.


Informações do Cabeçalho:
Arquivo "header.h" - Arquivo onde contem todos os prototipos de funções e typedef's utilizados para os tipos abstratos de dados do código.
Arquivo "header_linuxosx.h" ou "header_windows.h" - Arquivo para facilitar a portabilidade do código e permitir que o programa faça pausas e limpe a tela em certos momentos de sua execução

Constante: [MAT] - definida em 10 e é o tamanho máximo que assumem os códigos de matricula dos alunos e códigos das disciplinas.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"
#include "header_windows.h"
#define MAT 10


/*
Informação de Funções da Main:
cadastrar_aluno -> Recebe como entrada o ponteiro com a lista de alunos e insere um aluno na lista, retorna o endereço da lista de alunos.
remover_aluno -> Recebe como entrada o ponteiro com a lista de alunos e remove um aluno da lista, retorna o endereço da lista de alunos.
cadastrar_disciplina -> Recebe como entrada o ponteiro com a lista das disciplinas e insere uma nova disciplina na lista, retorna o endereço da lista de disciplinas.
remover_disciplina -> Recebe como entrada o ponteiro com a lista das disciplinas e remover uma disciplina da lista, retorna o endereço da lista de disciplinas.
 */

ALUNO * cadastrar_aluno(ALUNO * alunos);
ALUNO * remover_aluno(ALUNO * alunos);
DISCIPLINA * cadastrar_disciplina(DISCIPLINA * disciplinas);
DISCIPLINA * remover_disciplina(DISCIPLINA * disciplinas);

/*
Função main do programa - ao ser inicializada ela cria duas listas, uma com todos os alunos cadastrados e outra com todas as disciplinas cadastradas, ambas as listas são feitas com o conteúdo nos arquivos destinados a elas, "alunos.txt" e "disciplinas.txt".

O Programa te fornece as opções das operações que o usuário deseja fazer e após uma ser escolhida, ela é realizada.
 */

int main()
{
  int opcao;
  ALUNO * alunos;
  DISCIPLINA * disciplinas;
  alunos = aluno_arquivo_para_lista();
  disciplinas = disciplina_arquivo_para_lista();
  do {
    LIMPAR_TELA
    printf("Operações com alunos:\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Editar Aluno\n");
    printf("3 - Remover Aluno\n");
    printf("4 - Imprimir Todos os Alunos\n");
    printf("5 - Gravar em Arquivo\n\n");

    printf("Operações com disciplinas:\n");
    printf("6 - Cadastrar Disciplina\n");
    printf("7 - Remover Disciplina\n");
    printf("8 - Imprimir todas as disciplinas\n");
    printf("9 - Gravar em Arquivo\n");
    printf("10 - Sair do Programa\n");

    
    printf("Opcao: ");
    scanf("%d", &opcao);
    switch(opcao)
      {
      case 1:
	LIMPAR_TELA
	alunos = cadastrar_aluno(alunos);
	PAUSA
	break;
      case 2:
	EDICAO_DE_ALUNO(); //Chamada de uma função que se encontra no arquivo editar_aluno.c
	break;
      case 3:
	LIMPAR_TELA
	alunos = remover_aluno(alunos);
	PAUSA
	break;
      case 4:
	LIMPAR_TELA
	aluno_imprimir_alunos(alunos); //Chamada de uma função que se encontra no arquivo aluno_funcoes.c
	PAUSA
	break;
      case 5:
	aluno_gravar_em_arquivo(alunos); //Chamada de uma função que se encontra no arquivo aluno_funcoes.c
	break;
      case 6:
	LIMPAR_TELA
	disciplinas = cadastrar_disciplina(disciplinas);
	PAUSA
	break;
      case 7:
	LIMPAR_TELA
	disciplinas = remover_disciplina(disciplinas);
	PAUSA
	break;
      case 8:
	LIMPAR_TELA
	  disciplina_imprimir_disciplinas(disciplinas); //Chamada de uma função que se encontra no arquivo disciplinas_funcoes.c
	PAUSA
	  break;
      case 9:
	disciplina_gravar_em_arquivo(disciplinas); //Chamada de uma função que se encontra no arquivo disciplinas_funcoes.c
	break;
      }
  }while(opcao!=10);
  aluno_gravar_em_arquivo(alunos); //Ao fechar o programa, as listas de alunos e disciplinas são salvas em seus respectivos arquivos.
  disciplina_gravar_em_arquivo(disciplinas);
  return 0;
}


//Implementação das Funções prototipadas no inicio do código.

ALUNO * cadastrar_aluno(ALUNO * alunos)
{
  aluno_nodo * novo_aluno;
  char * nome, * matricula;
  nome = (char*)malloc(sizeof(char)*100);
  matricula = (char*)malloc(sizeof(char)*100);

  printf("Digite o nome do Aluno: ");
  scanf(" %[^\n]s",nome);
  printf("Digite a matricula do Aluno: ");
  scanf("%s",matricula);

  novo_aluno = aluno_criar_aluno(nome,matricula);
  free(nome);
  free(matricula);
  alunos = aluno_inserir_aluno(alunos,novo_aluno);
  return alunos;
}


ALUNO * remover_aluno(ALUNO * alunos)
{
  char * chave;
  chave = (char*)malloc(sizeof(char)*100);
  printf("Digite o numero de matricula do aluno que deseja remover: ");
  scanf(" %[^\n]s",chave);
  alunos = aluno_remover_aluno(alunos,chave);
  return alunos;
}

DISCIPLINA * cadastrar_disciplina(DISCIPLINA * disciplinas)
{
  disciplina_nodo * nova_disciplina;
  char * nome, * codigo;
  int creditos;
  nome = (char*)malloc(sizeof(char)*100);
  codigo = (char*)malloc(sizeof(char)*100);

  printf("Digite o nome da disciplina: ");
  scanf(" %[^\n]s",nome);
  printf("Digite o codigo da disciplina: ");
  scanf("%s",codigo);
  printf("Digite os creditos da disciplina: ");
  scanf("%d", &creditos);

  nova_disciplina = disciplina_criar_disciplina(nome,codigo,creditos);
  free(nome);
  free(codigo);
  disciplinas = disciplina_inserir_disciplina(disciplinas,nova_disciplina);
  return disciplinas;
}


DISCIPLINA * remover_disciplina(DISCIPLINA * disciplinas)
{
  char * chave;
  chave = (char*)malloc(sizeof(char)*100);
  printf("Digite o codigo da materia que quer remover: ");
  scanf(" %s",chave);
  disciplinas = disciplina_remover_disciplina(disciplinas,chave);
  return disciplinas;
}

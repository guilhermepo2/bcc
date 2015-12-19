#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "header.h"
#include "header_windows.h"
#define MAT 10

//Protótipo das funções utilizadas.

EDICAO * inserir_disciplina(EDICAO * lista_disciplinas);
EDICAO * inserir_nota(EDICAO * lista_disciplinas);
EDICAO * encerrar_disciplina(EDICAO * lista_disciplinas);

//Função que vai ser chamada na main para iniciar o modo de edição de alunos.

void EDICAO_DE_ALUNO(void)
{
  char * matricula = (char*)malloc(sizeof(char)*MAT);
  printf("Digite a matricula do usuario que deseja editar: ");
  scanf("%s",matricula);
  
  //Abrindo para leitura o arquivo referente ao aluno que vai ser editado.
  
  char buf[100];
  snprintf(buf,sizeof(buf), "alunos/%s.txt", matricula);
  FILE * arq = fopen(buf,"r");
  if(arq==NULL) //Caso o arquivo não exista.
    {
      LIMPAR_TELA
      printf("Matricula nao encontrada.\n\n");
      PAUSA
    }
  else
    {
      fgets(buf,sizeof(buf),arq);
      char * nome = strtok(buf,","); //pegando o nome do aluno
      matricula = strtok(NULL,"\n");
      fclose(arq);
  
      
  EDICAO * ficha_aluno;
  int op;
  ficha_aluno = edicao_arquivo_para_lista(matricula);  //Pega a base de dados das matérias que o aluno cursa ou já cursou e a coloca no programa.
  do
    {
      LIMPAR_TELA
	printf("Modo de edicao de Aluno\nAluno: %s\n",nome);
      printf("1 - Inserir Disciplina Sendo Cursada\n");
      printf("2 - Ver Disciplinas em que o Aluno foi Aprovado.\n");
      printf("3 - Ver disciplinas em que o Aluno foi Reprovado.\n");
      printf("4 - Ver disciplinas que o aluno esta cursando.\n");
      printf("5 - Inserir nota para disciplina em andamento\n");
      printf("6 - Encerrar uma disciplina\n");
      printf("7 - Encerrar edicao\n");
      printf("Opcao: ");
      scanf("%d", &op);
      switch(op)
	{
	case 1:
	  ficha_aluno = inserir_disciplina(ficha_aluno);
	  PAUSA
	  break;
	case 2:
	  LIMPAR_TELA
	  edicao_imprimir_disciplinas_aprovadas(ficha_aluno);
	  PAUSA
	  break;
	case 3:
	  LIMPAR_TELA
	  edicao_imprimir_disciplinas_reprovadas(ficha_aluno);
	  PAUSA
	  break;
	case 4:
	  LIMPAR_TELA
	  edicao_imprimir_disciplinas_cursando(ficha_aluno);
	  PAUSA
	  break;
	case 5:
	  ficha_aluno = inserir_nota(ficha_aluno);
	  PAUSA
	  break;
	case 6:
	  ficha_aluno = encerrar_disciplina(ficha_aluno);
	  PAUSA
	  break;
	}
    }while(op!=7);
  edicao_gravar_em_arquivo(ficha_aluno,nome,matricula);
    }

}

//Função que vai fazer a inserção de uma disciplina a ser cursada para o aluno.

EDICAO * inserir_disciplina(EDICAO * lista_disciplinas)
{
  DISCIPLINA * disciplinas_disponiveis;
  disciplinas_disponiveis = disciplina_arquivo_para_lista();
  //pegando em uma lista as disciplinas existentes.
  
  //verificando quantas disciplinas o aluno cursa
  int quantidade_disciplinas = quantidade_disciplinas_sendo_cursadas(lista_disciplinas);
  if (quantidade_disciplinas == 6) //caso ele curse 6 matérias.
    {
      printf("\nO Aluno ja cursa 6 materias.\n\n");
      return lista_disciplinas;
    }
  
  char codigo[MAT], disciplina[100];
  int verificador;
  printf("Digite o Codigo da disciplina a ser inserida: ");
  scanf("%s",codigo);
  verificador = verificar_existencia_disciplina(disciplinas_disponiveis,codigo,disciplina);
  //verificando se a matéria que foi digitada realmente existe, a função retorna também o nome da matéria a ser inserida.

  if(verificador) //caso a matéria realmente exista
    {
      //verificar se a materia ja esta sendo cursada ou se ja foi cursada
      verificador = verificar_disciplina(lista_disciplinas, codigo);
      if(verificador==-1) //aluno nunca cursou a materia
	{
	  edicao_nodo * novo;
	  novo = edicao_criar_disciplina_cursando(disciplina,codigo);
	  lista_disciplinas = edicao_inserir_disciplina_lista(lista_disciplinas,novo);
	}
      if(verificador==0) // Aluno esta cursando a materia
	{
	  printf("\nO Aluno ja esta cursando essa materia.\n\n");
	}
      if(verificador==1) //Aluno ja foi aprovado
	{
	  printf("\nO Aluno ja foi aprovado nessa materia.\n\n");
	}
      if(verificador==2) //Aluno ja foi reprovado nessa materia
	{
	  int vezes_cursada;
	  //fazendo a verificação de quantas vezes a disciplina já foi cursada.
	  vezes_cursada = verificar_quantidade_cursada(lista_disciplinas,codigo);
	  if(vezes_cursada == 4)
	    {
		printf("\nEssa materia ja foi cursada quatro vezes por esse aluno.\nEla nao pode mais ser cursada.\n\n");
	    }
	  else //caso o aluno tenha sido reprovado mas menos de 4 vezes
	    {
	      edicao_nodo * novo;
	      novo = edicao_criar_disciplina_reprovado(disciplina,codigo,vezes_cursada);
	      lista_disciplinas = edicao_inserir_disciplina_lista(lista_disciplinas,novo);
	    }
	}
    }
  else
    printf("\nEssa disciplina nao existe.\n\n");
  return lista_disciplinas;
  
}

EDICAO * inserir_nota(EDICAO * lista_disciplinas)
{
  char codigo[MAT];
  int nota;
  printf("Digite o codigo da materia que deseja atribuir a nota: ");
  scanf("%s",codigo);
  printf("Digite a nota que deseja atribuir: ");
  scanf("%d",&nota);
  lista_disciplinas = edicao_alterar_nota(lista_disciplinas,codigo,nota);
  return lista_disciplinas;
}

EDICAO * encerrar_disciplina(EDICAO * lista_disciplinas)
{
  char codigo[MAT];
  printf("Digite o codigo da materia que deseja encerrar: ");
  scanf("%s", codigo);
  lista_disciplinas = edicao_encerrar_disciplina(lista_disciplinas,codigo);
  return lista_disciplinas;
}

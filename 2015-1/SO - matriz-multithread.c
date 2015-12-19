/*
Guilherme Pacheco de Oliveira
Trabalho de Sistemas Operacionais - Universidade Federal de Uberlândia
Semestre: 2015-1
Programa em C que faz a multiplicação de uma matriz de tamanho TAM usando N threads
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<pthread.h>

#define N 2 //Numero de Threads
#define TAM 5000 //Tamanho da Matriz

int matrizA[TAM][TAM];
int matrizB[TAM][TAM];
int matrizC[TAM][TAM];

int random_number()
{
  int n;
  n = rand() % 10;
  return n;
}

void imprimir_matriz(int matriz[TAM][TAM])
{
  int i, j;
  for(i = 0; i < TAM; i++)
    {
      printf("%d - ", i+1);
      for(j = 0; j <  TAM; j++)
	{
	  printf("%d ", matriz[i][j]);
	}
      printf("\n");
    }
}

void multiplicar_matriz(int * pedaco)
{
  int contador = *pedaco;
  int m_inicio = (contador * TAM)/N;
  int m_fim = ((contador+1) * TAM)/N;
  printf("inicio: %d - fim: %d\n", m_inicio, m_fim);
  int i, j, k, acumulador;
  time_t inicio, fim;
  double tempo_gasto;

  printf("Multiplicando...\n");
  time(&inicio);
  for(i = m_inicio; i < m_fim; i++)
    {
      for(j = 0; j < TAM; j++)
	{
	  acumulador = 0;
	  for(k = 0; k < TAM; k++)
	    {  
	      acumulador += (matrizA[i][k] * matrizB[k][j]);
	    }
	  matrizC[i][j] = acumulador;
	}
    }
  time(&fim);
  tempo_gasto = difftime(fim,inicio);
  printf("Thread %d - Tempo: %f\n", contador, tempo_gasto);
}

int main(void)
{
  srand(time(NULL));
  pthread_t threads[N];
  int i, j, flags[N];
  
  for(i = 0; i < TAM; i++)
    for(j = 0; j < TAM; j++)
      {
	matrizA[i][j] = random_number();
	matrizB[i][j] = random_number();
      }
  
  //multiplificar matriz multithread
  for(i = 1; i < N; i++)
    {
      flags[i] = i;
      pthread_create(&threads[i], NULL, (void*) &multiplicar_matriz, &flags[i]);
    }

  flags[0] = 0;
  multiplicar_matriz(&flags[0]);

  for(i = 1; i < N; i++)
    {
      pthread_join(threads[i], NULL);
    }
  
  //imprimindo as matrizes
  //printf("Matrizes:\n");
  //printf("A: \n");
  //imprimir_matriz(matrizA);
  //printf("B: \n");
  //imprimir_matriz(matrizB);
  //printf("C: \n");
  //imprimir_matriz(matrizC);
  
  return 0;
}

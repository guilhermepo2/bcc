//Código que, dado um ponto e um eixo cartesiano, fornece o ponto simétrico ao fornecido em relação ao eixo escolhido.

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  int x;
  int y;
}tipoPonto;

int main()
{
  tipoPonto simetria(tipoPonto* ponto, tipoPonto* pSimetria, int* eixo)
  {
    if (*(eixo) == 2)
      {
	pSimetria->y = ponto->y;
	pSimetria->x = -1*ponto->x;
      }
    if (*(eixo) == 1)
      {
	pSimetria->x = ponto->x;
	pSimetria->y = -1*ponto->y;
      }
    return *pSimetria;	   		  
  }
  
  tipoPonto ponto;
  printf("Preencha o ponto (x,y):\n");
  scanf("%d %d", &ponto.x, &ponto.y);
  int eixo;
  printf("Escolha o eixo a ser espelhado: 1 - abscissa, 2 - ordenada\n");
  scanf("%d", &eixo);
  tipoPonto pSimetria;
  simetria(&ponto, &pSimetria, &eixo);
  printf("Ponto original: (%d, %d)\n", ponto.x, ponto.y);
  printf("Ponto Simétrico: (%d, %d)\n", pSimetria.x, pSimetria.y);
  
  return 0;
}

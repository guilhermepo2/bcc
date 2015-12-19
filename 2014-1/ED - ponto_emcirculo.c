// Código que, dado o centro e o raio de um circulo, ele calcula se um ponto também dado está dentro desse circulo.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
  int x;
  int y;
}tipoPonto;

typedef struct {
  int R;
  tipoPonto centro;
}tipoCirculo;

int main()
{

  int esta_contido(tipoPonto* ponto, tipoCirculo* circulo)
  {
    float distancia;
    distancia = sqrt(pow((circulo->centro.x-ponto->x),2)+pow((circulo->centro.y-ponto->y),2));
    if (distancia < circulo->R || distancia==circulo->R) return 1;
    else return 0;
  }


  tipoCirculo circulo;
  tipoPonto ponto;
  printf("Entre com as posições x e y de um ponto:\n");
  scanf("%d %d", &ponto.x, &ponto.y);
  printf("Entre com as posições x e y do centro de um circulo e seu Raio:\n");
  scanf("%d %d %d", &circulo.centro.x, &circulo.centro.y, &circulo.R);
  int vr;
  vr = esta_contido(&ponto, &circulo);
  if (vr == 1) printf("O ponto está no interior do circulo\n");
  if (vr == 0) printf("O ponto não está dentro do circulo\n");
  return 0;
}

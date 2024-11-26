/*
 * Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no plano
 * P1 (x1,y1) e P2 (x2,y2)
 * Calcule a distância entre P1 e P2 com a fórmula da distância entre pontos
 * Fórmula: sqrt(pow(x2-x1,2) + pow(y2-y1,2))
*/

#include <stdio.h>
#include <math.h>

int main ()
{
  double x1, x2, y1, y2;
  printf (" entre com os valores de x1 e x2: ");
  scanf ("%lf %lf", &x1, &x2);
  printf (" entre com os valores de y1 e y2: ");
  scanf ("%lf %lf", &y1, &y2);
  printf (" o valor da distancia entre os pontos P1 e P2 vale: %.2lf\n", sqrt(pow(x2-x1,2) + pow(y2-y1,2)) );
  return (0);
}



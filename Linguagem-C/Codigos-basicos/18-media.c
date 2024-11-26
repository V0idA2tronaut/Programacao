/*
 * Leia 2 valores de ponto flutuante de dupla precisão (double) que correspondem a 2 notas de um aluno
 * Em seguida, calcule a média do aluno, sabendo que a nota 1 tem peso máximo 3.5 e a nota 2 tem peso máximo 7.5
 * A fórmula para calcular a média é: (x1*p1 + x2*p2*...*xn*pn)/p1+p2+...+pn
*/

#include <stdio.h>

#define peso1 3.5
#define peso2 7.5

int main ()
{
  double nota1, nota2;
  printf (" digite as duas notas, respectivamente: ");
  scanf ("%lf %lf", &nota1, &nota2);
  printf (" a media das notas vale: %2lf\n", ( (nota1 * peso1) + (nota2 * peso2) )/ (peso1 + peso2) );
  return (0);
}

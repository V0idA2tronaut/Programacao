/*
 * A fórmula para calcular a área de uma circunferência é: area = pi * raio * raio
 * Consiere para este problema, pi = 3,14159
 * Crie um programa para calcular a área de um círculo dada entrada de um usuário
*/

#include <stdio.h>

#define PI 3.14159

int main ()
{
  double raio;
  printf (" digite o valor do raio: ");
  scanf ("%lf", &raio);
  printf (" o valor da area do círculo eh: %.2lf\n", PI * raio * raio);
  return (0);
}

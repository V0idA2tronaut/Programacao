/*
 * Faça um programa que calcule e mostre o volume de uma esfera fornecido o valor de seu raio
 * Considere o valor de PI como: 3,14159
 * A fórmula para calcular o volume da esfera é: 4/3 * pi * raio³
*/

#include <stdio.h>

#define PI 3.14159

int main ()
{
  double raio;
  printf (" entre com o valor do raio: ");
  scanf ("%lf", &raio);
  printf (" o valor do volume de uma esfera com %2lf de raio vale: %2lf\n", raio, 4 * raio * raio * raio * PI / 3);
  return (0);
}

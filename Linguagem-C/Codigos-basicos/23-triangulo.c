/*
 * leia 3 valores reais e verifique se eles formam ou não um triângulo
 * Em caso positivo, calcule o perímetro do triângulo
 * Em caso negativo, calcule a área do trapézio que tem os dois primeiros valores como base e o terceiro como altura
*/

#include <stdio.h>

int main (void)
{
  float valor1, valor2, valor3;

  scanf ("%f %f %f", &valor1, &valor2, &valor3);
  if (valor1 < valor2 + valor3 && valor2 < valor1 + valor3 && valor3 < valor2 + valor3)
  {
    printf (" eh triangulo de perimetro: %.3f\n", valor1 + valor2 + valor3);
  }
  else
  {
    printf (" nao eh triangulo, logo, area trapezio: %.3f\n", (valor1 + valor2) * valor3/2);
  }
  return (0);
}

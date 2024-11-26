/*
 * Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de Bhaskara
 * Se não for possível calcular, mostrar a mensagem "impossível calcular"
 * A fórmula de Bhaskara segue como: -valor2 +- sqrt(pow(valor2,2) - 4 * valor1 * valor3)/2 * valor1 * valor3
*/

#include <stdio.h>
#include <math.h>

#define delta (valor2*valor2)-(4*valor1*valor3)

int main ()
{
  double valor1, valor2, valor3;
  printf (" entre com os valores para A, B e C, respectivamente: ");
  scanf ("%lf %lf %lf", &valor1, &valor2, &valor3);

  if (valor1 != 0 && delta > -1)
  {
    printf (" o valor da raiz1 vale: %lf\n", (-valor2 + sqrt(delta) )/(2 * valor1) );
    printf (" o valor da raiz2 vale: %lf\n", (-valor2 - sqrt(delta) )/(2 * valor1) );
  }
  else
  {
    printf (" impossivel calcular\n");
  }
  return (0);
}


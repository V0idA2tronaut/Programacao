/*
 * Um número inteiro é dito perfeito se o dobro dele é igual à soma de todos os seus divisores
 * Por exemplo, como os divisores de 6 são: 1, 2, 3 e 6 | 1 + 2 + 3 + 6 = 12
 * A matemática ainda não sabe se a quantidade de números perfeitos é ou não finita
 * 
 * Escreva um programa que liste todos os números perfeitos menores que um inteiro dado pelo usuário
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime (int primo)
{
	for (int check = 5; check < primo/2; check += 2)
	{
		if (primo % check == 0 || primo % (check + 6) == 0) return false;
	}

	return true;
}
	
int main ()
{
	int maximo;
	int i = 2;

	printf ("Entre com um valor maximo para verificar os numeros perfeitos entre 0 e este maximo: ");
	scanf ("%d", &maximo);

	while (pow(2,(i-1)) * (pow(2,i) - 1) <= maximo)
	{
		if (i == 2) printf ("Este eh um numero perfeito = %.1lf \n", pow(2,(i-1)) * (pow(2,i) - 1));
		else if (i == 3) printf ("Este eh um numero perfeito = %.1lf \n", pow(2,(i-1)) * (pow(2,i) - 1));
		else if ( isPrime((pow(2,i) - 1)) == true) printf ("Este eh um numero perfeito = %.1lf\n", pow(2,(i-1)) * (pow(2,i) - 1));
		i++;
	}

	return (0);
}

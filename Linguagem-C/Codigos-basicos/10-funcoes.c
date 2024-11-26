#include <stdio.h>

void passagem_porValor(int, int);
void passagem_porReferencia(int*, int*);

int main ()
{
	int valor1 = 10;
	int valor2 = 5;
	
	printf ("valor1 = %d | valor2 = %d\n", valor1, valor2);
	passagem_porValor(valor1, valor2);

	printf ("valor1 = %d | valor2 = %d\n", valor1, valor2);
	passagem_porReferencia(&valor1, &valor2);

	printf ("valor1 = %d | valor2 = %d\n", valor1, valor2);

	return (0);
}

void passagem_porValor(int Valor1, int Valor2)
{
	Valor1 = Valor1 + Valor2;
}

void passagem_porReferencia(int *Valor1, int *Valor2)
{
	*Valor2 = *Valor2 + *Valor1;
}


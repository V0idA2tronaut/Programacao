#include <stdio.h>

int main ()
{
	int valor1 = 0;

	printf ("\n contando de 0 ate 9 (10 numeros)\n");
	do{
		printf ("%d\n", valor1++);
	}while(valor1 < 10);

	return (0);
}


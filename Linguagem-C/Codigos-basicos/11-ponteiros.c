#include <stdio.h>

int main ()
{
	int valor;
	int *valorPtr;

	valor = 7;

	valorPtr = &valor;
	printf ("o endereço de valor = %p\no valor de *valorPtr = %p\n", &valor, valorPtr);
	printf ("o valor de valor = %d\no valor de *valorPtr = %d\n", valor, *valorPtr);
	printf ("sabnendo que * e & complementam-se mutuamente\n&*valorPtr = %p\n*&valorPtr = %p\n", &*valorPtr, *&valorPtr);
	
	return (0);
}

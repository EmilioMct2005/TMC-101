#include <stdio.h>
#include <math.h>

/* Igualdad de expresiones.
El programa, al recibir como datos T, P y N, comprueba la igualdad de
una expresión determinada.

T, P y N: variables de tipo entero. */

void main(void)
{
    int T, P, N;
    printf("ingrese los valores de T, P y N: ");
    scanf("%d %d %d", &T, &P, &N);
    if (P != 0)
    {
        if (pow(T / P, N) ==  (pow(T, N) / pow(P, N)))
            printf("\mSe comprueba la igualdad");
            else
            printf("\nNO se comprueba la igualdad");

    }
    else
        printf("\nP tiene que ser diferente de cero");


}


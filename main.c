#include <stdio.h>

void main(void)
{
    float PAG, SPA;
    SPA = 0;
    printf("ingrese el primer pago:\t");
    scanf("%f", &PAG);
    while (PAG)
    {
        SPA = SPA + PAG;
        printf ("ingrese el siguiente pago:\t");
        scanf ("%f", &PAG);


    }
    printf("\nEl total de pagos del mes es: %.2f", SPA);
}


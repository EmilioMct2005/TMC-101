#include <stdio.h>
#include <math.h>

void main (void)
{
    int NUM;
    long CUA, SUC = 0;
    printf("\nIngrese un numero entero -0parea terminar-:\t");
    scanf("%d", &NUM);
    while(NUM)
    {
        CUA = pow (NUM, 2);
        printf("%d al cuadrado es %1d", NUM, CUA);
        SUC = SUC + CUA;
        printf("\nInrgese un numero entero -0 para terminar-:\t");
        scanf ("%d", &NUM);

    }
    printf("\nLa suma de los cuadrados es %1d", SUC);
}

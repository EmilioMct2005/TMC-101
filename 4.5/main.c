#include <stdio.h>

int cubo(int);
void main (void)
{
    int I;
    for(I = 1; I <=100; I++)
    printf("\nEl cubo de Ies:%d", cubo(I));
}
    int cubo (int K)
    {
       return (K*K*K);
    }


#include <stdio.h>


/* Billete de ferrocarril.
El programa calcula el costo de un billete de ferrocarril teniendo en
cuenta la distancia entre las dos ciudades y el tiempo de permanencia
del pasajero.

DIS y TIE: variables de tiempo entero.
BIL: variable de tiempo real.*/

void main(void)
{
    int DIS, TIE;
    float BIL;
    printf("ingrese la distancia entre las ciudades y el tiempo de estancia: ");
    scanf("%d %d", &DIS, &TIE);
    if ((DIS*2 > 500)&& (TIE > 10))
        BIL = DIS * 2 * 0.8;
    else
        BIL = DIS * 2 * 0.19;
    printf("n\n costo del billete: %7.2f", BIL);

}

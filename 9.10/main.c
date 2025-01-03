#include <stdio.h>
#include <stdlib.h>

void minymay(FILE *);

void main (void)
{
    char p;
    FILE *ar;
    if ((ar = fopen("arc5.txt", "r")) != NULL)
    {
        minymay(ar);
        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");
}

void minymay(FILE *arc)
{
    int min = 0, may = 0;
    char p;
    while (!feof(arc))
    {
        p = fgetc(arc);

        if (islower(p))
            min++;
        else if (isupper(p))
            may++;
    }
}

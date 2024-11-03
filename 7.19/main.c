#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cuentap(char *);

void main(void) {
    int i;
    char fra[50];
    printf("\nIngrese la línea de texto: ");
    gets(fra);
    strcat(fra, " ");
    i = cuentap(fra);
    printf("\nLa línea de texto tiene %d palabras", i);
}

int cuentap(char *cad) {
    char *cad0;
    int i = 0;
    cad0 = strstr(cad, " ");

    while (cad0 != NULL) {
        i++;
        cad0 = strstr(cad0 + 1, " ");
    }
    return i;
}

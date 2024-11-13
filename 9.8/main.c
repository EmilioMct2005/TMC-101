#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
}alumno;

void escribe(FILE *);

void main (void)
{
    FILE *ar;
    if ((ar = fopen ("ad1.dat", "w")) != NULL)
        escribe (ar);
    else
        printf("\nNo se puede abrir el archivo");
    fclose(ar);
}

void escribe(FILE *ap)
{
    alumno alu;
    int i = 0, r;
    printf("\nDesea ingresar informacion sobre alumnos? (s1 - 1  no - 0): ");
    scanf("%d", &r);
    while(r)
    {
        i++;
        printf("Matricula del alumno %d:", i);
        scanf("%d", &alu.matricula);
        printf("\nNombre del alumno %d: ", i);
        fflush(stdin);
        gets(alu.nombre);
        printf("\nCarrera del alumno %d: ", i);
        scanf("%d", &alu.nombre);
        printf("\nPromedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);

        fwrite(&alu, sizeof(alumno), 1, ap);
        printf("\nDesea ingresar informacion sobre mas alumnos? (si - 1  no - 0):");
        scanf("%d", &r);
    }
}

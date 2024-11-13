#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char materia[20];
    int calificacio;
}matcal;

typedef struct
{
    int matricula;
    char nombre[20];
    matcal cal[5];
}alumno;

void F1(FILE *);
void F2(FILE *);
float F3(FILE *);

void main(void)
{
    float pro;
    FILE *ap;
    if ((ap = fopen("esc.dat", "r")) != NULL)
    {
       F1(ap) ;
       F2(ap);
       pro = F3(ap);
       printf("\n\nPromedio general materia 4: %f", pro);
    }
    else
        printf("El archivo no se puede abrir");
    fclose(ap);
}

void F1(FILE *ap)
{
  alumno alu;
  int j;
  float sum, pro;
  printf("\nMatricula y promedios");

  fread(&alu, sizeof(alumno), 1, ap);
  while(!feof(ap))
  {
      printf("\nMatricula: %d", alu.matricula);
      sum = 0.0;
      for(j = 0; j < 5; j++)
        sum += alu.cal[j].calificacio;
      pro = sum / 5;
      printf("\tPromedio: %f", pro);
      fread(&alu, sizeof(alumno), 1, ap);
  }
}

void F2(FILE *ap)
{
    alumno alu;
    int j;
    rewind(ap);
    printf("\n\nAlumnos con calificacion > 9 en materia 3");
    fread(&alu, sizeof(alumno), 1, ap);
    while(!feof(ap))
    {
        if(alu.cal[2].calificacio > 9)
            printf("\nMatricula del alumno: %d", alu.matricula);
        fread(&alu, sizeof(alumno), 1, ap);
    }
}

float F3(FILE *ap)
{
    alumno alu;
    int i = 0;
    float sum = 0, pro;
    rewind(ap);
    fread(&alu, sizeof(alumno), 1, ap);
    while(!feof(ap))
    {
        i++;
        sum += alu.cal[3].calificacio;
        fread(&alu, sizeof(alumno), 1, ap);
    }
    pro = (float)sum / i;
    return (pro);
}

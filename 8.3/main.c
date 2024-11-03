#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado {
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion;
};

void Lectura(struct empleado *a) {
    printf("\nIngrese el nombre del empleado: ");
    gets(a->nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(a->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    fflush(stdin);
    printf("---Ingrese la direcci�n del empleado---");
    printf("\n\tCalle: ");
    gets(a->direccion.calle);
    printf("\tN�mero: ");
    scanf("%d", &a->direccion.numero);
    printf("\tC�digo Postal: ");
    scanf("%d", &a->direccion.cp);
    fflush(stdin);
    printf("\tLocalidad: ");
    gets(a->direccion.localidad);
}

int main(void) {
    struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jer�nimo", 120, 3490, "Toluca"}};
    struct empleado *e1, *e2, e3, e4;

    e1 = (struct empleado *) malloc(sizeof(struct empleado));
    printf("\nIngrese el nombre del empleado 1: ");
    scanf("%s", e1->nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(e1->departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    fflush(stdin);
    printf("---Ingrese la direcci�n del empleado---");
    printf("\n\tCalle: ");
    gets(e1->direccion.calle);
    printf("\tN�mero: ");
    scanf("%d", &e1->direccion.numero);
    printf("\tC�digo Postal: ");
    scanf("%d", &e1->direccion.cp);
    fflush(stdin);
    printf("\tLocalidad: ");
    gets(e1->direccion.localidad);

    printf("\nIngrese el nombre del empleado 3: ");
    scanf("%s", e3.nombre);
    fflush(stdin);
    printf("Ingrese el departamento de la empresa: ");
    gets(e3.departamento);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    fflush(stdin);
    printf("---Ingrese la direcci�n del empleado---");
    printf("\n\tCalle: ");
    gets(e3.direccion.calle);
    printf("\tN�mero: ");
    scanf("%d", &e3.direccion.numero);
    printf("\tC�digo Postal: ");
    scanf("%d", &e3.direccion.cp);
    fflush(stdin);
    printf("\tLocalidad: ");
    gets(e3.direccion.localidad);

    e2 = (struct empleado *) malloc(sizeof(struct empleado));
    Lectura(e2);
    Lectura(&e4);

    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e1->nombre, e1->departamento, e1->sueldo,
           e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

    printf("\nDatos del empleado 4\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e4.nombre, e4.departamento, e4.sueldo,
           e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

    free(e1);
    free(e2);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 100
#define MAX_CARRERA 50

typedef struct {
    char nombre[MAX_NOMBRE];
    float promedio;
    char carrera[MAX_CARRERA];
} Alumno;

// Funcion para limpiar el bufer de entrada
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcion para agregar un alumno y escribirlo en un archivo
void agregar_alumno_a_archivo(const char *nombre_archivo) {
    Alumno alumno;

    printf("Ingrese el nombre del alumno: ");
    limpiar_buffer();
    fgets(alumno.nombre, MAX_NOMBRE, stdin);
    alumno.nombre[strcspn(alumno.nombre, "\n")] = '\0';

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &alumno.promedio);

    printf("Ingrese la carrera del alumno: ");
    limpiar_buffer();
    fgets(alumno.carrera, MAX_CARRERA, stdin);
    alumno.carrera[strcspn(alumno.carrera, "\n")] = '\0';

    FILE *archivo = fopen(nombre_archivo, "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escribir.\n");
        return;
    }

    fprintf(archivo, "%s,%.2f,%s\n", alumno.nombre, alumno.promedio, alumno.carrera);
    fclose(archivo);

    printf("Alumno agregado al archivo '%s' con exito.\n", nombre_archivo);
}

// Funcion para mostrar los contenidos del archivo
void mostrar_archivo(const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    char linea[200];
    printf("\nContenido del archivo '%s':\n", nombre_archivo);
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }
    fclose(archivo);
}

// Funcion para mostrar el menu principal
void mostrar_menu_principal() {
    printf("\nMENU PRINCIPAL:\n");
    printf("1. Crear un nuevo archivo\n");
    printf("2. Abrir archivo existente\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");
}

// Funcion para mostrar el menu de archivo
void mostrar_menu_archivo() {
    printf("\nMENU DE ARCHIVO:\n");
    printf("1. Ver los datos guardados\n");
    printf("2. Agregar un alumno\n");
    printf("3. Volver al menu principal\n");
    printf("Seleccione una opcion: ");
}

int main() {
    int opcion, opcion_archivo;
    char nombre_archivo[100];
    FILE *archivo;

    while (1) {
        mostrar_menu_principal();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // funcion para crear un nuevo archivo
                printf("Ingrese el nombre del archivo a crear (incluya la extension .txt): ");
                limpiar_buffer();
                fgets(nombre_archivo, sizeof(nombre_archivo), stdin);
                nombre_archivo[strcspn(nombre_archivo, "\n")] = '\0';

                archivo = fopen(nombre_archivo, "w");
                if (archivo == NULL) {
                    printf("Error al crear el archivo.\n");
                } else {
                    printf("Archivo '%s' creado con exito.\n", nombre_archivo);
                    fclose(archivo);
                }
                break;

            case 2:
                // Abrir un archivo existente
                printf("Ingrese el nombre del archivo a abrir (incluya la extension .txt): ");
                limpiar_buffer();
                fgets(nombre_archivo, sizeof(nombre_archivo), stdin);
                nombre_archivo[strcspn(nombre_archivo, "\n")] = '\0';

                archivo = fopen(nombre_archivo, "r");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo.\n");
                    break;
                }

                fclose(archivo);

                // funcion para mostrar menu de archivo
                while (1) {
                    mostrar_menu_archivo();
                    scanf("%d", &opcion_archivo);

                    switch (opcion_archivo) {
                        case 1:
                            // Ver los datos guardados
                            mostrar_archivo(nombre_archivo);
                            break;

                        case 2:
                            // Agregar un alumno
                            agregar_alumno_a_archivo(nombre_archivo);
                            break;

                        case 3:
                            // Volver al menu principal
                            printf("Volviendo al menu principal...\n");
                            break;

                        default:
                            printf("Opcion no valida. Intente de nuevo.\n");
                    }

                    if (opcion_archivo == 3) {
                        break;
                    }
                }
                break;

            case 3:
                // Salir del programa
                printf("Saliendo del programa.\n");
                return 0;

            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    }

    return 0;
}


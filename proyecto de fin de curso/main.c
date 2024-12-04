
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_NAME_LEN 100
#define MAX_CARRERA_LEN 50

// Definición de la estructura Alumno
typedef struct {
    char nombre[MAX_NAME_LEN];
    float promedio;
    char carrera[MAX_CARRERA_LEN];
} Alumno;

// Función para mostrar el menú
void mostrarMenu() {
    printf("\n--- Sistema de Gestión de Alumnos ---\n");
    printf("1. Nuevo Archivo\n");
    printf("2. Abrir Archivo por Nombre\n");
    printf("3. Guardar Archivo con Nombre\n");
    printf("4. Buscar y Seleccionar Renglón\n");
    printf("5. Agregar Nuevo Alumno\n");
    printf("6. Salir\n");
    printf("Seleccione una opción: ");
}

// Función para crear un nuevo archivo
void nuevoArchivo(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error al crear el archivo");
        return;
    }
    fclose(file);
    printf("Archivo creado exitosamente: %s\n", filename);
}

// Función para abrir un archivo
FILE *abrirArchivo(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (!file) {
        printf("El archivo \"%s\" no existe.\n", filename);
    }
    return file;
}

// Función para guardar registros en un archivo
void guardarArchivo(const char *filename, Alumno *alumnos, int cantidad) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error al guardar el archivo");
        return;
    }
    fwrite(alumnos, sizeof(Alumno), cantidad, file);
    fclose(file);
    printf("Registros guardados exitosamente en %s.\n", filename);
}

// Función para agregar un nuevo alumno
void agregarAlumno(FILE *file) {
    Alumno nuevo;
    printf("Ingrese el nombre del alumno: ");
    scanf(" %[^\n]", nuevo.nombre);
    printf("Ingrese el promedio: ");
    scanf("%f", &nuevo.promedio);
    printf("Ingrese la carrera: ");
    scanf(" %[^\n]", nuevo.carrera);

    fseek(file, 0, SEEK_END);
    fwrite(&nuevo, sizeof(Alumno), 1, file);
    printf("Alumno agregado exitosamente.\n");
}

// Función para buscar un alumno por nombre
void buscarAlumno(FILE *file) {
    char nombreBusqueda[MAX_NAME_LEN];
    Alumno alumno;
    int encontrado = 0;

    printf("Ingrese el nombre a buscar: ");
    scanf(" %[^\n]", nombreBusqueda);

    rewind(file);
    int index = 0;
    while (fread(&alumno, sizeof(Alumno), 1, file)) {
        if (strcmp(alumno.nombre, nombreBusqueda) == 0) {
            printf("Alumno encontrado en el renglón %d:\n", index + 1);
            printf("Nombre: %s, Promedio: %.2f, Carrera: %s\n",
                   alumno.nombre, alumno.promedio, alumno.carrera);
            encontrado = 1;
            break;
        }
        index++;
    }
    if (!encontrado) {
        printf("No se encontró un alumno con el nombre especificado.\n");
    }
}

int main() {
    setlocale(LC_ALL, ""); // Configurar soporte para caracteres especiales
    char filename[MAX_NAME_LEN] = "";
    FILE *archivo = NULL;
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: // Nuevo Archivo
                printf("Ingrese el nombre del nuevo archivo: ");
                scanf(" %[^\n]", filename);
                nuevoArchivo(filename);
                break;

            case 2: // Abrir Archivo
                printf("Ingrese el nombre del archivo a abrir: ");
                scanf(" %[^\n]", filename);
                archivo = abrirArchivo(filename, "rb+");
                if (archivo) {
                    printf("Archivo abierto exitosamente: %s\n", filename);
                }
                break;

            case 3: // Guardar Archivo
                if (archivo) {
                    fclose(archivo);
                    archivo = abrirArchivo(filename, "rb+");
                    printf("Archivo guardado exitosamente: %s\n", filename);
                } else {
                    printf("No hay archivo abierto para guardar.\n");
                }
                break;

            case 4: // Buscar y Seleccionar
                if (archivo) {
                    buscarAlumno(archivo);
                } else {
                    printf("No hay archivo abierto.\n");
                }
                break;

            case 5: // Agregar Nuevo Alumno
                if (archivo) {
                    agregarAlumno(archivo);
                } else {
                    printf("No hay archivo abierto.\n");
                }
                break;

            case 6: // Salir
                if (archivo) fclose(archivo);
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}

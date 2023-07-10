#include <stdio.h>
#include <string.h>



void llamararchivo() {
    FILE *archivo;
    archivo = fopen("alumnos.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }
    fclose(archivo);
}

typedef struct {
    int orden;
    char nombre[50];
    char carrera[50];
    float nota1;
    float nota2;
    float nota3;
    float promedio;
} Estudiantes;

void cargarEstudiantes(Estudiantes* estudiantes, int numEstudiantes, const char* alumnos) {
    FILE* archivo;
    archivo = fopen(alumnos, "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para lectura.\n");
        
    }

    for (int i = 0; i < numEstudiantes; i++) {
        fscanf(archivo, "%d;%[^;];%[^;];%f;%f;%f\n", &estudiantes[i].orden, estudiantes[i].nombre,
               estudiantes[i].carrera, &estudiantes[i].nota1, &estudiantes[i].nota2, &estudiantes[i].nota3);
    }

    fclose(archivo);
}
void guardarEstudiantes(Estudiantes* estudiantes, int numEstudiantes, const char* nombreArchivo) {
    FILE* archivo;
    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        
    }

    fprintf(archivo, "Orden;Nombre;Carrera;Nota1;Nota2;Nota3;Promedio\n");

    for (int i = 0; i < numEstudiantes; i++) {
        fprintf(archivo, "%d;%s;%s;%.2f;%.2f;%.2f;%.2f\n", estudiantes[i].orden, estudiantes[i].nombre,
                estudiantes[i].carrera, estudiantes[i].nota1, estudiantes[i].nota2, estudiantes[i].nota3, estudiantes[i].promedio);
    }

    fclose(archivo);
}
void ordenarEstudiantes(Estudiantes* estudiantes, int numEstudiantes) {
    for (int i = 0; i < numEstudiantes - 1; i++) {
        for (int j = 0; j < numEstudiantes - i - 1; j++) {
            if (estudiantes[j].orden < estudiantes[j + 1].orden) {
                Estudiantes or = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = or;
            }
        }
    }
}


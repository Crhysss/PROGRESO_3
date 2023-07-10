#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nombre[50];
    char carrera[50];
    float nota1;
    float nota2;
    float nota3;
    float promedio;
} datos;

void cargarEstudiantes(datos* estudiantes, int numDatos,  char* alumnos) {
    FILE* archivo;
    archivo = fopen(alumnos, "r");

    if (archivo == NULL) {
        printf("No se abrio en formato lectura.\n");
        exit(1);
    }

    for (int i = 0; i < numDatos; i++) {
        fscanf(archivo, "%d;%[^;];%[^;];%f;%f;%f\n", &estudiantes[i].codigo, estudiantes[i].nombre,
               estudiantes[i].carrera, &estudiantes[i].nota1, &estudiantes[i].nota2, &estudiantes[i].nota3);
    }

    fclose(archivo);
}

void calcularPromedio(datos* estudiantes, int numDatos) {
    for (int i = 0; i < numDatos; i++) {
        estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3) / 3.0;
    }
}

void ordenarEstudiantes(datos* estudiantes, int numDatos) {
    for (int i = 0; i < numDatos - 1; i++) {
        for (int j = 0; j < numDatos - i - 1; j++) {
            if (estudiantes[j].codigo < estudiantes[j + 1].codigo) {
                datos struc = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = struc;
            }
        }
    }
}

void guardarEstudiantes(datos* estudiantes, int numDatos, char* nombreArchivo) {
    FILE* archivo;
    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("No se abrio en formato escritura.\n");
        exit(1);
    }

    fprintf(archivo, "Codigo;Nombre;Carrera;Nota1;Nota2;Nota3;Promedio\n");

    for (int i = 0; i < numDatos; i++) {
        fprintf(archivo, "%d;%s;%s;%.2f;%.2f;%.2f;%.2f\n", estudiantes[i].codigo, estudiantes[i].nombre,
                estudiantes[i].carrera, estudiantes[i].nota1, estudiantes[i].nota2, estudiantes[i].nota3, estudiantes[i].promedio);
    }

    fclose(archivo);
}

int main() {
    char* archivoEntrada = "alumnos.txt";
    char* archivoSalida = "estudiantes_ordenados.txt";
    int numDatos = 5;

    datos estudiantes[numDatos];

    cargarEstudiantes(estudiantes, numDatos, archivoEntrada);
    calcularPromedio(estudiantes, numDatos);
    ordenarEstudiantes(estudiantes, numDatos);
    guardarEstudiantes(estudiantes, numDatos, archivoSalida);

    printf("El archivo se creo.\n");

    return 0;
}

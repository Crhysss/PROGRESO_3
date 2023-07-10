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
typedef struct notas{
    int not1[5]={"6.00","5.00","10.00","9.00","8.50"};
    int not2[5]={"7.00","6.00","9.00","9.00","8.00"};
    float not3[5]={"8.00", "7.00", "10.00","9.00","9.00"};
}Notas;

typedef struct datos
{
    int orden;
    char nombre[30];
    char carrera[30];
    notas Notas;
}Datos;
int numDatos=5;
void formato(){
    FILE *archivo;
    archivo = fopen("alumnos.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }
    
    for (int i = 0; i < numDatos; i++) {
        fprintf(archivo, "%-10d  ;  %-10s  ;  %-10s  ;  %-14f  ;  %-6f  ;  %-10f\n", Datos.orden, Datos.nombre, Datos.carrera,
        Datos.Nota.not1[i], Datos.Nota.not2[i], Datos.Nota.not3[i]);
    }

    fclose(archivo);
}
void cargarCitas() {
    FILE *archivo;
    archivo = fopen("estudiantes.txt", "r");

    if (archivo == NULL) {
        printf("No se encontro el archivo de citas.\n");
        return;  // Retorna sin realizar ninguna acción adicional
    }

    while (!feof(archivo)) {
    fscanf(archivo, "%[^;];  %[^;];  %d;  %[^;];  %[^;];  %d\n", Datos[numDatos].orden,
           Datos[numDatos].nombre, Datos[numDatos].cedula, citas[numCitas].fecha,
           citas[numCitas].especialidad, &citas[numCitas].hora);
    numCitas++;
}


    fclose(archivo);
}
int main(){

}
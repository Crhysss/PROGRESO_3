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

typedef struct datos
{
    int orden;
    char nombre[30];
    char carrera[30];
    float not1[5]={6.00;5.00;10.00;9.00;8.50};
    float not2[5]={7.00;6.00;9.00;9.00;8.00};
    float not3[5]={8.00; 7.00; 10.00;9.00;9.00};
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
        Datos.not1[i], Datos.not2[i], Datos.not3[i]);
    }

    fclose(archivo);
}
void guardarEstudiantes(Estudiante* estudiantes, int numEstudiantes, const char* nombreArchivo) {
    FILE* archivo;
    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        exit(1);
    }

    fprintf(archivo, "Orden;Nombre;Carrera;Nota1;Nota2;Nota3;Promedio\n");

    for (int i = 0; i < numEstudiantes; i++) {
        fprintf(archivo, "%d;%s;%s;%.2f;%.2f;%.2f;%.2f\n", estudiantes[i].orden, estudiantes[i].nombre,
                estudiantes[i].carrera, estudiantes[i].nota1, estudiantes[i].nota2, estudiantes[i].nota3, estudiantes[i].promedio);
    }

    fclose(archivo);
}
int main(){
    int i;
    float not1[5]={6.00,5.00,10.00,9.00,8.50};
    float not2[5]={7.00,6.00,9.00,9.00,8.00};
    float not3[5]={8.00, 7.00, 10.00,9.00,9.00};
    float sumas[5]={0};
    for(i=0; i<5;i++){
        sumas[0]=not1[i]+not2[i]+not3[i];
        sumas[1]=not1[i]+not2[i]+not3[i];
        sumas[2]=not1[i]+not2[i]+not3[i];
        sumas[3]=not1[i]+not2[i]+not3[i];
        sumas[4]=not1[i]+not2[i]+not3[i];
    }
}

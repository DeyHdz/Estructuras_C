#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura Empleado
typedef struct {
    char nombre[50];
    int edad;
} Empleado;

// Definimos la estructura Departamento
typedef struct {
    char nombreDepto[50];
    Empleado *empleados; // Apuntador a arreglo dinámico de empleados
    int numEmpleados;
} Departamento;

int main() {
    Departamento ventas;

    // Definimos el número de empleados
    ventas.numEmpleados = 3;

    // Asignamos memoria dinámica para los empleados
    ventas.empleados = (Empleado*) malloc(ventas.numEmpleados * sizeof(Empleado));

    // Asignamos nombre del departamento
    strcpy(ventas.nombreDepto, "Ventas");

    // Llenamos datos de los empleados
    strcpy(ventas.empleados[0].nombre, "Ana");
    ventas.empleados[0].edad = 28;

    strcpy(ventas.empleados[1].nombre, "Luis");
    ventas.empleados[1].edad = 34;

    strcpy(ventas.empleados[2].nombre, "Sofia");
    ventas.empleados[2].edad = 25;

    // Mostramos información
    printf("Departamento: %s\n", ventas.nombreDepto);
    for (int i = 0; i < ventas.numEmpleados; i++) {
        printf("Empleado %d: %s, Edad: %d\n", i + 1, ventas.empleados[i].nombre, ventas.empleados[i].edad);
    }

    // Liberamos la memoria asignada
    free(ventas.empleados);

    return 0;
}

#include <stdio.h>
#include <string.h>

// Estructura para almacenar información de un coche
typedef struct {
    char marca[20];
    char modelo[20];
    int anioFabricacion;
    float costo;
} Coche;

int main() {
    // Inicializamos una variable de tipo Coche
    Coche auto1;

    // Creamos un apuntador que apuntará a auto1
    Coche *ptrAuto = &auto1;

    // Modificamos los datos del coche usando el apuntador
    strcpy((*ptrAuto).marca, "Honda");
    strcpy((*ptrAuto).modelo, "Civic");
    (*ptrAuto).anioFabricacion = 2022;
    (*ptrAuto).costo = 21500.75;

    // Mostramos en pantalla los datos almacenados
    printf("Informacion del vehiculo:\n");
    printf("Marca: %s\n", ptrAuto->marca);
    printf("Modelo: %s\n", ptrAuto->modelo);
    printf("Anio de Fabricacion: %d\n", ptrAuto->anioFabricacion);
    printf("Costo: $%.2f\n", ptrAuto->costo);

    return 0;
}

#include <stdio.h>
#include <string.h>

// Definición de la estructura Producto
typedef struct {
    char nombre[30];
    float precio;
    int cantidad;
} Producto;

int main() {
    // Declaramos un arreglo de 3 productos
    Producto productos[3] = {
        {"Lapiz", 5.5, 100},
        {"Cuaderno", 25.0, 50},
        {"Goma", 3.0, 80}
    };

    float total = 0; // Variable para almacenar el valor total del inventario

    // Creamos un apuntador que recorrerá el arreglo
    Producto *ptrProducto = productos;

    // Recorremos los productos usando el apuntador
    for (int i = 0; i < 3; i++) {
        total += (ptrProducto + i)->precio * (ptrProducto + i)->cantidad; // Accedemos usando el apuntador
    }

    // Mostramos el valor total del inventario
    printf("Valor total del inventario: $%.2f\n", total);

    return 0;
}

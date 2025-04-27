//Crea una función que retorne una estructura Punto con coordenadas aleatorias.

#include <stdio.h>
#include <stdlib.h> // Para rand()
#include <time.h>   // Para time()

// Definición de la estructura Punto
typedef struct {
    int x;
    int y;
} Punto;

// Función que retorna un Punto con coordenadas aleatorias
Punto crearPuntoAleatorio() {
    Punto p;
    p.x = rand() % 101; // Coordenada x entre 0 y 100
    p.y = rand() % 101; // Coordenada y entre 0 y 100
    return p;
}

int main() {
    srand(time(NULL)); // Inicializar la semilla de números aleatorios

    // Creamos un punto aleatorio
    Punto miPunto = crearPuntoAleatorio();

    // Mostramos las coordenadas
    printf("Punto aleatorio generado: (%d, %d)\n", miPunto.x, miPunto.y);

    return 0;
}

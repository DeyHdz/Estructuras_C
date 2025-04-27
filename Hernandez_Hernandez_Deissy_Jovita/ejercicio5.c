//Crea un arreglo dinámico de estructuras Libro usando Malloc. Toma el Hint del ejercicio 4.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura Libro
typedef struct {
    char titulo[100];
    char autor[50];
    int anio;
} Libro;

int main() {
    int numLibros;

    printf("¿Cuántos libros deseas registrar? ");
    scanf("%d", &numLibros);

    // Reservamos memoria para los libros
    Libro *catalogo = (Libro*) malloc(numLibros * sizeof(Libro));

    // Verificamos que se haya reservado correctamente
    if (catalogo == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Llenamos los datos
    for (int i = 0; i < numLibros; i++) {
        printf("Libro #%d\n", i + 1);
        printf("Título: ");
        scanf(" %[^\n]", catalogo[i].titulo); // Leer con espacios
        printf("Autor: ");
        scanf(" %[^\n]", catalogo[i].autor);
        printf("Año: ");
        scanf("%d", &catalogo[i].anio);
    }

    // Mostramos los libros registrados
    printf("\nCatálogo de libros:\n");
    for (int i = 0; i < numLibros; i++) {
        printf("Título: %s | Autor: %s | Año: %d\n", catalogo[i].titulo, catalogo[i].autor, catalogo[i].anio);
    }

    // Liberamos la memoria
    free(catalogo);

    return 0;
}

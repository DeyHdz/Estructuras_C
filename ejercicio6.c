#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Estructura para representar un libro
typedef struct {
    char titulo[50];  // Título del libro
    char autor[50];   // Autor del libro
    int anio;         // Año de publicación
    bool disponible;  // Disponibilidad del libro
} Libro;

// Función para mostrar todos los libros en el catálogo
void mostrarLibros(Libro *catalogo, int n) {
    if (n == 0) {
        printf("\nEl catálogo está vacío.\n");
        return;
    }

    printf("\n=== CATÁLOGO DE LIBROS (%d en total) ===\n", n);
    for (int i = 0; i < n; i++) {
        printf("[%d] Título: %s | Autor: %s | Año: %d | Disponible: %s\n",
               i + 1,
               catalogo[i].titulo,
               catalogo[i].autor,
               catalogo[i].anio,
               catalogo[i].disponible ? "Sí" : "No");
    }
    printf("\n");
}

// Función para añadir un libro al catálogo
void anadirLibro(Libro **catalogo, int *n, Libro nuevo) {
    // Redimensionamos el arreglo para añadir un libro más
    *catalogo = (Libro *)realloc(*catalogo, (*n + 1) * sizeof(Libro));
    
    if (*catalogo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }
    
    // Añadimos el nuevo libro al final del arreglo
    (*catalogo)[*n] = nuevo;
    (*n)++;
    
    printf("\nLibro \"%s\" añadido correctamente.\n", nuevo.titulo);
}

// Función para eliminar un libro por índice
void eliminarLibro(Libro **catalogo, int *n, int indice) {
    if (*n == 0) {
        printf("\nEl catálogo está vacío. No hay libros para eliminar.\n");
        return;
    }
    
    if (indice < 0 || indice >= *n) {
        printf("\nError: El número de libro no es válido.\n");
        return;
    }
    
    printf("\nLibro \"%s\" eliminado correctamente.\n", (*catalogo)[indice].titulo);
    
    // Movemos todos los libros después del eliminado una posición hacia atrás
    for (int i = indice; i < *n - 1; i++) {
        (*catalogo)[i] = (*catalogo)[i + 1];
    }
    
    // Reducimos el tamaño del arreglo
    if (*n > 1) {
        *catalogo = (Libro *)realloc(*catalogo, (*n - 1) * sizeof(Libro));
        if (*catalogo == NULL) {
            printf("Error: No se pudo reasignar memoria.\n");
            exit(1);
        }
    } else {
        // Si era el único libro, liberamos la memoria y ponemos el catálogo en NULL
        free(*catalogo);
        *catalogo = NULL;
    }
    
    (*n)--;
}

// Función para leer datos de un libro desde la entrada del usuario
Libro leerLibro() {
    Libro nuevo;
    
    printf("\nIngrese los datos del nuevo libro:\n");
    
    printf("Título: ");
    scanf(" %[^\n]", nuevo.titulo);  // Lee toda la línea incluyendo espacios
    
    printf("Autor: ");
    scanf(" %[^\n]", nuevo.autor);
    
    printf("Año de publicación: ");
    scanf("%d", &nuevo.anio);
    
    // Por defecto, todos los libros nuevos están disponibles
    nuevo.disponible = true;
    
    return nuevo;
}

// Función para mostrar el menú de opciones
void mostrarMenu() {
    printf("\n=== SISTEMA DE GESTIÓN DE BIBLIOTECA ===\n");
    printf("1. Ver catálogo\n");
    printf("2. Añadir un libro\n");
    printf("3. Eliminar un libro\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
}

int main() {
    Libro *catalogo = NULL;  // Inicialmente el catálogo está vacío
    int totalLibros = 0;     // Contador de libros
    int opcion;              // Opción del menú
    int numLibro;            // Para eliminar libros
    
    printf("¡Bienvenido al Sistema de Gestión de Biblioteca!\n");
    
    // Bucle principal del programa
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:  // Ver catálogo
                mostrarLibros(catalogo, totalLibros);
                break;
                
            case 2:  // Añadir un libro
                {
                    Libro nuevoLibro = leerLibro();
                    anadirLibro(&catalogo, &totalLibros, nuevoLibro);
                }
                break;
                
            case 3:  // Eliminar un libro
                mostrarLibros(catalogo, totalLibros);
                if (totalLibros > 0) {
                    printf("Ingrese el número del libro que desea eliminar (1-%d): ", totalLibros);
                    scanf("%d", &numLibro);
                    eliminarLibro(&catalogo, &totalLibros, numLibro - 1);  // Restamos 1 porque mostramos desde 1
                }
                break;
                
            case 4:  // Salir
                printf("\nSaliendo del programa. ¡Hasta pronto!\n");
                break;
                
            default:
                printf("\nOpción no válida. Por favor, intente de nuevo.\n");
        }
        
    } while (opcion != 4);
    
    // Liberamos la memoria antes de salir
    if (catalogo != NULL) {
        free(catalogo);
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un paciente
typedef struct Paciente {
    char nombre[50];
    int edad;
    char diagnostico[50];
    int prioridad; // 1-3, donde 1 es urgente
    struct Paciente* siguiente;
} Paciente;

// Función para agregar un paciente al inicio de la lista
Paciente* agregarPacienteAlInicio(Paciente* cabeza, const char* nombre, int edad, const char* diagnostico, int prioridad) {
    // Validar la prioridad
    if (prioridad < 1 || prioridad > 3) {
        printf("Error: La prioridad debe estar entre 1 y 3\n");
        return cabeza;
    }

    // Crear nuevo nodo
    Paciente* nuevoNodo = (Paciente*)malloc(sizeof(Paciente));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return cabeza;
    }

    // Llenar datos del paciente
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->edad = edad;
    strcpy(nuevoNodo->diagnostico, diagnostico);
    nuevoNodo->prioridad = prioridad;
    nuevoNodo->siguiente = cabeza;

    // Retornar la nueva cabeza
    return nuevoNodo;
}

// Función para eliminar un paciente por nombre
Paciente* eliminarPaciente(Paciente* cabeza, const char* nombre) {
    Paciente *actual = cabeza, *anterior = NULL;
    
    // Buscar el paciente
    while (actual != NULL && strcmp(actual->nombre, nombre) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    // Si no se encontró el paciente
    if (actual == NULL) {
        printf("Paciente '%s' no encontrado\n", nombre);
        return cabeza;
    }
    
    // Eliminar el paciente (primer nodo)
    if (anterior == NULL) {
        cabeza = actual->siguiente;
    } else {
        // Eliminar el paciente (nodo intermedio o final)
        anterior->siguiente = actual->siguiente;
    }
    
    printf("Paciente '%s' eliminado correctamente\n", nombre);
    free(actual);
    return cabeza;
}

// Función para mostrar la lista de pacientes
void mostrarPacientes(Paciente* cabeza) {
    Paciente* actual = cabeza;
    int contador = 0;
    
    printf("\n===== LISTA DE PACIENTES =====\n");
    
    if (actual == NULL) {
        printf("La lista está vacía\n");
        return;
    }
    
    printf("NOMBRE\t\tEDAD\tDIAGNÓSTICO\t\tPRIORIDAD\n");
    printf("----------------------------------------------------------\n");
    
    while (actual != NULL) {
        printf("%s\t%d\t%s\t\t%d %s\n", 
               actual->nombre, 
               actual->edad, 
               actual->diagnostico, 
               actual->prioridad,
               actual->prioridad == 1 ? "(Urgente)" : actual->prioridad == 2 ? "(Media)" : "(Baja)");
        actual = actual->siguiente;
        contador++;
    }
    
    printf("----------------------------------------------------------\n");
    printf("Total de pacientes: %d\n", contador);
}

// Función para liberar la memoria de la lista
void liberarLista(Paciente* cabeza) {
    while (cabeza != NULL) {
        Paciente* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    Paciente* lista = NULL;
    
    printf("Sistema de Gestión de Pacientes del Hospital\n");
    printf("-------------------------------------------\n\n");
    
    // Agregar 10 pacientes con diferentes prioridades
    lista = agregarPacienteAlInicio(lista, "María López", 45, "Neumonía", 1);
    lista = agregarPacienteAlInicio(lista, "Juan Pérez", 32, "Fractura de brazo", 2);
    lista = agregarPacienteAlInicio(lista, "Ana Gómez", 28, "Migraña", 3);
    lista = agregarPacienteAlInicio(lista, "Carlos Ruiz", 65, "Infarto", 1);
    lista = agregarPacienteAlInicio(lista, "Sofía Martínez", 19, "Apendicitis", 1);
    lista = agregarPacienteAlInicio(lista, "Pedro Sánchez", 50, "Diabetes descompensada", 2);
    lista = agregarPacienteAlInicio(lista, "Lucía Fernández", 37, "Infección urinaria", 3);
    lista = agregarPacienteAlInicio(lista, "Roberto Díaz", 72, "Hipertensión", 2);
    lista = agregarPacienteAlInicio(lista, "Elena Castro", 24, "Traumatismo craneal", 1);
    lista = agregarPacienteAlInicio(lista, "Javier Moreno", 41, "Cólico renal", 2);
    
    // Mostrar la lista original
    printf("Lista original de pacientes:\n");
    mostrarPacientes(lista);
    
    // Eliminar 2 pacientes específicos
    printf("\nEliminando pacientes...\n");
    lista = eliminarPaciente(lista, "Ana Gómez");
    lista = eliminarPaciente(lista, "Javier Moreno");
    
    // Mostrar la lista actualizada
    printf("\nLista actualizada después de eliminar pacientes:\n");
    mostrarPacientes(lista);
    
    // Liberar memoria
    liberarLista(lista);
    
    printf("\nLista finalizado correctamente.\n");
    return 0;
}

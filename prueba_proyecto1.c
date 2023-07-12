#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    int repeticiones;
} ParNumeroRepeticiones;

void contarRepeticiones(const char* cadena) {
    int longitud = strlen(cadena);

    char* cadenaMutable = malloc((longitud + 1) * sizeof(char)); // Crear una copia mutable de la cadena
    strcpy(cadenaMutable, cadena); // Copiar la cadena original a la cadena mutable

    char* token = strtok(cadenaMutable, "#"); // Separar la cadena por el carácter '#'
    ParNumeroRepeticiones* pares = malloc(longitud * sizeof(ParNumeroRepeticiones));
    int numPares = 0;

    while (token != NULL) {
        int numero = atoi(token);

        // Buscar el número en los pares existentes
        int i;
        for (i = 0; i < numPares; i++) {
            if (pares[i].numero == numero) {
                pares[i].repeticiones++;
                break;
            }
        }

        // Si el número no se encontró, agregarlo como nuevo par
        if (i == numPares) {
            pares[numPares].numero = numero;
            pares[numPares].repeticiones = 1;
            numPares++;
        }

        token = strtok(NULL, "#"); // Obtener el siguiente token
    }

    for (int i = 0; i < numPares; i++) {
        printf("(%d, %d) ", pares[i].numero, pares[i].repeticiones);
    }

    free(pares); // Liberar la memoria asignada para los pares
    free(cadenaMutable); // Liberar la memoria asignada para la cadena mutable

    printf("\n");
}

int main() {
    const char* cadena = "#2#2#3#3#3#3#3#5#5#5#5#11#11#121";
    contarRepeticiones(cadena);

    return 0;
}

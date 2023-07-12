#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} lista_asociada;

void contarRepeticiones(const char* cadena) {
    int longitud_cadena = strlen(cadena);

    char* cadena_dinamica = malloc((longitud_cadena + 1) * sizeof(char)); // Crear una copia mutable de la cadena
    strcpy(cadena_dinamica, cadena); // Copiar la cadena original a la cadena mutable

    char* token = strtok(cadena_dinamica, "#"); // Separar la cadena por el carácter '#'
    lista_asociada* repeticiones = malloc(longitud_cadena * sizeof(lista_asociada));
    int elemento = 0;

    while (token != NULL) {
        int numero = atoi(token);

        // Buscar el número en las repeticiones existentes
        int i;
        for (i = 0; i < elemento; i++) {
            if (repeticiones[i].x == numero) {
                repeticiones[i].y++;
                break;
            }
        }

        // Si el número no se encontró, agregarlo como nuevo par
        if (i == elemento) {
            repeticiones[elemento].x = numero;
            repeticiones[elemento].y = 1;
            elemento++;
        }

        token = strtok(NULL, "#"); // Obtener el siguiente token
    }

    for (int i = 0; i < elemento; i++) {
        printf("(%d, %d) ", repeticiones[i].x, repeticiones[i].y);
    }

    free(repeticiones); // Liberar la memoria asignada para los repeticiones
    free(cadena_dinamica); // Liberar la memoria asignada para la cadena mutable

    printf("\n");
}

int main() {
    const char* cadena = "#1#1#1#1#1#2#2#121";
    contarRepeticiones(cadena);

    return 0;
}

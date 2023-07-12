#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contarRepeticiones(const char* cadena) {
    int longitud = strlen(cadena);

    if (longitud == 0) {
        return;
    }

    char* cadenaMutable = malloc((longitud + 1) * sizeof(char)); // Crear una copia mutable de la cadena
    strcpy(cadenaMutable, cadena); // Copiar la cadena original a la cadena mutable

    char* token = strtok(cadenaMutable, "#"); // Separar la cadena por el carácter '#'
    int numPares = 0;
    typedef struct {
        int numero;
        int repeticiones;
    } ParNumeroRepeticiones;
    ParNumeroRepeticiones* pares = malloc(longitud * sizeof(ParNumeroRepeticiones));

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

char* factorizarPrimos(long long int numero) {
    int factor = 2;
    int n = 1000;
    char* factores = malloc(n * sizeof(char));
    factores[0] = '\0';

    while (numero > 1) {
        if (numero % factor == 0) {
            char temp[100];
            sprintf(temp, "#%d", factor);
            strcat(factores, temp);
            numero /= factor;
        } else {
            factor++;
        }
    }

    return factores;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Solo es permitido ingresar 1 número entero.\n");
        return 1;
    }

    long long int numero = abs(atoll(argv[1]));

    char* mensaje = factorizarPrimos(numero);

    contarRepeticiones(mensaje);
    printf("%s\n", mensaje);

    free(mensaje);

    return 0;
}

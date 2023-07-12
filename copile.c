#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    free(factores);
}



int main(int argc, char *argv[]) {
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

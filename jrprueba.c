#include <stdio.h>
#include <stdlib.h>


int** crear_matriz(int filas, int columnas) {
    // Reservar memoria para un arreglo de punteros a enteros
    int** matriz = (int**)malloc(filas * sizeof(int*));
    if (matriz == NULL) {
        printf("Error al reservar memoria.\n");
        return NULL;
    }

    // Reservar memoria para cada fila de la matriz
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*)malloc(columnas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Error al reservar memoria.\n");

            // Liberar memoria previamente reservada
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);

            return NULL;
        }
    }

    // Obtener los números del usuario y asignarlos a la matriz
    printf("Ingrese los valores para cada posición de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        printf("Fila %d:\n", i);
        for (int j = 0; j < columnas; j++) {
            printf("Valor en la posición (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    return matriz;
}


int main() {
    int filas, columnas;

    // Obtener las dimensiones de la matriz del usuario
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);

    // Obtener las direcciones de memoria de las filas
    int** matriz_obtenida = crear_matriz(filas, columnas);

    if (matriz_obtenida != NULL) {
        // Imprimir las direcciones de memoria de las filas
        printf("Direcciones de memoria de las filas:\n");
        for (int i = 0; i < filas; i++) {
            printf("Fila %d: %p\n", i, (void*)matriz_obtenida[i]);
        }

        // Imprimir la matriz utilizando aritmética de puntero
        printf("Matriz formada mediante aritmética de punteros:\n");
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                printf("%d ", *(*(matriz_obtenida + i) + j));
        } printf("\n"); }

        // Liberar memoria reservada para las filas
        for (int i = 0; i < filas; i++) {
            free(matriz_obtenida[i]);
        }
        free(matriz_obtenida);

        return 0;
    }

    return -1;
}

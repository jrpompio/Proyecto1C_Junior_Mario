#include <stdio.h>
#include <stdlib.h>

int crearMatriz(int*** matriz, int*** listaPunteros, int filas, int columnas) {
    *matriz = (int**)malloc(filas * sizeof(int*));
    *listaPunteros = (int**)malloc(filas * sizeof(int*));

    for (int i = 0; i < filas; i++) {
        (*matriz)[i] = (int*)malloc(columnas * sizeof(int));
        (*listaPunteros)[i] = (*matriz)[i];  // Guardar el puntero de la primera componente
    }

    printf("Ingrese los elementos de la matriz:\n");

    for (int i = 1; i < filas + 1; i++) {
        for (int j = 1; j < columnas + 1; j++) {
            printf("Ingrese la componente (%d, %d): ", i, j);
            if (scanf("%d", &((*matriz)[i-1][j-1])) != 1) {
                return -1;  // Se ingresó algo distinto a un número entero
            }
        }
    }

    return 0;  // Todo se ingresó correctamente
}

void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void imprimirMatriz(int** matriz, int filas, int columnas) {
    printf("Su matriz es:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (j == 0) {
                printf("(");
            }
            if (j == columnas - 1) {
                printf("%d", matriz[i][j]);
            } else {
                printf("%d ", matriz[i][j]);
            }
            if (j == columnas - 1) {
                printf(")");
            }
        }
        printf("\n");
    }
}

void imprimirListaPunteros(int** listaPunteros, int filas) {
    printf("Lista de punteros:\n");
    for (int i = 0; i < filas; i++) {
        printf("%p\n", (void*)listaPunteros[i]);
    }
}

void imprimirMatrizConPunteros(int** listaPunteros, int filas, int columnas) {
    printf("Valores de la matriz utilizando punteros:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", *(*(listaPunteros + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int** matriz;
    int** listaPunteros;
    int filas, columnas;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    if (crearMatriz(&matriz, &listaPunteros, filas, columnas) == -1) {
        printf("ValueError: Solo puede ingresar números enteros.\n");
    } else {
        // Realizar operaciones con la matriz...

        // Imprimir la matriz
        imprimirMatriz(matriz, filas, columnas);

        // Imprimir la lista de punteros
        imprimirListaPunteros(listaPunteros, filas);

        imprimirMatrizConPunteros(listaPunteros, filas, columnas);

        // Liberar la memoria
        liberarMatriz(matriz, filas);
    }

    return 0;
}
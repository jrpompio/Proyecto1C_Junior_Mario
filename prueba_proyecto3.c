#include <stdio.h>
#include <stdlib.h>

int crearMatriz(int*** matriz, int*** listaPunteros, int filas, int columnas) {
    *matriz = (int**)malloc(filas * sizeof(int*)); // Reservar memoria para las filas de la matriz
    *listaPunteros = (int**)malloc(filas * sizeof(int*)); // Reservar memoria para los punteros de la lista

    for (int i = 0; i < filas; i++) {
        (*matriz)[i] = (int*)malloc(columnas * sizeof(int)); // Reservar memoria para las columnas de la matriz
        (*listaPunteros)[i] = (*matriz)[i]; // Asignar los punteros de la lista a las filas de la matriz
    }

    printf("Ingrese los elementos de la matriz:\n");

    for (int i = 1; i < filas + 1; i++) {
        for (int j = 1; j < columnas + 1; j++) {
            printf("Ingrese la componente (%d, %d): ", i, j);
                printf("---%d---", ((*matriz)[i-1][j-1]));
            if (scanf("%d", &((*matriz)[i-1][j-1])) != 1) {// Leer el elemento y verificar si es un número entero
                return -1; // Devolver -1 en caso de error
            }
        }
    }

    return 0; // Devolver 0 si la matriz se creó correctamente
}

void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]); // Liberar la memoria de las columnas de la matriz
    }
    free(matriz); // Liberar la memoria de las filas de la matriz
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
        imprimirMatriz(matriz, filas, columnas);
        imprimirListaPunteros(listaPunteros, filas);
        imprimirMatrizConPunteros(listaPunteros, filas, columnas);
        liberarMatriz(matriz, filas);
    }

    return 0;
}

/******************************************************************************

Proyecto3.c - Realizado por:
Junior Alfonso Ruiz Sánchez - B97026
Mario Fabian Rocha Morales - B96561

Programa que crea una matriz de cualquier tamaño y crea una lista de punteros 
de las primeras componentes de las filas de cada matriz.

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*Fución que crea la matriz y la lista de punteros usando memoria dinámica
tanto para la matriz como para la lista de punteros de la primera componente
de cada fila de la matriz*/
int crearMatriz(int*** matriz, int*** listaPunteros, int filas, int columnas) {
    *matriz = (int**)malloc(filas * sizeof(int*));
    *listaPunteros = (int**)malloc(filas * sizeof(int*));
    int i, j;

    for (i = 0; i < filas; i++) {
        (*matriz)[i] = (int*)malloc(columnas * sizeof(int));
        // Guardar el puntero de la primera componente.
        (*listaPunteros)[i] = (*matriz)[i];
    }

    printf(
        "Digite las componentes de la matriz:\n"
        );

    for (i = 1; i < filas + 1; i++) {
        for (j = 1; j < columnas + 1; j++) {
            printf(
                "Ingrese la componente (%d, %d): ", i, j
            );
            if (scanf("%d", &((*matriz)[i-1][j-1])) != 1) {
                return -1;  // Error al digitar los valores.
            }
        }
    }

    return 0;  // Todo se ingresó correctamente
}

void imprimirMatriz(int** matriz, int filas, int columnas) {
    int i, j;
    printf(
        "Su matriz es:\n"
    );
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
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
    printf(
        "Punteros de las primeras componentes de cada fila:\n"
    );
    for (int i = 0; i < filas; i++) {
        printf("%p\n", (void*)listaPunteros[i]);
    }
}

void MatrizConPunteros(int** listaPunteros, int filas, int columnas) {
    printf(
        "Matriz formada mediante aritmética de punteros:\n"
    );
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", *(*(listaPunteros + i) + j));
        }
        printf("\n");
    }
}

void liberarMemoria(int** matriz, int filas, int** listaPunteros) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(listaPunteros);
}

int main() {
    int** matriz;
    int** listaPunteros;
    int filas, columnas;

    printf(
        "Programa para generar una matris de M columnas\n"
        "y N filas y optener el puntero de la primera\n"
        "componente de cada fila (solo números enteros).\n"
        "-------------------------------------------------\n"
    );

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Condicional que imprime mensaje de error si se digitan mal
    // las componentes de la matriz.
    if (crearMatriz(&matriz, &listaPunteros, filas, columnas) == -1) {
        printf("ValueError: Solo puede ingresar números enteros.\n");
    } else {

        // Imprime la matriz.
        imprimirMatriz(matriz, filas, columnas);

        // Imprime la lista de punteros.
        imprimirListaPunteros(listaPunteros, filas);

        // Imprime la matriz usando aritmética de punteros.
        MatrizConPunteros(listaPunteros, filas, columnas);

        // Libera la memoria
        liberarMemoria(matriz, filas, listaPunteros);
    }

    return 0;
}
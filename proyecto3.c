/******************************************************************************

Proyecto3.c

Realizado por:
    Junior Alfonso Ruiz Sánchez - B97026
    Mario Fabian Rocha Morales - B96561

Uso:
    Programa que crea una matriz de cualquier tamaño y crea una lista de 
    punteros de las primeras componentes de las filas de cada matriz.

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Función que crea la matriz y la lista de punteros usando memoria dinámica
tanto para la matriz como para la lista de punteros de la primera componente
de cada fila de la matriz */
int crearMatriz(int*** matriz, int*** list_punteros, int filas, int columnas) {
    *matriz = (int**)malloc(filas * sizeof(int*));  // Tamaño de la matriz (filas).
    *list_punteros = (int**)malloc(filas * sizeof(int*));  // Tamaño de la lista.
    int i, j; // Variables de control.

    // ciclo para iterar sobre cada fila.
    for (i = 0; i < filas; i++) {
        // Tamaño de la matriz (columas).
        (*matriz)[i] = (int*)malloc(columnas * sizeof(int));
        // Guardar el puntero de la primera componente.
        (*list_punteros)[i] = (*matriz)[i];
    }

    printf(
        "Digite las componentes de la matriz:\n"
        );

    // Ciclos for para rellear la matriz con los valores que el
    // usuario ingrese.
    for (i = 1; i < filas + 1; i++) {
        for (j = 1; j < columnas + 1; j++) {
            printf(
                "Ingrese la componente (%d, %d): ", i, j
            );
            // Condicional para rellenar la matriz y retornar un -1 si
            // se ingresa un caracter inválido, cuando el scanf no logra
            // leer el valor ingresado retorna algo distinto de 1, entonces
            // la función retorna -1.
            if (scanf("%d", &((*matriz)[i-1][j-1])) != 1) {
                return -1;  // Error al digitar los valores.
            }
        }
    }

    return 0;  // Retora 0 si la matriz se rellena correctamente.
}

void ImprimirMatriz(int** matriz, int filas, int columnas) {
    int i, j; // Variables de control.
    printf(
        "Su matriz es:\n"
    );
    // Ciclo for para imprimir la matriz componente por componente.
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (j == 0) {
                printf("(");  // Paréntesis de la izquierda.
            }
            if (j == columnas - 1) {
                printf("%d", matriz[i][j]);
            } else {
                printf("%d ", matriz[i][j]);
            }
            if (j == columnas - 1) {
                printf(")");  // Paréntesis de la derecha.
            }
        }
        printf("\n");
    }
}

void ImprimirListadePunteros(int** list_punteros, int filas) {
    int i;
    printf(
        "Punteros de las primeras componentes de cada fila:\n"
    );
    // Ciclo for para imprimir cada componente de la lista de punteros.
    for (i = 0; i < filas; i++) {
        printf("%p\n", (void*)list_punteros[i]);
    }
}

// Fución para imprimir la matriz usando aritmética de punteros.
void MatrizConPunteros(int** list_punteros, int filas, int columnas) {
    int i, j;
    printf(
        "Matriz formada mediante aritmética de punteros:\n"
    );
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (j == 0) {
                printf("(");  // Paréntesis de la izquierda.
            }
            if (j == columnas - 1) {
                printf("%d", *(*(list_punteros + i) + j));
            } 
            else {
                printf("%d ", *(*(list_punteros + i) + j));
            }
            if (j == columnas - 1) {
                printf(")");  // Paréntesis de la derecha.
            }

        }
        printf("\n");
    }
}

// Función para liberar memoria.
void LiberarMemoria(int** matriz, int filas, int** list_punteros) {
    int i;
    // Ciclo for para liberar el espacio de las columnas.
    for (i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(list_punteros);
}

int main() {
    int** matriz;
    int** list_punteros;
    int filas, columnas;

    printf(
        "Programa para generar una matris de M columnas\n"
        "y N filas y optener el puntero de la primera\n"
        "componente de cada fila (solo números enteros).\n"
        "------------------------------------------------\n"
    );

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Condicional que imprime mensaje de error si se digitan mal
    // las componentes de la matriz.
    if (crearMatriz(&matriz, &list_punteros, filas, columnas) == -1) {
        printf("ValueError: Solo puede ingresar números enteros.\n");
    }
    else {

        // Imprime la matriz.
        ImprimirMatriz(matriz, filas, columnas);

        // Imprime la lista de punteros.
        ImprimirListadePunteros(list_punteros, filas);

        // Imprime la matriz usando aritmética de punteros.
        MatrizConPunteros(list_punteros, filas, columnas);

        // Libera la memoria
        LiberarMemoria(matriz, filas, list_punteros);
    }

    return 0;
}
/******************************************************************************

Proyecto2.c

Realizado por:
    Junior Alfonso Ruiz Sánchez - B97026
    Mario Fabian Rocha Morales - B96561

Uso:
    Programa para calcular el ángulo entre los lados de un triángulo usando ley
    de cosenos.

******************************************************************************/

#include <stdio.h>  // Header de entrada y salida.
#include <math.h>  // Hace operaciones matemáticas.
#include <stdlib.h>  // Optiene el valor numérico de un char. 
#include <ctype.h>  // Identifica si un caracter es numero o letra.

int main(int argc, char *argv[]) {
    float a, b, c, ang_a, ang_b, ang_c;  // Variables de lados y ángulos.
    int i, k, j; //  Variables enteras para ciclos for y error de caracteres.
    
    /*Ciclo for para verificar que los caracteres de los argumentos sean los
    correctos, y capturar el error para letras y simbolos no deseados.*/
    for (i = 1; i < argc; i++) {  // Recorre la lista de argumetos.
        for (j = 0; argv[i][j] != '\0'; j++) {  // Recorre cada caracter.

            // Verifica que solo sean números, omitiento el punto.
            if (argv[i][j] != '.' && !isdigit((int)argv[i][j])) {
                k = 1; // Variable usada como identificador
            }
        }
    }

    if (k == 1) {  // Detiene el código si hay caracteneres erróneos.
       printf("ValueError: Debe digitar valores numéricos.\n");
    }

    else if (argc != 4) {  // Detiene el código si hay más o menos argumentos.
        printf(
            "ArgumentError: Recuerde que un triángulo posee tres lados.\n"
            );
    }

    else {  // Solo se ejecuta si los argumentos son correctos.

        // Tomando las medidas de los lados ("atof" los hace float).
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);

        /*Condicionales que comprueban que las medidas sean correctas, me-
        diante la suma de dos de sus lados, debe ser mayor al tercer lado.*/
        if (a + b <= c) {
            printf("MathError: Los valores digitados no son validos.\n");
        }
        else if (b + c <= a) {
            printf("MathError: Los valores digitados no son validos.\n");
        }
        else if (a + c <= b) {
            printf("MathError: Los valores digitados no son validos.\n");
        }
        else {  // Solo se ejecuta si las medidas de los lados son correctas.
        
            // Cálculo de ángulos mediante ley de cosenos.
            ang_a = acos(
                (pow(a, 2) - pow(b, 2) - pow(c, 2))/(-2 * b * c)
                );
            ang_a = ang_a * (180 / M_PI);  // Convierte de radianes a grados.

            ang_b = acos(
                (pow(b, 2) - pow(a, 2) - pow(c, 2))/(-2 * a * c)
                );
            ang_b = ang_b * (180 / M_PI);

            ang_c = acos(
                (pow(c, 2) - pow(a, 2) - pow(b, 2))/(-2 * a * b)
                );
            ang_c = ang_c * (180 / M_PI);
    
            printf(  // Muestra la medida de los lados.
                "El lado A mide: %f\n" 
                "El lado B mide: %f\n"
                "El lado C mide: %f\n", 
                a, b, c
                );
            printf(  // Muestra la medida de los ángulos en grados.
                "El algulo entre el lado B y C es: %f\n" 
                "El algulo entre el lado C y A es: %f\n"
                "El algulo entre el lado A y B es: %f\n", 
                ang_a, ang_b, ang_c
                );
        }
    }
}

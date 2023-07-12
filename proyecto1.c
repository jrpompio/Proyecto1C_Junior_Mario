/*******************************************************************************

Proyecto1.c - Realizado por:
Junior Alfonso Ruiz Sánchez - B97026
Mario Fabian Rocha Morales - B96561

Este programa...

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*******************************************************************************
prueba función
*******************************************************************************/

char* factorizarPrimos(int numero) {
    int factor = 2; // Comenzamos con el factor más pequeño
    int n = 1000;  // Tamaño deseado de la cadena
    char* factores = malloc(n * sizeof(char));
    factores[0] = '\0';  // Inicializar la cadena vacía

    while (numero > 1) {
        if (numero % factor == 0) {
            char temp[100];  // Variable temporal para almacenar el valor de factor como cadena
            sprintf(temp, "-%d", factor);
            strcat(factores, temp);  // Concatenar el valor de factor al final de la cadena factores
            numero /= factor; // Dividir el número por el factor
        } else {
            factor++; // Pasar al siguiente factor
        }
    }
    printf("\n");
    return factores;
    free(factores);
}


/*******************************************************************************
prueba función
*******************************************************************************/









// Función principal

int main(int argc, char *argv[]) {
    /* Condición para terminar el programa los argumentos son diferentes a 2
    puesto que solo se debe tener un numero entero y el argumento 0 */
     if (argc != 2) {
        printf("Debe ingresar 1 número entero nada más.\n");
        return 1; // acá se devuelve 1 para terminar el programa
    }
    // De igual manera solo se usa el argumento 1, ya que solo este es admitido
    unsigned long long int numero =  atoi(argv[1]);

    char* mensaje = factorizarPrimos(numero);
    printf("%s", mensaje);



    return 0;
}



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

/*******************************************************************************
Insertando código a probar
*******************************************************************************/

// Esta función toma como entrada una cadena de caracteres y cuenta el número de veces que cada dígito aparece consecutivamente en la cadena.
void contarRepeticiones(const char* cadena) {
    // Primero, calculamos la longitud de la cadena usando la función strlen.
    int longitud = strlen(cadena);
    int i, j, k;

    // Luego, usamos un bucle for para recorrer cada carácter de la cadena.
    for (i = 0; i < longitud; i++) {
        // Si el carácter actual es '#' y es el primer carácter de la cadena o el carácter anterior no es '#', entonces entramos en este bloque de código.
        if (cadena[i] == '#' && (i == 0 || cadena[i-2] != cadena[i])) {
            // Calculamos el valor numérico del dígito que sigue al carácter '#' restando el valor ASCII del carácter '0' al valor ASCII del dígito.
            int num = cadena[i + 1] - '0';
            // Inicializamos el contador de repeticiones en 1.
            int repeticiones = 1;

            // Usamos otro bucle for para recorrer los siguientes caracteres de la cadena, avanzando de dos en dos para saltar los caracteres '#'.
            for (j = i + 2; j < longitud; j+=2) {
                // Si el carácter actual es '#', entonces entramos en este bloque de código.
                if (cadena[j] == '#') {
                    // Calculamos el valor numérico del dígito que sigue al carácter '#' restando el valor ASCII del carácter '0' al valor ASCII del dígito.
                    int siguienteNum = cadena[j + 1] - '0';
                    // Si el siguiente dígito es igual al dígito que estamos contando, entonces incrementamos el contador de repeticiones en 1.
                    if (siguienteNum == num) {
                        repeticiones++;
                    } else {
                        // Si el siguiente dígito no es igual al dígito que estamos contando, entonces salimos del bucle for interno.
                        break;
                    }
                }
            }

            // Imprimimos el dígito y su número de repeticiones en el formato "(dígito, repeticiones)".
            printf("(%d, %d) ", num, repeticiones);
            // Actualizamos el índice del bucle for externo para saltar los caracteres que ya hemos contado.
            i = j-2;
        }
    }

    // Usamos otro bucle for para encontrar el índice del primer carácter que no sea igual al primer carácter de la cadena o cuyo dígito no sea igual al primer dígito de la cadena.
    for (k = 2; k < longitud; k += 2) {
        if (cadena[k] != cadena[0] || cadena[k + 1] != cadena[1]) {
            break;
        }
    }

    // Creamos una nueva cadena llamada nuevaCadena que tiene la misma longitud que la cadena original menos el número de elementos que estamos eliminando.
    char* nuevaCadena = malloc(longitud - i + 1);
    // Copiamos todos los elementos de la cadena original a partir del índice encontrado en el bucle for anterior en la nueva cadena.
    strcpy(nuevaCadena, cadena + i);

    // Llamamos a la función contarRepeticiones recursivamente con la nueva cadena como argumento para contar las repeticiones de los dígitos restantes.
    contarRepeticiones(nuevaCadena);

    // Liberamos la memoria asignada para la nueva cadena usando la función free.
    free(nuevaCadena);

    printf("\n");
}


/*******************************************************************************
Insertando código a probar
*******************************************************************************/

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Solo es permitido ingresar 1 n�mero entero.\n");
        return 1;
    }

    long long int numero = abs(atoll(argv[1]));

    char* mensaje = factorizarPrimos(numero);

    contarRepeticiones(mensaje);

    free(mensaje);

    return 0;
}

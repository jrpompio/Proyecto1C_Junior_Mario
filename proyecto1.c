/*******************************************************************************

Proyecto1.c

Realizado por:
    Junior Alfonso Ruiz Sánchez - B97026
    Mario Fabian Rocha Morales - B96561

Uso:
    Este programa descompone un número entero dando sus divisores primos, con sus
    respectivas potencias. El formato para la descomposición es:

        N: (d1, p1), (d2, p2), …, (dm, pm);

    donde N es el número por descomponer, d es un divisor, y p es una potencia.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Esta función sirve para factorizar los números en sus divisores primos
en el cual la salida de la función es una cadena de la forma #n#n#m#m...#z#z */

char* factorizar_primos( unsigned long int numero) {
    /* Se crea una variable inicial en el número primo menor
     diferente a 1 para sustraer
     cada divisibilidad de 2 en adelante */
    int factor = 2;
    // Se crea un una cadena mutable con un tamaño considerable
    char* factores = malloc( 1000 * sizeof(char));
    factores[0] = '\0';  // Inicializar la cadena vacía

    /* Se itera mientras número sea mayor a 1 puesto que
    no se quiere la condición en la que numero = 1
    ni menor a este*/

    while (numero > 1) {
        // Cuando el numero no tiene residuo
        if (numero % factor == 0) {
            // se crea un char temporal
            char temp[100];
            // Uso de sprint para asignar valor de "#factor" a temp
            sprintf(temp, "#%d", factor);
            // Se agrega el valor de temp al final de factores
            strcat(factores, temp);
            // Se divide el numero entre el factor
            // y se le asigna ese valor a numero
            numero /= factor;
        } else {
            // Si numero % factor tiene residuo se pasa al siguiente factor
            factor++;
        }
    }
    printf("\n");
    return factores; // Se devuelve la cadena dinamina
    free(factores); // Se libera esta memoria dentro de la función
}

/* Se crea un tipo de estructura de datos al que se le llama lista_asociada
este tipo de datos contendrá dos tipos de datos int asociados al indice del
elemento */

typedef struct {
    int x;
    int y;
} lista_asociada;

/* Se crea una función para contar las repeticiones de una cadena la cual contiene
el signo # como delimitador y así convertir ese segmento de la cadena
a tipo numérico y poder contar las veces que se repite dicho numero*/

void contar_repeticiones(const char* cadena) {
    // Se declara una variable que contiene el valor del tamaño de la cadena
    int longitud_cadena = strlen(cadena);
    int elemento = 0; // Se declara la variable elemento la cual inicia en cero

    /* Se crea una cadena mutable con malloc relativa
    al tamaño de longitud_cadena + 1 de un de una cadena
     la cual nos servirá para poder aplicar strtok()*/
    char* cadena_dinamica = malloc(
    (longitud_cadena + 1) * sizeof(char)
    );

    // Se copia la cadena original a la cadena dinámica
    strcpy(
    cadena_dinamica, cadena
    );

    // Se separa de la cadena dinámica usando carácter '#' que se presenta como
    // delimitador convirtiéndoles a nulo para sustraer el primer valor
    // y se asigna a una nueva variable, esto permite sustraer el primer valor
    // de número
    char* valor_num = strtok(
    cadena_dinamica, "#"
    );

    /*  printf("= %s\n", valor_num);
        for (int p = 0; p < longitud_cadena; p++) {
        printf("Iteración %d", p + 1);
        printf("= %c\n", valor_num[p]); } */



    /* Se utiliza el tipo de estructura creada en forma dinámica y se le asigna
     el mismo valor del tamaño de la longitud de la cadena por el tamaño de
     el tipo de estructura creada*/

    lista_asociada* repeticiones = malloc(
    longitud_cadena * sizeof(lista_asociada)
    );

    /* se itera un while mientras el valor
    de valor_num no apunte a un valor nulo*/
    while (valor_num != NULL) {
        int numero = atoi(valor_num); // se convierte este valor a int

        // printf("%d\n", numero);

        int i; // Se declara i para usar en for

        /*  Se inicia ciclo for de reconocimiento de números
          ciclo for inicia en cero para asignar en el indice 0
          del tipo de escrutara de datos creado y si el valor de la componente x
          es igual al de numero entonces se suma 1 a su componente en y
          que comienza en 1 por el if que está afuera y debajo de este
          ciclo for*/

        for (i = 0; i < elemento; i++) {
            if (repeticiones[i].x == numero) {
                repeticiones[i].y++;
                break; // Se rompe el ciclo para que una vez
                 // encontrado un valor, comience de nuevo
                 // hasta que el valor deje de ser el mismo
            }
        }

        /* El punto más importante cuando i deja de sumar + 1 por el break
         se detiene en algún valor, este valor será el indice
         en donde se guardará el numero, para la primera iteración
         no se suma + 1 por lo que el indice cero corresponde al primer numero
         a guardar para posteriormente ser usada en el for de reconocimiento */

        if (i == elemento) {
            repeticiones[elemento].x = numero;
            repeticiones[elemento].y = 1;
            elemento++;

        }

        // Ahora se vuelve a usar strtok para poder sustraer el siguiente valor
        // delimitado por #
        valor_num = strtok(NULL, "#");
    }
    // se muestran los elementos en el formato solicitado
    for (int i = 0; i < elemento; i++) {
        printf("(%d, %d), ", repeticiones[i].x, repeticiones[i].y);
    }
    // Se libera la memoria usada de los dos malloc
    free(repeticiones);
    free(cadena_dinamica);

    printf("\n");

}

// Función principal

int main(int argc, char *argv[]) {
    /* Condición para terminar el programa los argumentos son diferentes a 2
    puesto que solo se debe tener un numero entero y el argumento 0 */
     if (argc != 2) {
        printf("Debe ingresar 1 número entero nada más.\n");
        return 1; // acá se devuelve 1 para terminar el programa
    }
    // De igual manera solo se usa el argumento 1, ya que solo este es admitido
    unsigned long int numero = abs(atoi(argv[1]));
    if (numero > 1){ // if para condición numero mayor a 1
        // Uso de la función para factorizar números primos
    char* mensaje = factorizar_primos(numero);
    // print para formato de salida solicitado
    printf("%ld: ", numero);
    // Se usa la función para contar las repeticiones entregadas
    // por la función factorizar_primos
    contar_repeticiones(mensaje);
    } else if (numero == 1) { // else para el caso en el que numero = 1
    // ya que estos números tienen una condición especial
    printf(" \n El número %ld posee una condición especial\n"
           " puede representarse de la siguiente forma: \n\n"
            " %ld: (%ld , n) -->"
            " donde n es cualquier numero entero \n",
             numero, numero, numero);
    } else {
    printf("el valor %ld no es un número admitido\n ", numero);
    }

    return 0;
}



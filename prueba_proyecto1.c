#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("= %c\n", valor_num[p]); */

    }


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
        printf("(%d, %d) ", repeticiones[i].x, repeticiones[i].y);
    }
    // Se libera la memoria usada de los dos malloc
    free(repeticiones);
    free(cadena_dinamica);

    printf("\n");
}

int main() {
    const char* cadena = "#1#2#3#4#4#4#121";
    contar_repeticiones(cadena);

    return 0;
}

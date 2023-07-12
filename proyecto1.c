/*******************************************************************************

Proyecto1.c - Realizado por:
Junior Alfonso Ruiz Sánchez - B97026
Mario Fabian Rocha Morales - B96561

Este programa...

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Función para reconocer número primo:
Esta función usa el residuo de división de un numero n / (n - 1 hasta 2)
y cuenta las veces que este residuo fue cero aumentando un contador
la función devuelve este contador, por lo que si la función devuelve cero
se puede decir que este numero es primo
*/

// se declara numero como llu para tener mayor precisión
int reconocer_primo(unsigned long long int numero) {
    // se convierte el numero ingresado a valor absoluto para evitar underflow
    // ya que se está trabajando con variables únicamente positivas
    // dicho problema se supo gracias a:
    // https://www.youtube.com/shorts/xxGr3T8tDwE
    numero = abs(numero);
    // Se declaran variables a usar
    int j = 0; // Variable de contador de veces que el residuo es cero
    unsigned long long int i; // Variable para iterar el for

    for ( i = numero - 1; i >= 2; i--) {
        // si el residuo es igual a cero
        if (numero % i == 0) {
        // se aumenta el contador
            j++;
        }
    }
    return j; // la función retorna el valor del contador
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
    unsigned long long int numero =  atoi(argv[1]);
    // Se define una variable para usar la función
    // que reconoce si es número primo
    int primo_talvez = reconocer_primo(numero);
    // Si es primo
    if (primo_talvez == 0){
    // Se muestra el formato solicitado para ese número
    printf("%llu: (%llu, 1)\n", numero, numero);
    }
    else {
    printf("1");
    }



    return 0;
}


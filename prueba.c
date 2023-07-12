#include <stdio.h>
#include <stdlib.h>

int contar_primos(unsigned long long int numero) {
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




    return 0;
}


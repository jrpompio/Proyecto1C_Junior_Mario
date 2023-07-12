#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    float a, b, c, ang_a, ang_b, ang_c;
    int i, k = 1;
    
    for (i = 1; i < argc; i++) {
      int j;
      for (j = 0; argv[i][j] != '\0'; j++) {
         if (!isdigit((int)argv[i][j])) {
            k = 0;
            break;
         }
      }
    }

    if (k == 0) {
       printf("ValueError: Debe digitar valores numéricos.\n");
    }

    else if (argc != 4) {
        printf(
            "ArgumentError: Recuerde que un triángulo posee tres lados.\n"
            );
    }

    else {
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);

        if (a + b <= c) {
            printf("MathError: Los valores digitados no son validos.\n");
        }
        else if (b + c <= a) {
            printf("MathError: Los valores digitados no son validos.\n");
        }
        else if (a + c <= b) {
            printf("MathError: Los valores digitados no son validos.\n");
        }
        else {
            ang_a = acos(
                (pow(a, 2) - pow(b, 2) - pow(c, 2))/(-2 * b * c)
                );
            ang_a = ang_a * (180 / M_PI); // noqa

            ang_b = acos(
                (pow(b, 2) - pow(a, 2) - pow(c, 2))/(-2 * a * c)
                );
            ang_b = ang_b * (180 / M_PI);

            ang_c = acos(
                (pow(c, 2) - pow(a, 2) - pow(b, 2))/(-2 * a * b)
                );
            ang_c = ang_c * (180 / M_PI);
    
            printf(
                "El lado A mide: %f\n" 
                "El lado B mide: %f\n"
                "El lado C mide: %f\n", 
                a, b, c
                );
            printf(
                "El algulo entre el lado B y C es: %f\n" 
                "El algulo entre el lado C y A es: %f\n"
                "El algulo entre el lado A y B es: %f\n", 
                ang_a, ang_b, ang_c
                );
        }
    }
}

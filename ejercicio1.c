#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int es_entero_positivo(char *str) {
    if (strlen(str) == 0) return 0;

    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

long calcular_cuadrado_mostrando_pasos(int N) {
    long suma = 0;
    int impar = 1;

    printf("\nProceso de suma de impares:\n");

    for (int i = 0; i < N; i++) {
        printf("Iteracion %d: suma = %ld + %d", i + 1, suma, impar);
        suma += impar;
        printf(" = %ld\n", suma);
        impar += 2;
    }

    return suma;
}

int main() {

    char input[100];

    printf("Ingrese un numero entero positivo mayor que 0:\n");

    while (1) {

        if (fgets(input, sizeof(input), stdin) != NULL) {

            input[strcspn(input, "\n")] = 0;

            if (es_entero_positivo(input)) {

                int N = atoi(input);

                if (N > 0) {

                    long resultado = calcular_cuadrado_mostrando_pasos(N);

                    printf("\nEl cuadrado de %d es: %ld\n\n", N, resultado);

                } else {
                    printf("Debe ser mayor que cero.\n\n");
                }

            } else {
                printf("Entrada invalida. Se ignora.\n\n");
            }

            printf("Ingrese otro numero:\n");
        }
    }

    return 0;
}
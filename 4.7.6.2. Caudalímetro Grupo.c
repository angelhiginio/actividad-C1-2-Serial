/******************************************************************************
ONLINEGBD
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Integrantes del grupo: Luis Donado, Angel Higino, Isai Romero, Sanchez Juan
Ejercicio 4.7.6.2. Caudalímetro

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    int valor;
    
    int mayor = -1;
    int menor = 100;
    int suma = 0;
    int contador = 0;

    while (fgets(buffer, sizeof(buffer), stdin)) {

        // Verificamos el siguiente formato {'caudal': VALOR}
        if (sscanf(buffer, "{'caudal': %d}", &valor) == 1) {
            if (valor >= 0 && valor <= 99) {
                if (contador == 0) {
                    mayor = valor;
                    menor = valor;
                } else {
                    if (valor > mayor) mayor = valor;
                    if (valor < menor) menor = valor;
                }
                suma += valor;
                contador++;
                float promedio = (float)suma / contador;
                printf("{'ultimo': %d, 'mayor': %d, 'menor': %d, 'promedio': %.2f}\n",
                       valor, mayor, menor, promedio);
            }
        }
        // Si no se cumple el formato o el rango, se ignorará
    }

    return 0;
}
#include <Arduino.h>

#define BUFFER_SIZE 100

char buffer[BUFFER_SIZE];
int valor;

int mayor = -1;
int menor = 100;
int suma = 0;
int contador = 0;

void procesarLinea(char* linea);

void setup() {
    Serial.begin(115200);
    Serial.println("Sistema Caudalimetro listo...");
}

void loop() {

    static int index = 0;

    while (Serial.available()) {
        char c = Serial.read();

        if (c == '\n') {   // Fin de línea
            buffer[index] = '\0';
            procesarLinea(buffer);
            index = 0;     // Reiniciar buffer
        } else {
            if (index < BUFFER_SIZE - 1) {
                buffer[index++] = c;
            }
        }
    }
}

void procesarLinea(char* linea) {

    // Verifica formato {'caudal': VALOR}
    if (sscanf(linea, "{'caudal': %d}", &valor) == 1) {

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

            Serial.printf(
                "{'ultimo': %d, 'mayor': %d, 'menor': %d, 'promedio': %.2f}\n",
                valor, mayor, menor, promedio
            );
        }
    }
    // Si formato incorrecto o fuera de rango, se ignora
}
char buffer[20]; 
int posicion = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese un numero entero positivo");
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    
    if (c == '\n' || c == '\r') {
      if (posicion > 0) {
        buffer[posicion] = '\0';
        
        bool esNumerico = true;
        for (int i = 0; i < posicion; i++) {
          if (!isdigit(buffer[i])) {
            esNumerico = false;
            break;
          }
        }

        if (!esNumerico) {
          Serial.println("No se ha ingrezado un numero valido, intente de nuevo");
        } else {
          int numero = atoi(buffer);
          if (numero > 0) {
            Serial.print("Se ha ingresado el numero ");
            Serial.println(numero);

            int suma = 0;
            int impar = 1;
            for (int i = 0; i < numero; i++) {
              suma += impar;
              Serial.print("Sumando: ");
              Serial.print(impar);
              Serial.print(" -> Suma acumulada: ");
              Serial.println(suma);
              impar += 2;
            }
            Serial.println("--- Resultado final ---");
            Serial.println(suma);
            Serial.println("Ingrese un numero entero positivo");
          } else {
            Serial.println("El numero es invalido, ingrese uno nuevo");
          }
        }
        posicion = 0;
      }
    } else {
      if (posicion < sizeof(buffer) - 1) {
        buffer[posicion++] = c;
      }
    }
  }
}

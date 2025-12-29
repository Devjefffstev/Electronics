void setup() {
  pinMode(4, OUTPUT); // declaramos el pin GPIO19 como salida
}

void loop() {
  digitalWrite(4, HIGH); // encendido del LED
  delay(1000);            // espera 1 segundo
  digitalWrite(4, LOW);  // apagado del LED
  delay(1000);            // espera 1 segundo
}


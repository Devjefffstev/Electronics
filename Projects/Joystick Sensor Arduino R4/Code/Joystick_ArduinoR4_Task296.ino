#include <Arduino_LED_Matrix.h>

ArduinoLEDMatrix matrix;

int xPin = A0;
int yPin = A1;

uint8_t pixels[96]; // 8 filas x 12 columnas = 96 LEDs

void clearMatrix() {
  for (int i = 0; i < 96; i++) {
    pixels[i] = 0;
  }
}

// Función para encender un LED en fila y columna
void setPixel(int row, int col) {
  if (row >= 0 && row < 8 && col >= 0 && col < 12) {
    pixels[row * 12 + col] = 1;
  }
}

void setup() {
  matrix.begin();
}

void loop() {
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  clearMatrix();

  // Arriba → fila 0
  if (yVal > 700) {
    for (int c = 0; c < 12; c++) {
      setPixel(0, c);
    }
  }
  // Abajo → fila 7
  else if (yVal < 300) {
    for (int c = 0; c < 12; c++) {
      setPixel(7, c);
    }
  }
  // Derecha → columna 11
  if (xVal > 700) {
    for (int r = 0; r < 8; r++) {
      setPixel(r, 11);
    }
  }
  // Izquierda → columna 0
  else if (xVal < 300) {
    for (int r = 0; r < 8; r++) {
      setPixel(r, 0);
    }
  }
  // Centro → LED central (fila 3, col 6 aprox)
  else if (xVal > 400 && xVal < 600 && yVal > 400 && yVal < 600) {
    setPixel(3, 6);
  }

  // Mostrar en la matriz
  matrix.loadPixels(pixels, 96);

  delay(100);
}


void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer del DHT11");
    
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");

  delay(2000); // Espera mínima entre lecturas
}

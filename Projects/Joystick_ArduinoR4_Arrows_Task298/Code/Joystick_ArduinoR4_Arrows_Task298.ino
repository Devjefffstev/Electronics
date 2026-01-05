#include <Arduino_LED_Matrix.h>

ArduinoLEDMatrix matrix;

int xPin = A0;
int yPin = A1;
int buttonPin = 2;

uint8_t pixels[96];   // 8 filas x 12 columnas

void clearMatrix() {
  for (int i = 0; i < 96; i++) pixels[i] = 0;
}

void setPixel(int row, int col) {
  if (row >= 0 && row < 8 && col >= 0 && col < 12) {
    pixels[row * 12 + col] = 1;
  }
}

void setAllPixels() {
  for (int i = 0; i < 96; i++) pixels[i] = 1;
}

// Flecha hacia arriba (más compacta)
void drawArrowUp() {
  // cuerpo corto
  setPixel(4, 6);
  setPixel(5, 6);
  setPixel(6, 6);
  // punta pequeña
  setPixel(3, 6);
  setPixel(2, 6);
  setPixel(3, 5);
  setPixel(3, 7);
}

// Flecha hacia abajo (más compacta)
void drawArrowDown() {
  // cuerpo corto
  setPixel(2, 6);
  setPixel(3, 6);
  setPixel(4, 6);
  // punta pequeña
  setPixel(5, 6);
  setPixel(6, 6);
  setPixel(5, 5);
  setPixel(5, 7);
}

// Flecha izquierda
void drawArrowLeft() {
  for (int c = 3; c < 9; c++) setPixel(4, c);
  setPixel(4, 2); setPixel(4, 1);
  setPixel(3, 2); setPixel(5, 2);
}

// Flecha derecha
void drawArrowRight() {
  for (int c = 3; c < 9; c++) setPixel(4, c);
  setPixel(4, 9); setPixel(4, 10);
  setPixel(3, 9); setPixel(5, 9);
}

// Punto central
void drawCenterDot() {
  setPixel(3, 5); setPixel(3, 6);
  setPixel(4, 5); setPixel(4, 6);
}

void setup() {
  matrix.begin();
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);
  int buttonState = digitalRead(buttonPin);

  clearMatrix();

  // Mostrar valores en el monitor serial
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" | Y: ");
  Serial.print(yVal);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  if (buttonState == LOW) {
    setAllPixels();
    Serial.println("Botón presionado → Todos los LEDs encendidos");
  } else {
    if (yVal > 700) {
      drawArrowDown();
      Serial.println("Joystick hacia abajo → Flecha abajo");
    } else if (yVal < 300) {
      drawArrowUp();
      Serial.println("Joystick hacia arriba → Flecha arriba");
    } else if (xVal > 700) {
      drawArrowRight();
      Serial.println("Joystick derecha → Flecha derecha");
    } else if (xVal < 300) {
      drawArrowLeft();
      Serial.println("Joystick izquierda → Flecha izquierda");
    } else if (xVal > 400 && xVal < 600 && yVal > 400 && yVal < 600) {
      drawCenterDot();
      Serial.println("Joystick centrado → Punto central");
    }
  }

  matrix.loadPixels(pixels, 96);
  delay(100);
}

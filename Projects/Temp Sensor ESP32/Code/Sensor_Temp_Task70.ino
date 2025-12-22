
  #include <DHT.h>

#define DHTPIN 19       // Pin de datos del DHT11 conectado al GPIO4
#define DHTTYPE DHT11  // Tipo de sensor
#define LEDPIN 17       // Pin del LED conectado al GPIO2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);     // Inicializa comunicación serial
  dht.begin();              // Inicializa el sensor DHT11
  pinMode(LEDPIN, OUTPUT);  // Configura el pin del LED como salida
}

void loop() {
  float temp = dht.readTemperature();  // Lee la temperatura en °C

  if (isnan(temp)) {
    Serial.println("Error al leer el sensor");
    
  }

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");

  if (temp > 30.0) {
    digitalWrite(LEDPIN, HIGH);  // Enciende el LED
  } else {
    digitalWrite(LEDPIN, LOW);   // Apaga el LED
  }
    digitalWrite(LEDPIN, HIGH);  // Enciende el LED
  delay(2000);  // Espera 2 segundos antes de la siguiente lectura
      digitalWrite(LEDPIN, LOW);   // Apaga el LED
  delay(2000);  // Espera 2 segundos antes de la siguiente lectura

}

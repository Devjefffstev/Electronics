void setup() {
  pinMode(4, OUTPUT); // declare GPIO4 pin as output
}

void loop() {
  digitalWrite(4, HIGH); // turn LED on
  delay(1000);           // wait 1 second
  digitalWrite(4, LOW);  // turn LED off
  delay(1000);           // wait 1 second
}

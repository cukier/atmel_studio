void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write("Hello\n\r");
  delay(1000);
}

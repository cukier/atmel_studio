int AD0 = 14;
int AD1 = 15;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(AD0, OUTPUT);
  pinMode(AD1, OUTPUT);
  Serial.begin(9600);
}

void set_serial(int serial) {
  switch (serial) {
    case 0:
    default:
      digitalWrite(AD0, LOW);
      digitalWrite(AD1, LOW);
      break;
    case 1:
      digitalWrite(AD0, HIGH);
      digitalWrite(AD1, LOW);
      break;
  }

  delay(10);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  set_serial(0);
  Serial.println("Ligado\n");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  set_serial(1);
  Serial.println("Desligado\n");
  delay(1000);
}

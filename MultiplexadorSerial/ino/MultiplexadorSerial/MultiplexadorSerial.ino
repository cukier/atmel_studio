#define NR_PORTAS 0x02

int AD0 = 14;
int AD1 = 15;
int porta = 0;

void set_serial(int serial) {
  switch (serial) {
    case 0:
    default:
      digitalWrite(AD0, LOW);
      digitalWrite(AD1, LOW);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case 1:
      digitalWrite(AD0, HIGH);
      digitalWrite(AD1, LOW);
      digitalWrite(LED_BUILTIN, LOW);
      break;
  }

  delay(10);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(AD0, OUTPUT);
  pinMode(AD1, OUTPUT);
  Serial.begin(9600);
}

void fun1(void) {
  set_serial(0);
  Serial.println("Ligado\n");
  delay(1000);
  set_serial(1);
  Serial.println("Desligado\n");
  delay(1000);
}

int m_listen(void) {
  int ret = 0;

  do {
    ret = Serial.available();
    delay(10);
  } while (ret != Serial.available());

  return ret;
}

void fun2(void) {
  int n;
  int i;

  set_serial(porta);
  n = m_listen();

  if (n != 0) {
    Serial.print("Recebindo na porta ");
    Serial.print(porta);
    Serial.print(" ");
    Serial.print(n);
    Serial.println();

    for (i = 0; i < n; ++i) {
      Serial.print(Serial.read(), DEC);
      Serial.print(" ");
    }

    delay(500);
    n = 0;
  }

  porta++;
  porta %= NR_PORTAS;
  delay(10);
}


void loop() {
  fun2();
}

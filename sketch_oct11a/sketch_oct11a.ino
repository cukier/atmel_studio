uint16_t cont;

void setup() {
  //Serial.begin(9600);
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
  pinMode(LED_BUILTIN, OUTPUT);
}

SIGNAL(TIMER0_COMPA_vect)
{
  cont++;

  if (cont == 1000) {
    digitalWrite(LED_BUILTIN, !(digitalRead(LED_BUILTIN)));
    cont = 0;
  }
}

void loop() {
}

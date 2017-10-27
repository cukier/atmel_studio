uint16_t timestamp;

void setup() {
  timestamp = 0;
  DDRC |= (1<<DDC0);
  OCR0A = 0xFA;
  TIMSK0 |= _BV(OCIE0A);
  PORTC ^= (1 << PC0);
}

SIGNAL(TIMER0_COMPA_vect) {  
  TCNT0 = 0;
  //OCR0A = 0xAF;
  //timestamp++;

  //if (timestamp == 60000)
    PORTC ^= (1 << PC0);
}

void loop() {
  
}


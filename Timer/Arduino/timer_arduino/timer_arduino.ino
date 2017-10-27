#define REG         0x00
#define RESOLUTION  65536

unsigned char clockSelectBits;
char oldSREG;
unsigned int pwmPeriod;
void (*isrCallback)();

void interr()
{
  PORTC ^= (1 << PC0);
}

void resume()
{ 
  TCCR1B |= clockSelectBits;
}

void attachInterrupt(void (*isr)(), long microseconds)
{
  if(microseconds > 0) setPeriod(microseconds);
  isrCallback = isr;                                       // register the user's callback with the real ISR
  TIMSK1 = _BV(TOIE1);                                     // sets the timer overflow interrupt enable bit
  // might be running with interrupts disabled (eg inside an ISR), so don't touch the global state
//  sei();
  resume();                       
}

void setPeriod(long microseconds)    // AR modified for atomic access
{

  long cycles = (F_CPU / 2000000) * microseconds;                                // the counter runs backwards after TOP, interrupt is at BOTTOM so divide microseconds by 2
  if (cycles < RESOLUTION)              clockSelectBits = _BV(CS10);             // no prescale, full xtal
  else if ((cycles >>= 3) < RESOLUTION) clockSelectBits = _BV(CS11);             // prescale by /8
  else if ((cycles >>= 3) < RESOLUTION) clockSelectBits = _BV(CS11) | _BV(CS10); // prescale by /64
  else if ((cycles >>= 2) < RESOLUTION) clockSelectBits = _BV(CS12);             // prescale by /256
  else if ((cycles >>= 2) < RESOLUTION) clockSelectBits = _BV(CS12) | _BV(CS10); // prescale by /1024
  else        cycles = RESOLUTION - 1, clockSelectBits = _BV(CS12) | _BV(CS10);  // request was out of bounds, set as maximum

  oldSREG = SREG;
  cli();              // Disable interrupts for 16 bit register access
  ICR1 = pwmPeriod = cycles;                                          // ICR1 is TOP in p & f correct pwm mode
  SREG = oldSREG;

  TCCR1B &= ~(_BV(CS10) | _BV(CS11) | _BV(CS12));
  TCCR1B |= clockSelectBits;                                          // reset clock select register, and starts the clock
}

void initialize(long microseconds)
{
  TCCR1A = 0;                 // clear control register A
  TCCR1B = _BV(WGM13);        // set mode 8: phase and frequency correct pwm, stop the timer
  attachInterrupt(interr, 1000);
}

void setup() {
  initialize(1000);
}

void loop() {

}

/*
 * 15/05/2017 - interrupt changes by zohar mf from shenkar SE lab for the Tshield wearable kit
 * https://github.com/shenkarSElab/nanoRF
 *
 * Based on Joel Murphy and Yury Gitman's Pulse Sensor code
 * [see 6431f00  revisions for full License] 
 */
 
#include "PulseSensorBPM.h"



/*
 * Pinout:
 *   HAS_A_REF = set to true if you have connected
 *     the pulse sensor power pin to A-REF.
 *     If you are powering the pulse sensor below 5V,
 *     you must set HAS_A_REF to true.
 *   PIN_INPUT = Analog Input. Connected to the pulse sensor
 *    purple (signal) wire.
 *   PIN_BLINK = digital Output. Connected to an LED (and 220 ohm resistor)
 *    that will flash on each detected pulse.
 *   PIN_FADE = digital Output. Connected to an LED (and resistor)
 *    that will smoothly fade with each pulse.
 */
const boolean HAS_A_REF = false;
const int PIN_INPUT = A0;
const int PIN_BLINK = 4;    // Pin 4
const int PIN_FADE = 5;      // must be a pin that supports PWM. Can't be pin 9 or 10 (see ISR()).

/*
 * Planned time (microseconds) between calls to readSensor().
 * Note: interruptSetup() assumes this value is 2 milliseconds (2000 microseconds).
 */
const unsigned long MICROS_PER_READ = 2 * 1000L;

// PWM steps per fade step.  More fades faster; less fades slower.
const int PWM_STEPS_PER_FADE = 12;

/* 
 * fadePWM = Pulse Width Modulation value for our fading LED
 * (0 = off; 255 = full on)
 */
int fadePWM;

/*
 * The per-sample processing code.
 */
PulseSensorBPM pulseDetector(PIN_INPUT, MICROS_PER_READ / 1000L);

/*
 * If true, we've seen a beat that hasn't yet been printed.
 * Set in the ISR.
 * Cleared in loop().
 */
volatile boolean QS;

void setup() {
  /*
   * Use 115200 baud because that's what the Processing Sketch expects to read,
   * and because that speed provides about 11 bytes per millisecond.
   * 
   * If we used a slower baud rate, we'd likely write bytes faster than
   * they can be transmitted, which would mess up the timing
   * of readSensor() calls, which would make the pulse measurement
   * not work properly.
   */
  Serial.begin(115200);

  // Set up the I/O pins
  
  if (HAS_A_REF) {
    analogReference(EXTERNAL);
  }
  // PIN_INPUT is set up by the pulseDetector constructor.
  pinMode(PIN_BLINK, OUTPUT);
  digitalWrite(PIN_BLINK, LOW);
  pinMode(PIN_FADE, OUTPUT);
  fadePWM = 0;
  analogWrite(PIN_FADE, fadePWM);   // sets PWM duty cycle

  QS = false;
  interruptSetup(); // start the interrupt timer.
}

void loop() {
  
  /*
   * Every so often, send the latest Sample to the Processing Sketch.
   * We don't print every sample, because our baud rate
   * won't support that much I/O.
   */
  delay(20);
  
  Serial.print('S');
  Serial.println(pulseDetector.getSignal());

  // Coincidentally, fade the LED a bit.
  fadePWM -= PWM_STEPS_PER_FADE;
  if (fadePWM < 0) {
    fadePWM = 0;
  }
  analogWrite(PIN_FADE, fadePWM);

  // Blink the non-fading LED when the start of a pulse is detected.
  if (pulseDetector.isPulse()) {
    digitalWrite(PIN_BLINK, HIGH);
  } else {
    digitalWrite(PIN_BLINK, LOW);
  }

  // If the ISR has seen a beat, print the per-beat information.
  if (QS) {
    fadePWM = 255;  // start fading on the start of each beat.
    analogWrite(PIN_FADE, fadePWM);
    
   Serial.print('B');
    Serial.println(pulseDetector.getBPM());
    Serial.print('Q');
    Serial.println(pulseDetector.getIBI());
    if (pulseDetector.getBPM()>80)
    HIGHbpm();
     if (pulseDetector.getBPM()<78)
    LOWbpm();
    QS = false;
  }
}

void HIGHbpm(){
   Serial.println(" HIGH BPM ");
   //put your code here
}
void LOWbpm(){
   Serial.println(" LOW BPM ");
      //put your code here
}


/*
 * Sets up a Timer Interrupt for every 2ms
 */
void interruptSetup(){ 
// Initializes Timer1 to throw an interrupt every 2mS.
TCCR1A = 0x00; // DISABLE OUTPUTS AND BREAK PWM ON DIGITAL PINS 9 & 10
TCCR1B = 0x11; // GO INTO 'PHASE AND FREQUENCY CORRECT' MODE, NO PRESCALER
TCCR1C = 0x00; // DON'T FORCE COMPARE
TIMSK1 = 0x01; // ENABLE OVERFLOW INTERRUPT (TOIE1)
ICR1 = 16000;   // TRIGGER TIMER INTERRUPT EVERY 1mS  
sei();         // MAKE SURE GLOBAL INTERRUPTS ARE ENABLED
} 

//Read more: http://pulsesensor.proboards.com/thread/144/using-timer1-timer2-free-pin#ixzz4glL7U0zB
// THIS IS THE TIMER 1 INTERRUPT SERVICE ROUTINE. 
// Timer 1 makes sure that we take a reading every 2 miliseconds
ISR(TIMER1_OVF_vect){                    // triggered when Timer1 counts to 124
  cli();                                   // disable interrupts while we do this
  if (pulseDetector.readSensor()) {
    QS = true;
  }
  sei();                                   // enable interrupts when youre done!
}// end isr



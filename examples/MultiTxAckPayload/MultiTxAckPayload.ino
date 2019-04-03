

//code by Robin2
// http://forum.arduino.cc/index.php?topic=421081.msg3182137
//uses
// https://tmrh20.github.io/RF24/
//
// MultiTxAckPayload - the master or the transmitter
//   works with two Arduinos as slaves
//     each slave should the SimpleRxAckPayload program
//       one with the adress {'R','x','A','A','A'}
//         and the other with {'R','x','A','A','B'}
// 03-20-2019
// adapted to https://github.com/idiot-io/nanoRF
//

#include "switchPin.h"
#define DEBUG 0

#define FLASH_PIN 4
#define FLASH_GND_PIN 5

#define TRIG_PIN 2

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN   7
#define CSN_PIN 8

const byte numSlaves = 1;
const byte slaveAddress[numSlaves][5] = {
  {'R', 'x', 'A', 'Z', 'A'}
};

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[1] = "e";

//===============
bool state;

void setup() {
  attachInterrupt(digitalPinToInterrupt(TRIG_PIN), blink, RISING);

  pinMode(FLASH_PIN, OUTPUT);
  digitalWrite(FLASH_PIN, LOW);
  pinMode(FLASH_GND_PIN, OUTPUT);
  digitalWrite(FLASH_GND_PIN, LOW);
  pinMode(LED_BUILTIN, OUTPUT);

  radio.begin();
  delay(50);

  // open the writing pipe with the address of a slave
  radio.openWritingPipe(slaveAddress[0]);

  switchOn<LED_BUILTIN>();
}

//=============
int micro;
void loop() {
 
}
void flashOut() {
  if (state) {
    switchOn<FLASH_PIN>();
    radio.write( &dataToSend, sizeof(dataToSend) );
    switchOff<FLASH_PIN>();
    state = 0;
  }
}

void blink() {
  state = 1;
}



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

#define DEBUG 0

#define FLASH_PIN 2
#define FLASH_GND_PIN 3

#define TRIG_PIN 4
#define GND_PIN 5 //also mosfet

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
int lastTrigState, trigState;

void setup() {
  pinMode(FLASH_PIN, OUTPUT);
  digitalWrite(FLASH_PIN, LOW);
  pinMode(FLASH_GND_PIN, OUTPUT);
  digitalWrite(FLASH_GND_PIN, LOW);

  pinMode(TRIG_PIN, INPUT);
  digitalWrite(TRIG_PIN, HIGH);
  pinMode(GND_PIN, OUTPUT);
  digitalWrite(GND_PIN, LOW);

  radio.begin();
  delay(50);

  // open the writing pipe with the address of a slave
  radio.openWritingPipe(slaveAddress[0]);

}

//=============

void loop() {

  trigState = digitalRead(TRIG_PIN);
  //detect falling edge
  if (trigState != lastTrigState) {
    if (trigState == LOW) {

      //PORTD |= B11111011;

      digitalWrite(FLASH_PIN, HIGH);
      rad
  PORTD |= B11111011;
  delayMicroseconds(20);
  PORTD &= B00000100;
  delayMicroseconds(20);
  PORTD |= B11111011;
  delayMicroseconds(20);
  PORTD &= B00000100;
  delayMicroseconds(20);
  PORTD |= B11111011;
  delayMicroseconds(20);
  PORTD &= B00000100;
  delayMicroseconds(20);
  PORTD |= B11111011;
  delayMicroseconds(20);
  PORTD &= B00000100;
  delayMicroseconds(20);io.write( &dataToSend, sizeof(dataToSend) );
      //delayMicroseconds(20);
      digitalWrite(FLASH_PIN, LOW);
      //PORTD &= B00000100;
      delayMicroseconds(20);
    }
    lastTrigState = trigState;
  }
}

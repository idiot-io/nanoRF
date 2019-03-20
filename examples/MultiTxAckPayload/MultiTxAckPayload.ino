

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

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN   7
#define CSN_PIN 8

const byte numSlaves = 1;
const byte slaveAddress[numSlaves][5] = {
  {'R', 'x', 'A', 'A', 'C'}
};

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[1] = "e";
char txNum = '0';

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 33;

//===============
#define LED 4

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  radio.begin();
  radio.setAutoAck(0);
}

//=============

void loop() {

  currentMillis = millis();
  if (currentMillis - prevMillis >= txIntervalMillis) {

    ////////////////////////////////////////
    digitalWrite(LED, HIGH); //flip LED
    /////////////////////////////////////////

    send();


  }
  /////////////////////////////////
  digitalWrite(LED, LOW); //flip LED
  /////////////////////////////////
}

//================

void send() {

  // call each slave in turn
  for (byte n = 0; n < numSlaves; n++) {

    // open the writing pipe with the address of a slave
    radio.openWritingPipe(slaveAddress[n]);
    
    bool rslt;
    rslt = radio.write( &dataToSend, sizeof(dataToSend) );
  }

  prevMillis = millis();
}

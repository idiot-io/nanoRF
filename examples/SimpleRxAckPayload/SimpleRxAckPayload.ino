

// SimpleRxAckPayload- the slave or the receiver

#include "switchPin.h"
//https://github.com/fredlllll/FredUtil-Arduino/blob/master/fredOptimization.h

#define FLASH_PIN 4
#define GND_PIN 5 //also mosfet

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   7
#define CSN_PIN 8

const byte thisSlaveAddress[5] = {'R', 'x', 'A', 'Z', 'A'};

RF24 radio(CE_PIN, CSN_PIN);

char dataReceived[1]; // this must match dataToSend in the TX

//==============
#define DEBUG 0
void setup() {
  Serial.begin(115200);
  Serial.println("RX...");

  pinMode(FLASH_PIN, OUTPUT);
  pinMode(GND_PIN, OUTPUT);
  digitalWrite(GND_PIN, LOW);
  radio.begin();

  radio.setAutoAck(0);
  radio.openReadingPipe(1, thisSlaveAddress);

  radio.startListening();

}

//==========

void loop() {

  if ( radio.available() ) {
    Serial.println("got");

    switchOn<FLASH_PIN>();
    radio.read( &dataReceived, sizeof(dataReceived) );
    switchOff<FLASH_PIN>();
  }
}

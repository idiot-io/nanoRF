

// SimpleRxAckPayload- the slave or the receiver

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   7
#define CSN_PIN 8

//const byte thisSlaveAddress[5] = {'R', 'x', 'A', 'A', 'A'};
//const byte thisSlaveAddress[5] = {'R', 'x', 'A', 'A', 'B'};
const byte thisSlaveAddress[5] = {'R', 'x', 'A', 'A', 'C'};

RF24 radio(CE_PIN, CSN_PIN);

char dataReceived[1]; // this must match dataToSend in the TX

//==============
#define DEBUG 0
void setup() {
  pinMode(4, OUTPUT);

  radio.begin();
  
  radio.setAutoAck(0);
  radio.openReadingPipe(1, thisSlaveAddress);

  radio.startListening();

}

//==========

void loop() {
  if ( radio.available() ) {
    digitalWrite(4, HIGH);
    radio.read( &dataReceived, sizeof(dataReceived) );
    digitalWrite(4, LOW);
  }
}

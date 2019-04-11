// SimpleRx - the slave or the receiver

#include "switchPin.h"
#define FLASH_PIN 4
#define FLASH_GND_PIN 5


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   7
#define CSN_PIN 8

const byte thisSlaveAddress[5] = {'R', 'x', 'A', 'A', 'A'};

RF24 radio(CE_PIN, CSN_PIN);

char dataReceived[10]; // this must match dataToSend in the TX
bool newData = false;


//===========

void setup() {
  Serial.begin(115200);

  pinMode(FLASH_PIN, OUTPUT);
  pinMode(FLASH_GND_PIN, OUTPUT);
  digitalWrite(FLASH_GND_PIN, LOW);

  Serial.println("SimpleRx Starting");
  radio.begin();
  radio.setDataRate( RF24_250KBPS );
  radio.openReadingPipe(1, thisSlaveAddress);
  radio.startListening();


}

//=============

void loop() {
  getData();
  showData();
}

//==============

void getData() {
  if ( radio.available() ) {
    switchOn<FLASH_PIN>();
    radio.read( &dataReceived, sizeof(dataReceived) );
    switchOff<FLASH_PIN>();
    newData = true;
  }
}

void showData() {
  if (newData == true) {
    Serial.print("Data received ");
    Serial.println(dataReceived);
    newData = false;
  }
}

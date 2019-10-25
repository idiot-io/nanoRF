/** RF24Mesh_Example.ino by TMRh20

   This example sketch shows how to manually configure a node via RF24Mesh, and send data to the
   master node.
   The nodes will refresh their network address as soon as a single write fails. This allows the
   nodes to change position in relation to each other and the master node.
*/
//SYSTEM V2.5

#include "RF24.h"
#include "RF24Network.h"
#include "RF24Mesh.h"
#include <SPI.h>


int LED = 6;    // PWM Pin  6


/**** Configure the nrf24l01 CE and CS pins ****/
RF24 radio(10, 9);//NanoRF (7,8)
RF24Network network(radio);
RF24Mesh mesh(radio, network);

/**
   User Configuration: nodeID - A unique identifier for each radio. Allows addressing
   to change dynamically with physical changes to the mesh.

   In this example, configuration takes place below, prior to uploading the sketch to the device
   A unique value from 1-255 must be configured for each node.
   This will be stored in EEPROM on AVR devices, so remains persistent between further uploads, loss of power, etc.

 **/
#define nodeID 1//SYSTEM V2.5


uint32_t displayTimer = 0;

struct payload_t {
  unsigned long ms;
  unsigned long counter;
};

struct dataStruct1 {
  int vA1, vB1, vC1, LvibMSG; // 6 Electrodes Values
} myData;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.begin(115200);

  // Set the nodeID manually
  mesh.setNodeID(nodeID);
  // Connect to the mesh
  Serial.println(F("Connecting to the mesh..."));
  mesh.begin();
}

void loop() {

  mesh.update();

  // Send to the master node every second
  if (millis() - displayTimer >= 100) {
    displayTimer = millis();
    myData.vA1 = analogRead(A0);
    myData.vB1 = analogRead(A1);
    myData.vC1 = analogRead(A2);

    if ( myData.LvibMSG != 0) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
      myData.LvibMSG = 0;
    }

    // Send an 'M' type message containing the current millis()
    if (!mesh.write(&myData, 'M', sizeof(myData))) {

      // If a write fails, check connectivity to the mesh network
      if ( ! mesh.checkConnection() ) {
        //refresh the network address
        Serial.println("Renewing Address");
        if (!mesh.renewAddress()) {
          //If address renewal fails, reconfigure the radio and restart the mesh
          //This allows recovery from most if not all radio errors
          mesh.begin();
        }
      } else {
        Serial.println("Send fail, Test OK");
      }
    } else {
      Serial.print("Send OK: "); 
      Serial.println(displayTimer);
      Serial.print( myData.vA1); Serial.print(",");
      Serial.print( myData.vB1); Serial.print(",");
      Serial.print( myData.vC1); Serial.print(",");
      Serial.println( myData.LvibMSG);
    }
  }

  while (network.available()) {
    RF24NetworkHeader header;
        payload_t payload;
        network.read(header, &payload, sizeof(payload));
        Serial.print("Received packet #");
        Serial.print(payload.counter);
        Serial.print(" at ");
        Serial.println(payload.ms);
 
  }

}






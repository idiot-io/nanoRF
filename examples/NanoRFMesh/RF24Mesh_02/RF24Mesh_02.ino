/**
  nanorf sensor mesh -   agent
  https://github.com/idiot-io/nanoRF
  based on RF24Mesh_Example_Master.ino by TMRh20
*/


#include "RF24.h"
#include "RF24Network.h"
#include "RF24Mesh.h"
#include <SPI.h>
//#include <printf.h>

/**** Configure the nrf24l01 CE and CS pins ****/
RF24 radio(10, 9);//NanoRF (7,8)
RF24Network network(radio);
RF24Mesh mesh(radio, network);

#define nodeID 1//SYSTEM V2.5


uint32_t displayTimer = 0;
uint32_t ctr = 0;

struct dataStruct {
  int vA1, vB1, vC1; //Node01
  int vA2, vB2, vC2, LvibMSG;//Node2
};
struct dataStruct myData ; //unified data set
struct dataStruct tmpData ; //what came from a node.

void setup() {

  Serial.begin(115200);
  //printf_begin();
  // Set the nodeID manually
  mesh.setNodeID(nodeID);
  // Connect to the mesh
  Serial.println(F("Connecting to the mesh..."));
  mesh.begin();
}

void loop() {

  mesh.update();

  ////////////
  // Check for incoming data from the sensors
  ////////////
  if (network.available()) {
    RF24NetworkHeader header;
    network.peek(header);

    switch (header.type) {
      // Display the incoming millis() values from the sensor nodes
      case 'M':
        network.read(header, &tmpData, sizeof(tmpData));
        //update what we dont produce on this node
        tmpData.vA1 = myData.vA1;
        tmpData.vB1 = myData.vB1;
        tmpData.vC1 = myData.vC1;
        break;
    }
  }


  //////////////////
  // Send to the master node every second
  if (millis() - displayTimer >= 100) {
    displayTimer = millis();
    myData.vA2 = analogRead(A0);
    myData.vB2 = analogRead(A1);
    myData.vC2 = analogRead(A2);
    
    if (myData.vA2 > 600) {
    myData.LvibMSG = 1;
    }
    else  {
      myData.LvibMSG = 0;
    }

    // Send an 'M' type message containing the current millis()
    if (!mesh.write(&myData, 'M', sizeof(myData))) {

      // If a write fails, check connectivity to the mesh network
      if ( ! mesh.checkConnection() ) {
        Serial.println("Renewing Address");
        if (!mesh.renewAddress()) {
          mesh.begin();
        }
      } else {
        Serial.println("Send fail, Test OK");
      }
    } else {
      Serial.print("Send OK: "); Serial.println(displayTimer);
      Serial.print( myData.vA2); Serial.print(",");
      Serial.print( myData.vB2); Serial.print(",");
      Serial.print( myData.vC2); Serial.print(",");
      Serial.println( myData.LvibMSG);
    }
  }
}







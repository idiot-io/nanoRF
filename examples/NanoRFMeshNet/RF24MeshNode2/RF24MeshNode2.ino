
/** RF24Mesh_Example_Node2NodeExtra.ino by TMRh20

   This example sketch shows how to communicate between two (non-master) nodes using
   RF24Mesh & RF24Network
*/


#include "RF24.h"
#include "RF24Network.h"
#include "RF24Mesh.h"
#include <SPI.h>
//#include <printf.h>


/**** Configure the nrf24l01 CE and CS pins ****/
RF24 radio(7, 8);
RF24Network network(radio);
RF24Mesh mesh(radio, network);

/**
   User Configuration:
   nodeID - A unique identifier for each radio. Allows addressing to change dynamically
   with physical changes to the mesh. (numbers 1-255 allowed)

   otherNodeID - A unique identifier for the 'other' radio

 **/
#define nodeID 2
#define otherNodeID 1


uint32_t millisTimer = 0;
int LvibMSG;

struct dataStruct{
  int vA2, vB2, vC2;//Node2
} myData;

void setup() {

  Serial.begin(115200);
  // Set the nodeID
  mesh.setNodeID(nodeID);
  // Connect to the mesh
  Serial.println(F("Connecting to the mesh..."));
  mesh.begin();
}

void loop() {

  mesh.update();

  // Send to the other node every second
  if (millis() - millisTimer >= 100) {
    millisTimer = millis();
   
  myData.vA2 = analogRead(A0);
  myData.vB2 = analogRead(A1);
  myData.vC2 = analogRead(A2);
  
    if (myData.vA2 > 600) {
      LvibMSG = 1;
    }
    else  {
      LvibMSG = 0;
    }

    // Send an 'V' type to other Node(1) containing the LvibMSG
    if (!mesh.write(&LvibMSG, 'V', sizeof( LvibMSG), otherNodeID)) {
      
      if ( ! mesh.checkConnection() ) {
        Serial.println("Renewing Address");
        mesh.renewAddress();
      } else {
        Serial.println("Send fail, Test OK");
      }
    }
        // Send an 'M' type to  MasterNode(0) containing the myData
    if (!mesh.write(&myData, 'M', sizeof(myData))) {
      if ( ! mesh.checkConnection() ) {
        Serial.println("Renewing Address");
        mesh.renewAddress();
      } else {
        Serial.println("Send fail, Test OK");
      }
    }
    
  }

}


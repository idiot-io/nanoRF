
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
RF24 radio(7,8);
RF24Network network(radio);
RF24Mesh mesh(radio, network);

/**
   User Configuration:
   nodeID - A unique identifier for each radio. Allows addressing to change dynamically
   with physical changes to the mesh. (numbers 1-255 allowed)

   otherNodeID - A unique identifier for the 'other' radio

 **/
#define nodeID 3 
#define otherNodeID 1 

uint32_t millisTimer = 0;

struct dataStruct{
  int vA1, vB1, vC1,LvibMSG;//Node1
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

  if (network.available()) {
    RF24NetworkHeader header;

    network.read(header, &myData, sizeof(myData));
    Serial.println("V2.5:");
    Serial.print(myData.vA1);Serial.print(",");
    Serial.print(myData.vB1);Serial.print(",");
    Serial.print(myData.vC1);Serial.print(",");
   // Serial.print(myData.LvibMSG);Serial.println();
    Serial.print(" from nodeID ");
    int _ID = mesh.getNodeID(header.from_node);
    if ( _ID > 0) {
      Serial.println(_ID);
    } else {
      Serial.println("Mesh ID Lookup Failed");
    }
  }


    
    
  
}

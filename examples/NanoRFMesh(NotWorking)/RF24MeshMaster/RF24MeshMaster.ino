

/** RF24Mesh_Example_Master.ino by TMRh20


   This example sketch shows how to manually configure a node via RF24Mesh as a master node, which
   will receive all data from sensor nodes.

   The nodes can change physical or logical position in the network, and reconnect through different
   routing nodes as required. The master node manages the address assignments for the individual nodes
   in a manner similar to DHCP.

*/


#include "RF24Network.h"
#include "RF24.h"
#include "RF24Mesh.h"
#include <SPI.h>
//Include eeprom.h for AVR (Uno, Nano) etc. except ATTiny
#include <EEPROM.h>

/***** Configure the chosen CE,CS pins *****/
RF24 radio(10, 9);//NanoRF (7,8)
RF24Network network(radio);
RF24Mesh mesh(radio, network);
struct payload_t {
  unsigned long ms;
  unsigned long counter;
};


uint32_t displayTimer = 0;

struct dataStruct1 {
  int vA1, vB1, vC1; //Node01
  int vA2, vB2, vC2, LvibMSG;//Node2
} myData;


void setup() {
  Serial.begin(115200);

  // Set the nodeID to 0 for the master node
  mesh.setNodeID(0);
  Serial.println(mesh.getNodeID());
  // Connect to the mesh
  mesh.begin();

}


void loop() {

  // Call mesh.update to keep the network updated
  mesh.update();

  // In addition, keep the 'DHCP service' running on the master node so addresses will
  // be assigned to the sensor nodes
  mesh.DHCP();


  // Check for incoming data from the sensors
  if (network.available()) {
    RF24NetworkHeader header;
    network.peek(header);

    //  uint32_t dat=0;
    switch (header.type) {
      // Display the incoming millis() values from the sensor nodes
      case 'M': network.read(header, &myData, sizeof(myData)); break;
      default: network.read(header, 0, 0); Serial.println(header.type); break;

    }

  }

  if (millis() - displayTimer > 100) {
    displayTimer = millis();
   Serial.println(" ");
  Serial.println(F("********Assigned Addresses********"));

//      Serial.print("NodeID: ");
//      Serial.print(mesh.addrList[1].nodeID);
//      Serial.print(" RF24Network Address: 0");
//     Serial.println(mesh.addrList[1].address, OCT);
      Serial.print( myData.vA1); Serial.print(",");
      Serial.print( myData.vB1); Serial.print(",");
      Serial.print( myData.vC1); Serial.print(",");
      Serial.println( myData.vA2); Serial.print(",");
      Serial.print( myData.vB2); Serial.print(",");
      Serial.print( myData.vC2); Serial.print(",");
      Serial.println( myData.LvibMSG);
      /////DATA END
    }
 //   Serial.println(F("**********************************"));
    
  

}

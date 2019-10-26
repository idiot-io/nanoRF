/**
  nanorf sensor mesh -  master
  https://github.com/idiot-io/nanoRF
  based on RF24Mesh_Example_Master.ino by TMRh20
*/

#include "RF24Network.h"
#include "RF24.h"
#include "RF24Mesh.h"
#include <SPI.h>
#include <EEPROM.h>

/***** Configure the chosen CE,CS pins *****/
RF24 radio(10, 9);//NanoRF (7,8)
RF24Network network(radio);
RF24Mesh mesh(radio, network);

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
  mesh.setNodeID(0);
  Serial.println(mesh.getNodeID());
  // Connect to the mesh
  mesh.begin();
}

void loop() {
  mesh.update();
  mesh.DHCP();

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
        switch (header.from_node) {
          case 1: //Node1
            Serial.println(header.from_node, OCT);
            tmpData.vA1 = myData.vA1;
            tmpData.vB1 = myData.vB1;
            tmpData.vC1 = myData.vC1;
            break;
          case 2: //Node2
            tmpData.vA2 = myData.vA2;
            tmpData.vB2 = myData.vB2;
            tmpData.vC2 = myData.vC2;
            tmpData.LvibMSG = myData.LvibMSG
            break;
        }
        break;
      default: network.read(header, 0, 0); Serial.println(header.type); break;
    }
  }

  ///////////
  //// ping back
  ///////////
  if (millis() - displayTimer > 100) {
    ctr++;
    for (int i = 0; i < mesh.addrListTop; i++) {
      RF24NetworkHeader header(mesh.addrList[i].address, OCT); //Constructing a header
      // for debuging switch to this
      //Serial.println( network.write(header, &myData, sizeof(myData)) == 1 ? F("Send OK") : F("Send Fail")); //Sending an message
      network.write(header, &myData, sizeof(myData));
    }
    displayTimer = millis();
  }
}

/*
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

*/

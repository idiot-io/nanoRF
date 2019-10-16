/** RF24Mesh_Example.ino by TMRh20

   This example sketch shows how to manually configure a node via RF24Mesh, and send data to the
   master node.
   The nodes will refresh their network address as soon as a single write fails. This allows the
   nodes to change position in relation to each other and the master node.
*/


#include "RF24.h"
#include "RF24Network.h"
#include "RF24Mesh.h"
#include <SPI.h>
//#include <printf.h>

int PWRLed = 2;    // Digital Pin  2
int ThermOut = 6;    // Mosfet Output

int Gpin = 3;    // Digital Pin  3
int Hpin = 4;    // Digital Pin  4
int Epin = 9;    // Digital Pin  9
int Fpin = 10;    // Digital Pin  10


/**** Configure the nrf24l01 CE and CS pins ****/
RF24 radio(7, 8);
RF24Network network(radio);
RF24Mesh mesh(radio, network);

/**
   User Configuration: nodeID - A unique identifier for each radio. Allows addressing
   to change dynamically with physical changes to the mesh.

   In this example, configuration takes place below, prior to uploading the sketch to the device
   A unique value from 1-255 must be configured for each node.
   This will be stored in EEPROM on AVR devices, so remains persistent between further uploads, loss of power, etc.

 **/
#define nodeID 2


uint32_t displayTimer = 0;

struct payload_t {
  unsigned long ms;
  unsigned long counter;
};

struct dataStruct {
  int A, B, C, D, E, F, G, H, T, LvibMSG; // 8 Electrodes Values
} myData;

void setup() {
  pinMode(Epin, INPUT_PULLUP);
  digitalWrite(Epin, HIGH);
  pinMode(Fpin, INPUT_PULLUP);
  digitalWrite(Fpin, HIGH);
  pinMode(Gpin, INPUT_PULLUP);
  digitalWrite(Gpin, HIGH);
  pinMode(Hpin, INPUT_PULLUP);
  digitalWrite(Hpin, HIGH);

  pinMode(PWRLed, OUTPUT);
  digitalWrite(PWRLed, HIGH);

  pinMode(ThermOut, OUTPUT);
  digitalWrite(ThermOut, LOW);

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

  // Send to the master node every second
  if (millis() - displayTimer >= 100) {
    displayTimer = millis();
    myData.A = map(analogRead(A0), 1023, 0, 0, 1023);// LickoDuino Electrode1
    myData.B = map(analogRead(A1), 1023, 0, 0, 1023);// LickoDuino Electrode2
    myData.C = map(analogRead(A2), 1023, 0, 0, 1023);// LickoDuino Electrode3
    myData.D = map(analogRead(A3), 1023, 0, 0, 1023);// LickoDuino Electrode4
   
    // Rupture Electrode1
    int E = digitalRead(Epin);
    if (E == HIGH) {myData.E = 0;} else {myData.E = 255;}
    // Rupture Electrode2
    int F = digitalRead(Fpin);
    if (F == HIGH) { myData.F = 0; }else {myData.F = 255;}
     // Rupture Electrode3
    int G = digitalRead(Gpin);
    if (G == HIGH) { myData1.G = 0;} else { myData1.G = 255; }
      // Rupture Electrode4
    int H = digitalRead(Hpin);
    if (H == HIGH) { myData.H = 0;} else {  myData.H = 255; }

    myData.T = map(analogRead(A5), 0, 1023, 0, 255);// Thermostat Pot
    analogWrite(ThermOut,  myData.T);
    
    if (myData.A > 600) {
    myData1.LvibMSG = 1;
    }
    else  {
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
      Serial.print("Send OK: "); Serial.println(displayTimer);
      Serial.print( myData.A); Serial.print(",");
      Serial.print( myData.B); Serial.print(",");
      Serial.print( myData.C); Serial.print(",");
      Serial.print( myData.D); Serial.print(",");
      Serial.print( myData.E); Serial.print(",");
      Serial.print( myData.F); Serial.print(",");
      Serial.print( myData.G); Serial.print(",");
      Serial.print( myData.H); Serial.print(",");
      Serial.print( myData.T); Serial.print(",");
      Serial.println( myData1.LvibMSG);
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







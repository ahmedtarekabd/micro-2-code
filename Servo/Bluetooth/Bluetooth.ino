#include <SoftwareSerial.h>
#define rxPin   0
#define txPin   1

SoftwareSerial hc05(rxPin, txPin);

void setup(){
  //Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc05.begin(9600);
  hc05.println("ENTER AT Commands:");
}

void loop(){
  // //Write data from HC05 to Serial Monitor
  // if (hc05.available()){
  //   Serial.println(hc05.read() - '0');
  // }
  
  //Write data from HC05 to Serial Monitor
  // Serial.println("Before");
  if (hc05.available())
  {
    Serial.println("After");
    Serial.println(hc05.read() - '0');
  }

  //Write from Serial Monitor to HC05
  if (Serial.available()){
    hc05.println(Serial.read() - '0');
  }  
}

#include "SoftwareSerial.h"
  SoftwareSerial x(10,11);


void setup() {

  x.begin(9600);
}

void loop() {
  char c = x.read();
 
  x.println(c); //Print data on Serial Monitor
  Serial.println("\n");
  delay(1000);
}

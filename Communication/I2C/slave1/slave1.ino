#include "Wire.h"
char x;


void setup() {
  Serial.begin(9600);
  Wire.begin(9);
  Wire.onReceive(Event);
}

void Event(char bytes){
  x = Wire.read();
  Serial.print("The character that you entered in the other Arduino is ");
  Serial.println(x);
}

void loop() {
  delay(100);
}

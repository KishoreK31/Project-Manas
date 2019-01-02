#include "Wire.h"
char ch;

void setup() {
  
  Serial.begin(9600);
  Wire.begin();

}

void loop() {
  while(Serial.available()==0)
  {}
  ch=Serial.read();
  delay(100);
  Serial.print("The character that you entered is ");
  Serial.println(ch);

  Wire.beginTransmission(9);
 
  Wire.write(ch);
  Wire.endTransmission();
  
}

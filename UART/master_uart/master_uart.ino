#include "SoftwareSerial.h"
char mystr;
int i;
SoftwareSerial a(10,11);
void setup() {
 
  a.begin(9600);
  
}

void loop() {
  
  mystr=a.read();
  
  a.write(mystr); 
  
  delay(1000);
}

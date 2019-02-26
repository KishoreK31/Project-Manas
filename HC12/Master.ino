
#include <SoftwareSerial.h>

#define setpin 6

int i,m[5] = {0};

SoftwareSerial HC12(11,12); //Sets 11 and 12 as Tx and Rx pins
  
void setup() {
    Serial.begin(9600);
    pinMode(setpin,OUTPUT);
    digitalWrite(setpin,HIGH);
    Serial.print("AT+C001");
    Serial.print("AT+RX");
  
    
}

void loop() {
    Serial.println("Enter 5 integers?");
    
    for(i=0;i<5;i++){
      if(Serial.available()>0)
        m[i] = Serial.read();
    }
   

  Serial.println("Now sending to slave");
  
  for(i=0;i<5;i++){
      HC12.write("%d",&m[i]);
    }
}

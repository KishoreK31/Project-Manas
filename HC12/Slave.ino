
#include <SoftwareSerial.h>

#define setpin 6

int i,num=0,n = 0;

SoftwareSerial HC12(11,12); //Sets 11 and 12 as Tx and Rx pins
  
void setup() {
    Serial.begin(9600);
    pinMode(setpin,OUTPUT);
    digitalWrite(setpin,HIGH);
    Serial.print("AT+C001");
    Serial.print("AT+RX");
  
    
}

void loop() {
  if(HC12.available()>0){
    num = num*10 + HC1.read();
  }
  
  for(i=0;i<5;i++)//To print the received integers from number
  {
    n=num%10;
  
    Serial.println(n);
    num = (num-n)/10;
    
    
  }
}


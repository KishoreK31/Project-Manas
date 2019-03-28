#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio(7, 8);

const byte address[6] = "00001";
char text = 'a';

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setDataRate(RF24_1MBPS);
  radio.setChannel(1);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() { 
  
  if (Serial.available()) {
    
    text = Serial.read();
    Serial.println(text);
    radio.startWrite(&text, sizeof(text+1));
      }
  
}

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio(7, 8); //ce,csn

const byte address[6] = "00001";
char text = 'a';


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setDataRate(RF24_1MBPS);
  radio.setChannel(1);
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if(radio.available()) {
   
    radio.read(&text, sizeof(text+1));
    Serial.println(text);
      }
}

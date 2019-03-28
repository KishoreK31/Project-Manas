#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio(7, 8); //ce,csn

const byte address[6] = "00001";
char text[20] = "";
int  i;

void write_to_array();
void print();
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
  while (radio.available()) {
   
    write_to_array();
    print();

  }


}

void write_to_array() {
  radio.read(text, strlen(text)+1);
  
  
}


void print() {
  Serial.println(text);

}

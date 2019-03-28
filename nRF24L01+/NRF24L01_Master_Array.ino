//Doing this with integer array with 5 elements
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio(7, 8);

const byte address[6] = "00001";
char text[20] = "";
int flag;
char *p;
int i;

void print();
void read();
void rfwrite();
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setDataRate(RF24_1MBPS);
  radio.setChannel(1);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  flag = 0;
  p = text;
}

void loop() {


  if (Serial.available()) {
    read();

  }
  if (flag) {
    print();
    rfwrite();

  }


}

void print() {
  Serial.println(text);
  flag = 0;
}

void read() {

  p = &text[0];
  if (Serial.available()) {
    for (i = 0; Serial.available(); p++, i++) {
      *p = Serial.read();
    }
    text[i + 1] = '\0';
    flag = 1;
  }

}

void rfwrite() {

  radio.startWrite(text, strlen(text));

}

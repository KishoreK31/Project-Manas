#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio(7, 8); //Set up nRF24L01 on CE pin and CSN pin respectively

const uint64_t pipe = 0x0ABCDEF; //Address for communication between master and slave
uint16_t rx_data[7];             //Array to store the data
const uint16_t buffer_size = sizeof(rx_data); //Size of the payload for the RF
int i,rx_counter=0;             // rx_counter counts the number of reception
bool flag;

void print();
void setup() {
  Serial.begin(115200);

  //*****Radio settings****// [Should match master's]
  radio.begin();
  radio.setChannel(2);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(1, pipe); //Pipe address to read the data from
  radio.startListening();         //Starts the module as receiver
}

void loop() {
  while (radio.available()) {
    radio.read(rx_data, buffer_size);
    flag = 1;
  }
  if (flag){
    Serial.print("Receiver count:\t");
    Serial.println(rx_counter);
    rx_counter++;
    print();
    Serial.println("Received Succesfully\n");
  }
}


void print() {
  for (i = 0; i < 7; i++) {
    Serial.println(rx_data[i]);
  }
  flag = 0;
}

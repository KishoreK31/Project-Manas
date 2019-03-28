/*
 <Important links>
      *https://github.com/nRF24/RF24
          Note that this is different from maniacbug's RF24 library which not actively developed anymore.
      *https://www.instructables.com/id/Electric-Wheelchair-Controller/
          This code is partially derived from the above example which is similar to our desired purpose - controlling a bot
*/

#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio(7, 8); //Set up nRF24L01 on CE pin and CSN pin respectively

const uint64_t pipe = 0x0ABCDEF; //Address for communication between master and slave
uint16_t data[7]; //Array to store the data
const uint16_t buffer_size = sizeof(data); //Size of the payload for the RF
int i, flag;
int tx_counter = 0; //Counts the number of transmission


void read();//Ideally, this function should read from another source/device
void setup() {

  Serial.begin(115200);

  //*****Radio settings****// [Should match slave's]
  radio.begin();
  radio.setChannel(2);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_MIN);//Power issues may arise when RF24_PA_MAX is used   
  radio.openWritingPipe(pipe);  //Pipe address to write the data
  radio.stopListening();        //Starts the module as transmitter


  //Default values range from 100 to 700. Ideally, should be replaced with values which are read
  for (i = 0; i < 7; i++) {
    data[i] = 100 + (100 * i);
  }
  flag = 0;
  Serial.println("Enter 7 values");
}

void loop() {
 
  read();

  if (flag) {
    bool tx_ok = radio.write(data, buffer_size);
    tx_counter++;
    Serial.print("Transmission count:\t");
    Serial.println(tx_counter);
    print();
    if (tx_ok) {
      Serial.println("Transmitted Successfully");
      Serial.println("\nEnter Next set of 7 numbers");
    }
    else Serial.println("Transmission failed");
    
  }
}

void print() {
  for (i = 0; i < 7; i++) {
    Serial.println(data[i]);
  }
  flag = 0;
}

void read() {
  while (Serial.available()) {
    for (i = 0; i < 7; i++) {
      data[i] = Serial.parseInt();      
    }
    
    flag = 1;
  }
}


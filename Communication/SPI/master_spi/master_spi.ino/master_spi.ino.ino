
#include "SPI.h"
void recvWithEndMarker();
void showNewData();
const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data

boolean newData = false;
void setup (void)
{

  digitalWrite(SS, HIGH);  // ensure SS stays high for now

  // Put SCK, MOSI, SS pins into output mode
  // also put SCK, MOSI into LOW state, and SS into HIGH state.
  // Then put SPI hardware into Master mode and turn SPI on
  Serial.begin(9600);
  Serial.println("Enter a string");
  SPI.begin ();
  
  // Slow down the master a bit
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
}  // end of setup


void loop()
{
  int i = 0;
  char c;
  char *p;
  recvWithEndMarker();
  showNewData();
  
  
  // enable Slave Select
  digitalWrite(SS, LOW);    
  
  // send test string
  for (p = receivedChars ; c = *p; p++)
    SPI.transfer (c);
    SPI.transfer ('\n');
  // disable Slave Select
  digitalWrite(SS, HIGH);
  delay(1000);
}  // end of loop

void recvWithEndMarker() {
 static byte ndx = 0;
 char endMarker = '\n';
 char rc;
 while (Serial.available() > 0 && newData == false) {
 rc = Serial.read();

 if (rc != endMarker) {
 receivedChars[ndx] = rc;
 ndx++;
 if (ndx >= numChars) {
 ndx = numChars - 1;
 }
 }
 else {
 receivedChars[ndx] = '\0';// terminate the string
 ndx = 0;
 newData = true;
 }
 }
}

void showNewData() {
 if (newData == true) {
 Serial.print("Entered data: ");
 Serial.println(receivedChars);

 newData = false;
 
 }
}




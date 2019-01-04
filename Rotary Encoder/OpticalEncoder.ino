boolean state;
boolean laststate;
int counter = 0;
int degree;

int a = 6;
int b = 7;

void setup() {
  Serial.begin(9600);
  pinMode(a,INPUT);
  pinMode(a,INPUT);

  laststate = digitalRead(a);

}

void loop() {
state = digitalRead(a);

if(state != laststate)
{
  if(state != digitalRead(b))  counter++;
  else counter--;

//Serial.println(counter);

/*utilizing the 2400 cpr of the optical encoder we can modify the code to 
tell us the angle to which we have rotated the encoder's shaft

calculation for this:
2400 cpr means 600 pulses per revolution. Means 360 degrees divided by 600.
So, 0.6 degrees per pulse. or 0.6 degrees = 1 pulse*/

degree = counter*0.6;
Serial.print("Degree:");
Serial.println(degree);

if(counter>600 || counter<-600)
  counter = 0;
}
}

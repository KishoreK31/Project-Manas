/*
 * TASK:
 Make a circuit and code your arduino such that there are 2 tactile switches, each with a predefined pwm value.
 Whenever any one button is pressed the motor should run at that pwm value, until the button is released. There is
 also an ultrasonic sensor on the same arduino that triggers an interrupt at a threshold distance that 
 stops the motor. When no button is pressed or the ultrasonic isnt active, the motor should idle at another pwm value.
 */
 //simple example  = https://www.allaboutcircuits.com/technical-articles/using-interrupts-on-arduino/
 
const int trig = 9;
const int echo = 10;
const int redswitch = 2;
const int yellowswitch = 3;
int redled = 6;
int greenled = 5;
volatile int pwm = 50;

volatile bool rs = LOW;      //RS - RED SWITCH
volatile bool ys = LOW;      //YS - YELLOWSWITCH
bool last_rs = LOW;
bool last_ys =  LOW;
volatile long distance=0;
long duration=0;
long temp=0;

void setup(){
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(redswitch,INPUT);
  pinMode(yellowswitch,INPUT);
  Serial.begin(9600);
 
  attachInterrupt(digitalPinToInterrupt(redswitch), red,CHANGE);
  attachInterrupt(digitalPinToInterrupt(yellowswitch), green,CHANGE);
      
  digitalWrite(greenled,LOW);
  digitalWrite(redled,LOW);
}

boolean debounce(boolean temp,int switchPin)
{
  boolean current = digitalRead(switchPin);
  if (temp != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop(){

  
  //Ultrasonic sensor's distance calculation
  digitalWrite(trig,LOW);
  delayMicroseconds(5);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duration = pulseIn(echo, HIGH);
  temp = duration * 0.0343 / 2;
  noInterrupts();
  distance = temp;
  rs = debounce(last_rs,redswitch);
  ys = debounce(last_ys,yellowswitch);
  last_rs = rs;
  last_ys = ys;
  if(distance>8)interrupts();
  
  Serial.println(distance);  
  analogWrite(redled,pwm);
  analogWrite(greenled,pwm);
}

void red(){
  
  if(rs == HIGH) pwm = 150;
  else pwm = 0;
  
  
}

void green(){
  
  if(ys == HIGH) pwm = 250;
  else pwm = 0;
  
}



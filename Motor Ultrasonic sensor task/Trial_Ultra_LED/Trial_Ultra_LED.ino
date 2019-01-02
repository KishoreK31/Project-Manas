/*
 * TASK:
 Make a circuit and code your arduino such that there are 2 tactile switches, each with a predefined pwm value.
 Whenever any one button is pressed the motor should run at that pwm value, until the button is released. There is
 also an ultrasonic sensor on the same arduino that triggers a cumpulsory interrupt at a threshold distance that 
 stops the motor. When no button is pressed or the ultrasonic isnt active, the motor should idle at another pwm value.
 */
const int trig = 9;
const int echo = 10;
const int redswitch = 2;
const int yellowswitch = 3;
int redled = 6;
int greenled = 5;
int pwm = 0;

bool rs = LOW;      //RS - RED SWITCH
bool ys = LOW;      //YS - YELLOWSWITCH
bool td = LOW;      //TD - THRESHOLD DISTANCE

long distance=0;
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

  constrain(pwm,0,255);
  
  digitalWrite(greenled,LOW);
  digitalWrite(redled,LOW);
}

void loop(){

  //Button code
  rs = digitalRead(redswitch);
  ys = digitalRead(yellowswitch);
  delay(10);
  
  //Ultrasonic sensor's distance calculation
  digitalWrite(trig,LOW);
  delayMicroseconds(5);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  distance = temp;
  duration = pulseIn(echo,HIGH);
  distance = duration * 0.0343 /2;
  if (distance<8)
    td = HIGH;
  else
    td = LOW;

  if(td == HIGH)
  {
    pwm = 0;
  }
  else if (td == LOW)
  {
    if(rs == HIGH)
      pwm = 150;
    else if(ys == HIGH)
      pwm = 255;
    else
      pwm = 50;
  }
  Serial.println(distance);
  analogWrite(redled,pwm);
  analogWrite(greenled,pwm);
}


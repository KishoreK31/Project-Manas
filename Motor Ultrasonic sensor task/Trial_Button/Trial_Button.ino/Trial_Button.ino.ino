int led = 13;
int swtt = 2;

void setup() {

  Serial.begin(9600);
  pinMode(swtt,INPUT);
  pinMode(led,OUTPUT);
  
}

void loop() {
  delay(5);
  Serial.println(digitalRead(swtt));
  if (digitalRead(swtt) == HIGH){
    digitalWrite(led,HIGH);
  }
  else  digitalWrite(led,LOW);

}

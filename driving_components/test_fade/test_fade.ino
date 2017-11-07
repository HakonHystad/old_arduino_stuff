int led = 9;

void setup(){
  pinMode(led,OUTPUT);
}
void loop(){
  int brightness = analogRead(A0)/4;
  analogWrite(led,brightness);
  delay(1);
}


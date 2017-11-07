int button = 2;
int led = 7;

void setup(){
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}

void loop(){
  int buttonState = digitalRead(button);
  if (buttonState == 1) {
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  delay(1000);
    
}


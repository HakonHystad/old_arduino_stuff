int startLed = 2;
int finishLed = 10;
int ledState = LOW;

void setup(){
  for(int led = startLed;led<=finishLed;led=led+2){
    pinMode(led,OUTPUT);
  }
}
void loop(){
  if(ledState == LOW){
    for(int led = startLed;led<=finishLed;led=led+2){
      digitalWrite(led,HIGH);
      delay(1000);
    }
    ledState = HIGH;
  }
  else{
    for(int led = finishLed;led>=startLed;led=led-2){
      digitalWrite(led,LOW);
      delay(1000);
    }
    ledState = LOW;
  }
}

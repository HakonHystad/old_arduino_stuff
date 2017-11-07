//fader leds i sekvens med hastighet avhengig av potensiometer

int ledPin[] = {3,5,6,9,10};
int ledSize = 5;
int ledState = LOW;
int rate = 2;

void setup(){
  for(int led = 0;led<ledSize;led++){
    pinMode(ledPin[led],OUTPUT);
  }
}
void loop(){
  if(ledState == LOW){
    for(int led = 0;led<ledSize;led++){
      for(int brightness = 0;brightness<255;brightness++){
        rate = analogRead(A0)/128;
        analogWrite(ledPin[led],brightness);
        ledState = HIGH;
        delay(rate);
      }
    }
  }
  else{
    for(int led = 4;led>=0;led=led-1){
      for(int brightness = 254;brightness>=0;brightness=brightness-1){
        rate = analogRead(A0)/128;
        analogWrite(ledPin[led],brightness);
        ledState = LOW;
        delay(rate);
      }
    }
  }
}

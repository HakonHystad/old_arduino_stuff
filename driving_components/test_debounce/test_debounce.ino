const int led = 8;
const int button = 2;

int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup(){
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(led,ledState);
}

void loop(){
  int reading = digitalRead(button);
  if (reading != lastButtonState){
    lastDebounceTime = millis();}
  if ( (millis() - lastDebounceTime)> debounceDelay){
    if (reading != buttonState){
      buttonState = reading;
      if (buttonState == HIGH){
        ledState = !ledState;
      }
    }
  }
  digitalWrite(led,ledState);
  lastButtonState = reading;
}


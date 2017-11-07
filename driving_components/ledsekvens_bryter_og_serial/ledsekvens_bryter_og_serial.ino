//porter
const int led[] = {3,5,6,9,10};
const int button = 13;
//lese bryter m/debounce
int buttonState = LOW;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
//switchcase led
int ledChoice;

void setup(){
  Serial.begin(9600);
  for(int ledNr = 0; ledNr<5; ledNr++){
    pinMode(led[ledNr],OUTPUT);
  }
  pinMode(button, INPUT);
}
 

void loop(){
  
  //serial control of leds
  boolean serialVerification = true;
  
  if(Serial.available()>0){
    char input = Serial.read();
  switch (input){
    case '1':
      ledChoice = 0;
      break;
    case '2':
      ledChoice = 1;
      break;
    case '3':
      ledChoice = 2;
      break;
    case '4':
      ledChoice = 3;
      break;
    case '5':
      ledChoice = 4;
      break;
    default:
      Serial.println("not valid input");
      serialVerification = false;
      break;
  }
    if(serialVerification == true){
      for(int brightness = 0;brightness<256;brightness++){
        analogWrite(led[ledChoice],brightness);
        delay(100);
      }
    }
  }
      
  
  
  
  
  
  
  
  //debounce
  int reading = digitalRead(button);
  if(reading != lastButtonState){//ny mulig buttonState, reset tid
    lastDebounceTime = millis();
  }
  if(millis() - lastDebounceTime > debounceDelay){//sjekk igjen etter delay
    if(reading != buttonState){
      buttonState = reading;
    }
    if(buttonState == HIGH){
      blinkLed(LOW,5);//ledState satt til permanent low midlertidig
      }
    }
  lastButtonState = reading;
  //debounce end
}
//blinking led function
void blinkLed(int ledState,int nrRepeat){
  Serial.println("blink");
  int count =0;
  int ledStateIn = ledState;
  while(count <nrRepeat*2){
    for(int ledNr = 0; ledNr<=4; ledNr++){
      if(ledState == LOW){
        digitalWrite(led[ledNr],HIGH);
        if(ledNr == 4){
          ledState = HIGH;
          Serial.println("on");
        }
      }
      else if(ledState == HIGH){
        digitalWrite(led[ledNr],LOW);
        if(ledNr == 4){
          ledState = LOW;
          Serial.println("off");
        }
      }
    }
    count++;
    delay(250);
  }
  if(ledState != ledStateIn){
    for(int ledNr = 0; ledNr<=4; ledNr++){
      digitalWrite(led[ledNr],ledStateIn);
    }
  }
}

  
  
    
  
  

/*teller antall trykk på bryter, gir tilbake i antall blink*/
const int button = 13;
const int ledPin = 3;

int count=0;//teller antall blink
//debounce
int lastButtonState = LOW;
long time = 0;
int interval = 50;//hvor lenge bryter må holdes nede

void setup(){
  pinMode(button,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop(){
  int reading = digitalRead(button);
  if(reading!=lastButtonState){
    time = millis();
  }
  if( (millis() - time )>interval){
    if(reading == HIGH){
      count++;
      blinkLed(count);
    }
  }
  lastButtonState = reading;
}
void blinkLed(int NrOfBlinks){
  int count = 0;
  while(count<NrOfBlinks){
    digitalWrite(ledPin,HIGH);
    count++;
    delay(100);
    digitalWrite(ledPin,LOW);
    delay(200);
  }
}

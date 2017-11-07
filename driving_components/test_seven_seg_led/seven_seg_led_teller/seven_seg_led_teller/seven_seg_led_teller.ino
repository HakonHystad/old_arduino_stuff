//--------------- definerer tall 0-9 i matrise 10*7 ---------------
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                               };
//andre variabler
const int button = 13;

int count=0;
//debounce
int lastButtonState = LOW;
long time = 0;
int interval = 50;//hvor lenge bryter må holdes nede

void setup(){
  for(int ledPin = 2;ledPin<=9;ledPin++){
    pinMode(ledPin,OUTPUT);
  }
  pinMode(button,INPUT);
}
void loop(){
  int reading = digitalRead(button);
  if(reading!=lastButtonState){
    time = millis();
  }
  if( (millis() - time )>interval){
    if(reading == HIGH){
      count++;
      if(count>9){
        for(int Blink = 0;Blink<3;Blink++){//blinker dot 3 ganger for reset av teller
          digitalWrite(9,HIGH);
          delay(500);
          digitalWrite(9,LOW);
          delay(500);
        }
        count = 0;
      }
      sevenSegWrite(count);
      delay(500);
    }
  }
  lastButtonState = reading;
  delay(10);
}

void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}



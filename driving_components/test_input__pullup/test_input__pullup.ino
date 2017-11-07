const int led = 8;
const int button = 2;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button,INPUT_PULLUP);
}

void loop(){
  int buttonVal = digitalRead(button);
  Serial.println(buttonVal);
  if (buttonVal == HIGH){
    digitalWrite(led,LOW);
  }
  else{
    digitalWrite(led,HIGH);
  }
}
    

const int ledPin = 9;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop(){
  if(Serial.available()){
    char in = Serial.read();
    if(in == 'H'){
      digitalWrite(ledPin,HIGH);
      Serial.println(in);
    }
    else if (in == 'L'){
      digitalWrite(ledPin,LOW);
      Serial.println(in);
    }
  }
}

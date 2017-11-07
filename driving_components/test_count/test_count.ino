const int button = 2;
const int led = 8;

int pushCount = 0;
int buttonState;
int lastButtonState = LOW;

void setup(){
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  buttonState = digitalRead(button);
  if (buttonState != lastButtonState){
    if(buttonState == HIGH){
      pushCount++;
      Serial.println("on \nnumber of button pushes: ");
      Serial.println(pushCount);
    }
    else{
      Serial.println("off");
    }
  }
  lastButtonState = buttonState;
  if ((pushCount % 4) == 0){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}

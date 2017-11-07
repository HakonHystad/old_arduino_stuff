/* counts down from press of a button

-------- pins - segments------
1--11 (a)
2--7 (b)
3--4 (c)
4--2 (d)
5--1 (e)
6--10 (f)
7--5 (g)
8--3 (dot)
9--12 (resistor) (d1)
10--9 (resistor) (d2)
11--8 (resistor) (d3)
12--6 (resistor) (d4)
*/

//------------ numbers to 7seg ----------- 
byte segNumbers[10][7] = {
  { 1,1,1,1,1,1,0 },  // = 0
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
//--------- other variables -------------
int button = 13;
int speaker = 0;//disconnect when uploading sketch

void setup(){
  pinMode(button,INPUT);
  pinMode(speaker,OUTPUT);
    for(int pin=1;pin<=12;pin++){
      pinMode(pin,OUTPUT);
    } 
    for(int pinSet=1;pinSet<=8;pinSet++){//set segments initially off
      digitalWrite(pinSet,LOW);
    } 
}
int time = 3000;

void loop(){
  
  if(time == 3000){
    buttonIn(1,time);//wait for button, show start time
  }

  int number = time;
  
  clearSegments;
  writeNumber(number/1000);
  writeDigit(1);
  delay(1);
  
  clearSegments;
  number = number%1000;// 3 last digits of number remain
  writeNumber(number/100);
  writeDigit(2);
  delay(1);
  
  clearSegments;
  number = number%100;//2 last digits remain
  writeNumber(number/10);
  writeDigit(3);
  delay(1);
  
  /*----------- 4th digit too fast
  clearSegments;
  number = number%10;//last digit remain
  writeNumber(number);
  writeDigit(4);
  delay(1);
  */
  time--;
  if(time<=0){
    tone(speaker,262,1000);//play tone of 262Hz (C4) for 1 second
    buttonIn(2,0);//wait for button, show "STOP"
    time = 3000;
  }
  

}

//------ waits for button input ---------
int buttonState;//debouncing
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;

void buttonIn(int startStop,int startnr){
  
  int keepLoop = HIGH;
  while(keepLoop == HIGH){
    if(startStop == 1){
      writeStartTime(startnr);
    }
    else if(startStop == 2){
      spellStop();
    }
    
      int reading = digitalRead(button);
      
      if (reading != lastButtonState){
        lastDebounceTime = millis();
      }
      if ( (millis() - lastDebounceTime)> debounceDelay){
        if (reading != buttonState){
            buttonState = reading;
            if (buttonState == HIGH){
              keepLoop = LOW;
            }
        }
      }
  lastButtonState = reading;
  delay(1);
  }
}

//------ clears panel --------
void clearSegments(){
  for(int pin=1;pin<=7;pin++){
      digitalWrite(pin,LOW);
    }
}

//-------- selects digit to write on (1-4) -----
void writeDigit(int digit){
    for(int pin = 9; pin <=12; ++pin){
      digitalWrite(pin, HIGH);
    }
    digitalWrite( (digit+8) , LOW);//uses pin 9-12
}

    

//-------- writes out number (0-9) --------
void writeNumber(int number){
  int pin = 1;
  for(int r = 0;r<7;r++){
    digitalWrite(pin,segNumbers[number][r]);
    pin++;
  }
}
//------- write time before start -----
void writeStartTime(int number){
  
  clearSegments;
  writeNumber(number/1000);
  writeDigit(1);
  delay(1);
  
  clearSegments;
  number = number%1000;// 3 last digits of number remain
  writeNumber(number/100);
  writeDigit(2);
  delay(1);
  
  clearSegments;
  number = number%100;//2 last digits remain
  writeNumber(number/10);
  writeDigit(3);
  delay(1);
  
  clearSegments;
  number = number%10;//last digit remain
  writeNumber(number);
  writeDigit(4);
  delay(1);
}

//------- write STOP -----------

void spellStop(){
  
  //spell S
  clearSegments();
  writeDigit(1);
  digitalWrite(1,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  delay(1);
  
  //spell T
  clearSegments();
  writeDigit(2);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  delay(1);
  
  //spell O
  clearSegments();
  writeDigit(3);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  delay(1);
  
  //spell P
  clearSegments();
  writeDigit(4);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  delay(1);
}





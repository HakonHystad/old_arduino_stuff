//http://playground.arduino.cc/Main/DS1302RTC
//clock  displayed by 4 7segment leds

/*
-------- pins - segments------
0--11 (a)
1--7 (b)
2--4 (c)
3--2 (d)
4--1 (e)
5--10 (f)
6--5 (g)
7--12 (resistor) (d1)
8--9 (resistor) (d2)
9--8 (resistor) (d3)
10--6 (resistor) (d4)

-------- pins - RTC module ---------------
11--CE (reset)
12--I/O (data)
13--CLK
5v--VCC
GND--GND
*/

#include <DS1302RTC.h>
#include <Time.h>

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
DS1302RTC RTC(11, 12, 13);// Set pins:  CE, IO,SCLK

void setup() {

  //Serial.begin(9600); brukt til debugging
  for(int pin=0;pin<=10;pin++){
      pinMode(pin,OUTPUT);
    } 
    for(int pinSet=1;pinSet<=8;pinSet++){//set segments initially off
      digitalWrite(pinSet,LOW);
    } 
   setSyncProvider(RTC.get); // the function to get the time from the RTC

}

void loop() {
  
  int hours = hour();
  int minutes = minute();
  //Serial.print(hours);-------debug---
  //Serial.print(minutes);
  //delay(1000);

  clearSegments;
  writeNumber( hours/10 );
  writeDigit(1);
  delay(1);

  clearSegments;
  writeNumber( hours%10 );
  writeDigit(2);
  delay(1);

  clearSegments;
  writeNumber( minutes/10 );
  writeDigit(3);
  delay(1);

  clearSegments;
  writeNumber( minutes%10 );
  writeDigit(4);
  delay(1);

}

//------ clears panel --------
void clearSegments(){
  for(int pin=0;pin<=6;pin++){
      digitalWrite(pin,LOW);
    }
}

//-------- selects digit to write on (1-4) -----
void writeDigit(int digit){
    for(int pin = 7; pin <=10; ++pin){
      digitalWrite(pin, HIGH);
    }
    digitalWrite( (digit+6) , LOW);//uses pin 7-10
}

    

//-------- writes out number (0-9) --------
void writeNumber(int number){
  int pin = 0;
  for(int r = 0;r<7;r++){
    digitalWrite(pin,segNumbers[number][r]);
    pin++;
  }
}

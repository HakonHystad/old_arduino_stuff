/* writes out to 4 digit 7 seg led

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

void setup(){
    for(int pin=1;pin<=12;pin++){
      pinMode(pin,OUTPUT);
    } 
    for(int pinSet=1;pinSet<=8;pinSet++){//set segments initially off
      digitalWrite(pinSet,LOW);
    } 
}
long count = 0;
void loop(){
  long number = count;
  
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
  
  count++;
  if(count>9999){
    count = 0;
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

  
  
  

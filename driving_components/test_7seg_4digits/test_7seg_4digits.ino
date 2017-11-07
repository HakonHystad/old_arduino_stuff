/*
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


void setup(){
  for(int pin=1;pin<=12;pin++){
    pinMode(pin,OUTPUT);
    digitalWrite(pin,HIGH);
  }
  //--------write on digit 1---------
  digitalWrite(9,LOW);
  //--------write the number 3-------
  digitalWrite(1, HIGH); // A
  digitalWrite(2, HIGH); // B
  digitalWrite(3, HIGH); // C
  digitalWrite(4, HIGH); // D
  digitalWrite(5, LOW); // E
  digitalWrite(6, LOW); // F
  digitalWrite(7, HIGH); // G
  digitalWrite(8, LOW);//DP 
}
void loop(){}

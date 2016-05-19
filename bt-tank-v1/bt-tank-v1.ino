#include <SoftwareSerial.h>

const int RxD = 2;
const int TxD = 3;
const int gLED = 10;
const int yLED = 9;
const int bLED = 8;
const int rLED = 7;
char stuff;

SoftwareSerial mySerial(RxD,TxD);

void setup() {
  // put your setup code here, to run once:
  pinMode(RxD, INPUT); 
  pinMode(TxD, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  pinMode(rLED, OUTPUT);
  
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
 
  if(mySerial.available()) 
  { 
     stuff = mySerial.read();
     Serial.print(stuff);
     if(stuff == 'A'){
      digitalWrite(gLED,HIGH);
     }
     if(stuff == 'B'){
      digitalWrite(yLED,HIGH);
     }
     if(stuff == 'C'){
      digitalWrite(bLED,HIGH);
     }
     if(stuff == 'D'){
      digitalWrite(rLED,HIGH);
     }
  }
  delay(1000);
  digitalWrite(gLED,LOW);
  digitalWrite(yLED,LOW);
  digitalWrite(bLED,LOW);
  digitalWrite(rLED,LOW);
}

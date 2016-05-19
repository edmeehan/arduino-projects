#include <SoftwareSerial.h>

//bluetooth I/O pins
const int RxD = 2;
const int TxD = 3;
SoftwareSerial bluetooth(RxD,TxD);

String btString = "";

//motor1 control - left motor
const int motorSpeedLFT = 11;
const int motorControlPin_1_LFT = 9;
const int motorControlPin_2_LFT = 10;
const int ledLFT = 12;
int motorValueLFT = 0;
boolean motorPowerLFT = false;

//motor2 control - right motor
//const int motorSpeedRGT = ;
//const int motorControlPin_1_RGT = ;
//const int motorControlPin_2_RGT = ;
//const int ledRGT = 13;
//int motorValueRGT = 0;
//int motorPowerRGT = 0;

//bluetooth serial


void setup() {
  // put your setup code here, to run once:
  pinMode(RxD, INPUT); 
  pinMode(TxD, OUTPUT);
  
  pinMode(motorSpeedLFT, OUTPUT);
  pinMode(motorControlPin_1_LFT, OUTPUT);
  pinMode(motorControlPin_2_LFT, OUTPUT);
  pinMode(ledLFT, OUTPUT);
  
  digitalWrite(motorSpeedLFT,LOW); //make sure motor off to start;
  digitalWrite(motorControlPin_1_LFT,LOW);
  digitalWrite(motorControlPin_2_LFT,HIGH);

//  pinMode(motorSpeedRGT, OUTPUT);
//  pinMode(motorControlPin_1_RGT, OUTPUT);
//  pinMode(motorControlPin_2_RGT, OUTPUT);
//  pinMode(ledRGT, OUTPUT);

  //bluetooth serial
  bluetooth.begin(9600);
  //usb serial
  Serial.begin(9600);
}

void loop() {
  while (bluetooth.available() > 0) 
  {
     char btReceived = bluetooth.read();
     btString += btReceived; //convert to string
     
     if(btReceived == '\n'){
       //do stuff with bt value
       
       if(btString == "A\n"){
        motorPowerLFT = !motorPowerLFT; // toggle value
        Serial.print(motorPowerLFT ? "On" : "Off");
       }
       
       if(btString.endsWith("mp\n")){
        //its motor power
//        motorValueLFT = btString.toInt();
        Serial.print(btString);
       }
       btString = ""; //reset to empty string
     }
  }

  if(motorPowerLFT){
//    Serial.println("Do Stuff");
    digitalWrite(ledLFT,HIGH);
    //TODO - get values from slider
    digitalWrite(motorSpeedLFT,HIGH);
  }else{
//    Serial.println("Dont Do Stuff");
    digitalWrite(ledLFT,LOW);
    analogWrite(motorSpeedLFT,0);
  }
}

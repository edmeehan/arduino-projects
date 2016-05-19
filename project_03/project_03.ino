const int sensorPin = A0;
const float baselineTemp = 80.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open a serial port

  for(int pinNumber = 2; pinNumber < 5; pinNumber++){ // loop the pins
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value: "); // print to serialport for monitoring
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");

  //convert voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;

  Serial.print(temperature);

  float fahr = (temperature * 1.8) + 32;

  Serial.print(", degrees F: ");
  
  Serial.println(fahr);

  if(fahr >= baselineTemp+2 && fahr < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(fahr >= baselineTemp+4 && fahr < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(fahr >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }else{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  delay(10);
}

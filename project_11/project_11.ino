#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(switchPin,INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0,1);
  lcd.print("Crystal Ball!");
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    if(switchState == LOW){
      reply = random(8);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The ball says:");
      lcd.setCursor(0,1);

      switch(reply){
        case 0:
        lcd.print("A");
        break;

        case 1:
        lcd.print("B");
        break;

        case 2:
        lcd.print("C");
        break;

        case 3:
        lcd.print("D");
        break;

        case 4:
        lcd.print("E");
        break;

        case 5:
        lcd.print("F");
        break;

        case 6:
        lcd.print("G");
        break;

        case 7:
        lcd.print("H");
        break;
      }
    }
  }

  prevSwitchState = switchState;
}

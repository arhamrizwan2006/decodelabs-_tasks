#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int soil=A0;
const int relay=8;
const int buzzer=7;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int dry=800;
int wet=500;

bool pump=false;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay,LOW);
  digitalWrite(buzzer,LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("IRRIGATION");
  lcd.setCursor(2,1);
  lcd.print("PUMP"); lcd.setCursor(9,1); lcd.print("SYSTEM");
  delay(3000);
}

void loop() {
  int moisture=analogRead(soil);
  unsigned long current_millis=millis();

  if(moisture>dry){
    pump=true;
    digitalWrite(relay,HIGH);
    digitalWrite(buzzer,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MOISTURE  = "); lcd.setCursor(12,0); lcd.print(moisture);
    lcd.setCursor(0,1);
    lcd.print("WATER PUMP= ON");
  }
  else if(moisture<wet){
    pump=false;
    digitalWrite(relay,LOW);
    digitalWrite(buzzer,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MOISTURE  = "); lcd.setCursor(12,0); lcd.print(moisture);
    lcd.setCursor(0,1);
    lcd.print("WATER PUMP=OFF");
  }

  delay(3000);
}
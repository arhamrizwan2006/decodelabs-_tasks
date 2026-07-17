#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int DHTPIN = 4;
const int DHTTYPE = DHT11;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float temp;
float hum;

unsigned long previousMillis = 0;
const unsigned long interval = 1000;

void setup() {

  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  delay(100);
  lcd.print("Environmental");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Monitor   System");
  delay(2000);
  
}

void loop(){
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    temp = dht.readTemperature();
    hum = dht.readHumidity();
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp: "); lcd.print(temp); lcd.print(" C  ");
    lcd.setCursor(0,1);
    lcd.print("Hum : "); lcd.print(hum); lcd.print(" %RH ");
  }
}
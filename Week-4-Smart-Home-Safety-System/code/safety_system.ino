#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pir = 2;
const int buzzer = 3;
const int relay = 4;
const int led = 5;
const int mq2 = A0;

volatile bool motionFlag = false;
volatile unsigned long previousMillisPIR = 0;
const unsigned long intervalPIR = 50;

const int gasThreshold = 400;
bool validating = false;
unsigned long previousMillisGas = 0;
const unsigned long intervalGas = 1500;

bool systemLocked = false;

unsigned long previousMillisLCD = 0;
const unsigned long intervalLCD = 300;

void motionISR() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisPIR > intervalPIR) {
    motionFlag = true;
    previousMillisPIR = currentMillis;
  }
}

void checkGasSensor() {
  int gasValue = analogRead(mq2);

  if (!systemLocked) {
    if (gasValue > gasThreshold) {
      if (!validating) {
        validating = true;
        previousMillisGas = millis();
      } else if (millis() - previousMillisGas >= intervalGas) {
        systemLocked = true;
        validating = false;
      }
    } else {
      validating = false;
    }
  }
}

void handleMotionControl() {
  if (motionFlag) {
    motionFlag = false;
    digitalWrite(relay, LOW);
  } else {
    digitalWrite(relay, HIGH);
  }
}

void handleLockedState() {
  digitalWrite(relay, HIGH);

  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
  delay(250);
}

void updateLCD() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisLCD < intervalLCD) return;
  previousMillisLCD = currentMillis;

  lcd.setCursor(0, 0);
  if (systemLocked) {
    lcd.print("** FAULT LOCK **");
  } else {
    lcd.print("Status: NORMAL  ");
  }

  lcd.setCursor(0, 1);
  int gasValue = analogRead(mq2);
  lcd.print("Gas:");
  lcd.print(gasValue);
  lcd.print(" ");
  lcd.print(systemLocked ? "LOCKED" : "OK    ");
}

void setup() {
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(led, OUTPUT);

  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Warming up...");
  delay(30000);
  lcd.clear();

  attachInterrupt(digitalPinToInterrupt(pir), motionISR, RISING);
}

void loop() {
  checkGasSensor();

  if (systemLocked) {
    handleLockedState();
  } else {
    handleMotionControl();
  }

  updateLCD();
}
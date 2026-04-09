#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int MQ2_PIN=34;
int BUZZER= 14;
int threshold = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {

  int gasValue = analogRead(MQ2_PIN);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.print(gasValue);

  if(gasValue > threshold) {
    digitalWrite(BUZZER, HIGH);
    tone(BUZZER,250,256);

    lcd.setCursor(0, 1);
    lcd.print("ALERT! Gas Leak");
  } 
  else {
    digitalWrite(BUZZER, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Safe Environment");
  }

  delay(1000);
}
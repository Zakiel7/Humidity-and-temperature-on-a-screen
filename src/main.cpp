#include <LiquidCrystal.h>
#include <DHT.h>

#define DHT_PIN 4

//                RS, E, D4, D5, D6, D7
LiquidCrystal lcd(5, 6, 7, 8, 9, 10);
DHT dht(DHT_PIN, DHT11);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("Demarrage...");
  delay(1500);
  lcd.clear();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  if (isnan(h) || isnan(t)) {
    lcd.print("Erreur capteur  ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else {
    lcd.print("Hum  : ");
    lcd.print(h, 0);
    lcd.print(" %    ");
    lcd.setCursor(0, 1);
    lcd.print("Temp : ");
    lcd.print(t, 0);
    lcd.print((char)223);  // symbole °
    lcd.print("C   ");
  }
  delay(2000);
}
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define POT_PIN 34
#define LED_RED 19
#define LED_GREEN 18
#define RELAY_PIN 23
#define SERVO_PIN 4

#define SERVO_FREQ 50
#define SERVO_RES 16

LiquidCrystal_I2C lcd(0x27, 16, 2);

uint32_t servoDuty(int angle) {
  return map(angle, 0, 180, 1638, 7864);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  ledcAttach(SERVO_PIN, SERVO_FREQ, SERVO_RES);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(RELAY_PIN, LOW);

  ledcWrite(SERVO_PIN, servoDuty(0));

  lcd.setCursor(0, 0);
  lcd.print("SMART IRRIGATION");
}

void loop() {
  int potValue = analogRead(POT_PIN);
  Serial.println(potValue);

  if (potValue > 2000) {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("PUMP: ON  ");
    ledcWrite(SERVO_PIN, servoDuty(90));
  } else {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    lcd.setCursor(0, 1);
    lcd.print("PUMP: OFF ");
    ledcWrite(SERVO_PIN, servoDuty(0));
  }

  delay(200);
}

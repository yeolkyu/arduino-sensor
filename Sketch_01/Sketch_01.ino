int LED_PIN = 12;
void setup () {
  pinMode(LED_PIN, OUTPUT);
}

void blinkLED(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  delay(duration);
}

void loop() {
  blinkLED(LED_PIN, 1000); // 1초 동안 LED 깜빡이기
}

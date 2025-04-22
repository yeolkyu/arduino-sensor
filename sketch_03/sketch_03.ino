int LED_PIN = 12;

void blinkLED(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  delay(duration);
}
void setup() {
  pinMode(LED_PIN, OUTPUT);
}
void loop() {
  for (int i = 0; i < 5; i++) { // 5번 반복
    blinkLED(LED_PIN, 500);
  }
  while(true);
}

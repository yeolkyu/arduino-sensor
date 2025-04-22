int buttonPin = 2;
int LED_PIN = 12;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // 버튼이 눌리면
    digitalWrite(LED_PIN, HIGH); // LED 켜기
  } else {
    digitalWrite(LED_PIN, LOW); // LED 끄기
  }
}

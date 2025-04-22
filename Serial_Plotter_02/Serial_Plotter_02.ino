int sensorPin = A0;
int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int lightLevel = analogRead(sensorPin);  // 조도 센서 값 읽기
  int ledState = lightLevel > 500 ? HIGH : LOW;  // 밝기에 따라 LED 제어

  digitalWrite(ledPin, ledState);  // LED ON/OFF

  Serial.print("Light Level: ");
  Serial.print(lightLevel);
  Serial.print("  LED State: ");
  Serial.println(ledState);  // LED 상태 출력 (0 또는 1)

  delay(100);
}

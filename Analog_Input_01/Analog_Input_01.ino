int sensorPin = A0;

void setup() {
  Serial.begin(9600);  // 시리얼 모니터 시작
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // A0 핀에서 값 읽기 (0~1023)
  Serial.println(sensorValue);  // 읽은 값을 시리얼 모니터에 출력
  delay(500);  // 0.5초 대기
}

int sensorPin = A0; // 가변저항 연결 핀

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  int sensorValue = analogRead(sensorPin); // 센서 값 읽기
  Serial.print("Sensor Value: ");  
  Serial.println(sensorValue); // 센서 값 출력
  delay(500); // 0.5초 대기
}

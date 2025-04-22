void setup() {
  Serial.begin(9600);  // 시리얼 통신 시작 (전송 속도: 9600bps)
}

void loop() {
  Serial.println("Hello, Arduino!"); // "Hello, Arduino!" 출력
  delay(1000);  // 1초 대기
}

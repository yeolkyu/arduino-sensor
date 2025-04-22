volatile int cnt = 0;

void setup() {
  Serial.begin(9600);  // 시리얼 통신 시작 (전송 속도: 9600bps)
}

void loop() {
  Serial.print("카운터 횟수: ");
  cnt++;
  Serial.println(cnt);
  delay(1000);  // 1초 대기
}

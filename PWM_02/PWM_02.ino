void setup() {
  pinMode(11, OUTPUT);  // 11번 핀(Blue LED)을 출력으로 설정
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(11, i);  // LED 밝기 증가
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(11, i);  // LED 밝기 감소
    delay(10);
  }
}

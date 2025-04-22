void setup() {
  pinMode(9, OUTPUT);  // 9번 핀을 출력 모드로 설정
}

void loop() {
  int lightValue = analogRead(A0);  // 조도 센서 값 읽기 (0~1023)
  int brightness = map(lightValue, 0, 1023, 0, 255);  // 0~1023 값을 0~255 범위로 변환
  analogWrite(9, 255-brightness);  // 9번 핀(PWM)으로 LED 밝기 조절
}

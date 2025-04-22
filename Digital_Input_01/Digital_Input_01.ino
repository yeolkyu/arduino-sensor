void setup() {
  pinMode(2, INPUT);  // 2번 핀을 입력 모드로 설정
  pinMode(13, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(2);  // 2번 핀의 값을 읽음
  if (buttonState == LOW) {
    digitalWrite(13, HIGH);  // 버튼이 눌리면 LED 켜기
  } else {
    digitalWrite(13, LOW);  // 버튼이 눌리지 않으면 LED 끄기
  }
}

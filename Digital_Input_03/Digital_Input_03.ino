void setup() {
  pinMode(2, INPUT);  // 2번 핀을 입력 모드로 설정
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);  // 2번 핀을 입력 모드로 설정
  pinMode(12, OUTPUT);
}

void loop() {
  int buttonState2 = digitalRead(2);  // 2번 핀의 값을 읽음
  if (buttonState2 == LOW) {
    digitalWrite(13, HIGH);  // 버튼이 눌리면 LED 켜기
  } else {
    digitalWrite(13, LOW);  // 버튼이 눌리지 않으면 LED 끄기
  }
  int buttonState3 = digitalRead(3);  // 2번 핀의 값을 읽음
  if (buttonState3 == LOW) {
    digitalWrite(12, HIGH);  // 버튼이 눌리면 LED 켜기
  } else {
    digitalWrite(12, LOW);  // 버튼이 눌리지 않으면 LED 끄기
  }
}

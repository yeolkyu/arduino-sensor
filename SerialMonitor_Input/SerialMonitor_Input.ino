void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
  Serial.println("문자 입력 후 엔터를 누르세요:");
}

void loop() {
  if (Serial.available() > 0) {  // 입력 값이 있는지 확인
    String input = Serial.readString();  // 입력 받은 문자열 저장
    Serial.print("입력한 값: ");
    Serial.print(input);  // 입력 값 출력
  }
}

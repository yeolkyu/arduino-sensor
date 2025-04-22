int pirPin = 7;   // PIR 센서 OUT 핀
int buzzerPin = 5; // 부저 핀

void setup() {
  pinMode(pirPin, INPUT);      // PIR 센서를 입력으로 설정
  pinMode(buzzerPin, OUTPUT);  // 부저를 출력으로 설정 (필요 없어도 설정 가능)
  Serial.begin(9600);          // 디버깅용 시리얼 통신 시작
}

void loop() {
  int motion = digitalRead(pirPin); // PIR 센서 상태 읽기
  if (motion == HIGH) {             // 모션이 감지되면
    Serial.println("Motion Detected! Buzzer ON");
    tone(buzzerPin, 1000);          // 1000Hz 주파수로 "삐" 소리 내기
    delay(500);                     // 0.5초 동안 소리
    noTone(buzzerPin);              // 소리 끄기
    delay(500);                     // 0.5초 대기
  } else {
    noTone(buzzerPin);              // 모션 없으면 소리 끄기
    Serial.println("No Motion");
  }
}

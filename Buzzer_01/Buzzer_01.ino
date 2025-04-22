// D5 핀을 부저 핀으로 정의
const int buzzerPin = 5;

void setup() {
  // D5 핀을 출력으로 설정
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // 1000Hz 주파수로 200ms(0.2초) 동안 소리 발생
  tone(buzzerPin, 1000);  // tone(pin, frequency)
  delay(200);            // 0.2초 대기
  
  // 부저 끄기
  noTone(buzzerPin);     // 소리 중지
  delay(1000);          // 1초 대기
}

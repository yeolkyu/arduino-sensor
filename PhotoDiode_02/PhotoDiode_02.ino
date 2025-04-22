// 전역 변수 선언
volatile int count = 0;              // 인터럽트에서 사용할 카운트 변수
volatile bool buzzerTriggered = false; // 부저 트리거 플래그
const int photodiodePin = 3;         // D3 핀에 포토 다이오드 연결
const int buzzerPin = 5;             // D5 핀에 부저 연결
volatile unsigned long lastInterruptTime = 0; // 마지막 인터럽트 시간
const unsigned long debounceDelay = 100;      // 디바운싱 시간 (100ms)

// 인터럽트 서비스 루틴 (ISR)
void signalDetected() {
  unsigned long currentTime = millis();
  if (currentTime - lastInterruptTime >= debounceDelay) {
    count++;                    // 카운트 증가
    buzzerTriggered = true;     // 부저 트리거 설정
    lastInterruptTime = currentTime;
  }
}

void setup() {
  pinMode(photodiodePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Photodiode Counter Started");
  attachInterrupt(digitalPinToInterrupt(photodiodePin), signalDetected, RISING);
}

void loop() {
  // 부저 제어
  if (buzzerTriggered) {
    // 시리얼 출력
    Serial.print("Count: ");
    Serial.println(count);
    tone(buzzerPin, 1000);    // 1000Hz로 부저 울림
    delay(100);               // 100ms 유지
    noTone(buzzerPin);        // 부저 끄기
    buzzerTriggered = false;  // 트리거 리셋
  }
  delay(500);
}

// 전역 변수 선언
volatile int pressCount = 0;         // 스위치 누른 횟수
const int switchPin = 2;             // D2 핀에 스위치 연결
const int ledPin = 7;                // D7 핀에 LED 연결
volatile unsigned long lastInterruptTime = 0; // 마지막 인터럽트 시간
const unsigned long debounceDelay = 200;      // 디바운싱 지연 시간 (ms)

// 인터럽트 서비스 루틴 (ISR)
void switchPressed() {
  unsigned long currentTime = millis(); // 현재 시간 기록
  
  // 마지막 인터럽트 이후 충분한 시간이 지났는지 확인 (디바운싱)
  if (currentTime - lastInterruptTime >= debounceDelay) {
    pressCount++;              // 누른 횟수 증가
    digitalWrite(ledPin, HIGH); // LED 켜기
    delay(200);                // 200ms 대기
    digitalWrite(ledPin, LOW);  // LED 끄기
    lastInterruptTime = currentTime; // 마지막 인터럽트 시간 업데이트
  }
}

void setup() {
  // 핀 설정
  pinMode(switchPin, INPUT);    // 스위치 핀을 입력으로 설정
  pinMode(ledPin, OUTPUT);      // LED 핀을 출력으로 설정
  digitalWrite(ledPin, LOW);    // 초기 LED 상태 끄기
  
  // 시리얼 통신 시작
  Serial.begin(9600);
  
  // 인터럽트 설정: 스위치 핀이 HIGH가 될 때 인터럽트 발생
  attachInterrupt(digitalPinToInterrupt(switchPin), switchPressed, RISING);
}

void loop() {
  // 시리얼 모니터에 누른 횟수 출력
  static int lastCount = -1;    // 이전 카운트 저장
  if (pressCount != lastCount) { // 카운트가 변경되었을 때만 출력
    Serial.print("스위치 누른 횟수: ");
    Serial.println(pressCount);
    lastCount = pressCount;
  }
}

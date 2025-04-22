// 핀 정의
const int PIR_PIN = 7;    // PIR 센서 입력 핀 (D7)
const int LED_PIN = 12;   // LED 출력 핀 (D12)

// 변수 선언
unsigned long previousTime = 0;  // 마지막 감지 시간
unsigned long ledOnTime = 5000;  // LED ON 지속 시간 (5초 = 5000ms)
bool ledState = false;          // LED 상태 추적

void setup() {
  // 핀 모드 설정
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  // 초기 LED 끄기
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // 현재 시간 저장
  unsigned long currentTime = millis();
  
  // PIR 센서가 HIGH일 때
  if (digitalRead(PIR_PIN) == HIGH) {
    if (!ledState) {  // LED가 꺼져있던 상태라면
      ledState = true;
      digitalWrite(LED_PIN, HIGH);
      previousTime = currentTime;
    } else {  // LED가 이미 켜져있는 상태라면
      previousTime = currentTime;  // 시간 갱신으로 ON 시간 연장
    }
  }
  
  // LED가 켜져 있고 5초가 경과했다면 끄기
  if (ledState && ((currentTime - previousTime) >= ledOnTime)) {
    ledState = false;
    digitalWrite(LED_PIN, LOW);
  }
}

// 핀 정의
const int photodiodePin = 7;  // D7 핀에 포토 다이오드 연결
const int buzzerPin = 5;      // D5 핀에 부저 연결

// 이전 상태를 저장하기 위한 변수
int lastState = LOW;          // 포토 다이오드의 이전 상태

void setup() {
  // 핀 모드 설정
  pinMode(photodiodePin, INPUT);  // 포토 다이오드 핀을 입력으로
  pinMode(buzzerPin, OUTPUT);     // 부저 핀을 출력으로
  
  // 시리얼 통신 시작 (디버깅용, 필요 없으면 제거 가능)
  Serial.begin(9600);
  Serial.println("Photodiode Buzzer Started");
}

void loop() {
  // 현재 포토 다이오드 상태 읽기
  int currentState = digitalRead(photodiodePin);

  // RISING 엣지 감지: 이전 상태가 LOW였고 현재 상태가 HIGH인 경우
  if (lastState == LOW && currentState == HIGH) {
    // 부저 짧게 울리기
    tone(buzzerPin, 1000);  // 1000Hz로 부저 울림
    delay(100);             // 100ms 동안 유지
    noTone(buzzerPin);      // 부저 끄기
    
    // 디버깅용 출력 (선택 사항)
    Serial.println("Rising edge detected!");
  }

  // 현재 상태를 이전 상태로 업데이트
  lastState = currentState;

  // 루프 지연 (디바운싱 및 CPU 부하 감소를 위해 약간의 지연 추가)
  delay(10);  // 10ms 대기
}

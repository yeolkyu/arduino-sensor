// 핀 정의
const int photoInterruptPin = 7;  // 포토 인터럽터를 디지털 핀 7에 연결
const int ledPin = 12;            // LED를 디지털 핀 12에 연결

// 변수 선언
volatile int count = 0;          // 물체 통과 횟수 (volatile: 인터럽트 사용 대비)
int lastState = HIGH;            // 이전 상태 저장

void setup() {
  // 핀 모드 설정
  pinMode(photoInterruptPin, INPUT);  // 포토 인터럽터 입력
  pinMode(ledPin, OUTPUT);           // LED 출력
  
  // 시리얼 통신 시작 (디버깅용)
  Serial.begin(9600);
  Serial.println("Counter Started");
}

void loop() {
  // 포토 인터럽터의 현재 상태 읽기
  int currentState = digitalRead(photoInterruptPin);
  
  // LED 제어: LOW일 때 켜짐
  if (currentState == LOW) {
    digitalWrite(ledPin, HIGH);  // LED ON
  } else {
    digitalWrite(ledPin, LOW);   // LED OFF
  }
  
  // 상태 변화 감지 (HIGH -> LOW 전환 시 카운트)
  if (lastState == HIGH && currentState == LOW) {
    count++;  // 물체 통과 횟수 증가
    Serial.print("Object Count: ");
    Serial.println(count);
    delay(50);  // 디바운싱을 위한 짧은 지연
  }
  
  // 현재 상태를 이전 상태로 저장
  lastState = currentState;
}

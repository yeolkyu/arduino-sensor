// 핀 번호 정의
const int trigPin = 7;      // 트리거 핀: D7
const int echoPin = 8;      // 에코 핀: D8
const int buzzerPin = 5;    // 부저 핀: D5

void setup() {
  // 핀 모드 설정
  pinMode(trigPin, OUTPUT);   // 트리거 핀 출력 설정
  pinMode(echoPin, INPUT);    // 에코 핀 입력 설정
  pinMode(buzzerPin, OUTPUT); // 부저 핀 출력 설정
}

void loop() {
  // 트리거 신호 보내기
  digitalWrite(trigPin, LOW);       // 트리거 초기화
  delayMicroseconds(2);             // 2마이크로초 대기
  digitalWrite(trigPin, HIGH);      // 트리거 HIGH
  delayMicroseconds(10);            // 10마이크로초 유지
  digitalWrite(trigPin, LOW);       // 트리거 LOW

  // 에코 신호로 시간 측정 (타임아웃 1초 설정)
  long duration = pulseIn(echoPin, HIGH, 1000000);

  // 거리 계산 (cm)
  int distance = duration / 58;

  // 거리가 0cm~100cm 사이인지 확인
  if (distance >= 0 && distance <= 100) {
    // 소리 지속 시간과 간격 계산
    int toneDuration = map(distance, 0, 100, 50, 500);  // tone 지속 시간 (ms)
    int delayTime = map(distance, 0, 100, 100, 1000);   // 다음 tone까지의 대기 시간 (ms)

    // 부저에서 1000Hz 소리 발생
    tone(buzzerPin, 1000, toneDuration);  // 주파수 1000Hz, 지속 시간 toneDuration ms

    // 다음 tone까지 대기
    delay(delayTime);
  } else {
    // 거리 범위 밖이면 부저 끄기
    noTone(buzzerPin);
  }
}

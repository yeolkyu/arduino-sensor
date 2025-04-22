// 핀 정의
const int trigPin = 7;  // HC-SR04의 Trig 핀 (D7)
const int echoPin = 8;  // HC-SR04의 Echo 핀 (D8)
const int buzzerPin = 5; // 부저가 연결된 핀 (D5)

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);
  
  // 핀 모드 설정
  pinMode(trigPin, OUTPUT);   // Trig 핀은 출력
  pinMode(echoPin, INPUT);    // Echo 핀은 입력
  pinMode(buzzerPin, OUTPUT); // 부저 핀은 출력
}

void loop() {
  // 초음파 센서로 거리 측정
  long duration;
  float distance;
  
  // Trig 핀으로 초음파 신호 전송
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);    // 안정화를 위해 2마이크로초 대기
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);   // 10마이크로초 동안 펄스 전송
  digitalWrite(trigPin, LOW);
  
  // Echo 핀에서 반사된 신호 수신
  duration = pulseIn(echoPin, HIGH); // 신호 지속 시간 측정 (마이크로초)
  
  // 거리 계산 (음속: 343m/s, 왕복 거리 고려)
  distance = (duration * 0.0343) / 2; // cm 단위로 변환
  
  // 시리얼 모니터에 거리 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 거리가 15cm 미만이면 부저 울림
  if (distance < 15.0) {
    tone(buzzerPin, 1000); // 1000Hz 주파수로 부저 울림 (삐~ 소리)
    Serial.println("Buzzer ON");
    delay(200);            // 0.2초 동안 소리 유지
    noTone(buzzerPin);     // 부저 끔
  } else {
    noTone(buzzerPin);     // 거리가 15cm 이상이면 부저 끔
    Serial.println("Buzzer OFF");
  }
  
  // 0.5초 대기
  delay(500);
}

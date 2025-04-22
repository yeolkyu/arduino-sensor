// 핀 정의
const int trigPin = 7;    // Trig 핀
const int echoPin = 8;   // Echo 핀

// 변수 선언
long duration;            // 펄스 지속 시간
float distance;           // 계산된 거리

void setup() {
  // 핀 모드 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // 시리얼 통신 시작 (9600 baud)
  Serial.begin(9600);
}

void loop() {
  // Trig 핀 초기화
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // 10us 동안 Trig 핀 HIGH
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Echo 핀에서 펄스 지속 시간 측정
  duration = pulseIn(echoPin, HIGH);
  
  // 거리 계산 (cm 단위)
  // 음속: 343m/s = 34,300cm/s
  // 거리 = (시간 × 속도) ÷ 2
  distance = duration * 0.034 / 2;
  
  // 결과 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // 100ms 대기
  delay(100);
}

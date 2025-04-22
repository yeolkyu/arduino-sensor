volatile int count = 0; // 인터럽트에서 사용할 카운터 변수 (volatile 사용)
int ledPin = 13;        // LED가 연결된 D13 핀
int photoPin = 2;       // 포토 인터럽터가 연결된 D2 핀

void setup() {
  pinMode(photoPin, INPUT);  // D2 핀을 입력으로 설정
  pinMode(ledPin, OUTPUT);   // D13 핀을 출력으로 설정
  Serial.begin(9600);        // 시리얼 통신 시작 (9600 baud)
  
  // D2에서 RISING (LOW → HIGH) 인터럽트 설정
  attachInterrupt(digitalPinToInterrupt(photoPin), detectObject, RISING);
}

void loop() {
  // 포토 인터럽터 출력이 HIGH일 때 LED 켜기
  if (digitalRead(photoPin) == HIGH) {
    digitalWrite(ledPin, HIGH); // LED 켜기
  } else {
    digitalWrite(ledPin, LOW);  // LED 끄기
  }
  
  // 카운터 값을 시리얼 모니터에 출력
  Serial.print("Count: ");
  Serial.println(count);
  delay(500); // 0.5초마다 출력 (너무 빠른 출력을 방지)
}

// 인터럽트 서비스 루틴: 물체 감지 시 카운터 증가
void detectObject() {
  count++; // 물체가 감지될 때마다 카운터 증가
}

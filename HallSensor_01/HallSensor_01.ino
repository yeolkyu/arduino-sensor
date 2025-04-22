// 핀 정의
const int analogPin = A3;  // 홀센서 아날로그 출력 핀
const int digitalPin = 8;  // 홀센서 디지털 출력 핀
const int ledPin = 12;      // LED 핀

void setup() {
  // 핀 모드 설정
  pinMode(digitalPin, INPUT);  // D8을 입력으로 설정
  pinMode(ledPin, OUTPUT);     // D7을 출력으로 설정
  
  // 시리얼 통신 시작
  Serial.begin(9600);          // baud rate 9600
}

void loop() {
  // 디지털 출력 처리
  int digitalValue = digitalRead(digitalPin);  // D8 값 읽기
  if (digitalValue == HIGH) {
    digitalWrite(ledPin, HIGH);  // LED 켜기
  } else {
    digitalWrite(ledPin, LOW);   // LED 끄기
  }
  
  // 아날로그 출력 처리
  int analogValue = analogRead(analogPin);  // A3 값 읽기
  Serial.println(analogValue);              // 시리얼 모니터에 출력
  
  // 0.5초 대기
  delay(500);
}

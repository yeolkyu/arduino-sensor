const int cdsPin = A1;    // CdS 셀 연결 핀 (아날로그 입력 A1)
const int ledPin = 13;    // LED 연결 핀 (디지털 핀 D13)
bool ledState = false;    // LED 상태를 추적하는 변수 (false: 꺼짐, true: 켜짐)

void setup() {
  pinMode(ledPin, OUTPUT);    // LED 핀을 출력으로 설정
  Serial.begin(9600);         // 시리얼 통신 시작 (디버깅용)
  digitalWrite(ledPin, LOW);  // 초기 상태: LED 꺼짐
}

void loop() {
  int cdsValue = analogRead(cdsPin);  // CdS 셀 값 읽기 (0-1023)
  Serial.println(cdsValue);          // 측정값 시리얼 모니터에 출력

  if (!ledState) {  // LED가 꺼져있는 경우
    if (cdsValue < 500) {           // CdS 값이 500 미만이면
      digitalWrite(ledPin, HIGH);   // LED 켜기
      ledState = true;              // 상태 업데이트
    }
  } else {  // LED가 켜져있는 경우
    if (cdsValue >= 600) {          // CdS 값이 600 이상이면
      digitalWrite(ledPin, LOW);    // LED 끄기
      ledState = false;             // 상태 업데이트
    }
  }

  delay(100);  // 0.1초 대기 (너무 빠른 변화를 방지)
}

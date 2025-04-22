// 핀 정의
const int switchPin = 2;    // 스위치가 연결된 D2
const int redPin = 9;       // RGB LED의 RED가 연결된 D9
const int greenPin = 10;    // RGB LED의 GREEN이 연결된 D10
const int bluePin = 11;     // RGB LED의 BLUE가 연결된 D11

// 변수 선언
int switchState = 0;        // 현재 스위치 상태
int lastSwitchState = HIGH; // 이전 스위치 상태
int colorState = 0;         // 색상 상태 (0: 꺼짐, 1: RED, 2: GREEN, 3: BLUE)

// 디바운싱 변수
unsigned long lastDebounceTime = 0;  // 마지막 디바운스 시간
unsigned long debounceDelay = 50;    // 디바운스 지연 시간 (밀리초)

void setup() {
  // 핀 모드 설정
  pinMode(switchPin, INPUT_PULLUP);  // 내부 풀업 저항 사용
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // 초기 LED 상태 (꺼짐)
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  Serial.begin(9600);
}

void loop() {
  // 스위치 상태 읽기
  int reading = digitalRead(switchPin);

  // 스위치 상태가 변경되었는지 확인
  if (reading != lastSwitchState) {
    // 디바운스 타이머 리셋
    lastDebounceTime = millis();
  }

  // 디바운스 지연 시간 확인
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // 실제 스위치 상태가 변경되었는지 확인
    if (reading != switchState) {
      switchState = reading;

      // 스위치가 눌렸을 때 (LOW 상태)
      if (switchState == LOW) {
        // 다음 색상 상태로 전환
        colorState = (colorState + 1) % 4;  // 0~3 순환
        
        // LED 제어
        switch (colorState) {
          case 0:  // 꺼짐
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
            Serial.println("LED OFF");
            break;
          case 1:  // RED
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
            Serial.println("RED");
            break;
          case 2:  // GREEN
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, LOW);
            Serial.println("GREEN");
            break;
          case 3:  // BLUE
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, HIGH);
            Serial.println("BLUE");
            break;
        }
      }
    }
  }

  // 현재 상태를 이전 상태로 저장
  lastSwitchState = reading;
}

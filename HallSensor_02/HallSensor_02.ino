// 홀센서가 자기장을 한번 감지할 때마다 RGB-LED의 색상이 RED, GREEN, BLUE 순서로 변한다
// 프로그램을 실행하고 자석을 한번씩 갖다 댈 때마다 LED 색상이 변하는지 확인한다

// 핀 정의
const int hallPin = 8;     // 홀센서가 연결된 D8
const int redPin = 9;      // RGB LED의 RED가 연결된 D9
const int greenPin = 10;   // RGB LED의 GREEN이 연결된 D10
const int bluePin = 11;    // RGB LED의 BLUE가 연결된 D11

// 변수 선언
int hallState = 0;         // 현재 홀센서 상태
int lastHallState = HIGH;  // 이전 홀센서 상태
int position = 0;          // 현재 위치 (0: 초기, 1: 첫 번째, 2: 두 번째, 3: 세 번째)

// 디바운싱 변수
unsigned long lastDebounceTime = 0;  // 마지막 디바운스 시간
unsigned long debounceDelay = 50;    // 디바운스 지연 시간 (밀리초)

void setup() {
  // 핀 모드 설정
  pinMode(hallPin, INPUT);   // 홀센서 입력 (내부 풀업 저항 사용 안 함)
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // 초기 LED 상태 (꺼짐)
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  // 시리얼 통신 시작 (디버깅용, 선택 사항)
  Serial.begin(9600);
}

void loop() {
  // 홀센서 상태 읽기
  int reading = digitalRead(hallPin);

  // 상태가 변경되었는지 확인
  if (reading != lastHallState) {
    // 디바운스 타이머 리셋
    lastDebounceTime = millis();
  }

  // 디바운스 지연 시간 확인
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // 실제 상태가 변경되었는지 확인
    if (reading != hallState) {
      hallState = reading;

      // 자석이 감지되었을 때 (LOW 상태)
      if (hallState == LOW) {
        // 위치 증가 (0~3 순환)
        position = (position + 1) % 4;
        
        // 위치에 따른 LED 제어
        switch (position) {
          case 0:  // 초기 상태 (꺼짐)
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
            Serial.println("Position: OFF");
            break;
          case 1:  // 첫 번째 자석 - RED
            digitalWrite(redPin, HIGH);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, LOW);
            Serial.println("Position: 1 - RED");
            break;
          case 2:  // 두 번째 자석 - GREEN
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, HIGH);
            digitalWrite(bluePin, LOW);
            Serial.println("Position: 2 - GREEN");
            break;
          case 3:  // 세 번째 자석 - BLUE
            digitalWrite(redPin, LOW);
            digitalWrite(greenPin, LOW);
            digitalWrite(bluePin, HIGH);
            Serial.println("Position: 3 - BLUE");
            break;
        }
      }
    }
  }

  // 현재 상태를 이전 상태로 저장
  lastHallState = reading;
}

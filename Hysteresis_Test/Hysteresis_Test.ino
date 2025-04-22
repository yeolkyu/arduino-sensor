// 핀 정의
#define PHOTO_PIN A0  // 포토 다이오드 연결 핀
#define LED_PIN 3     // LED 연결 핀

// 히스테리시스 임계값
const int HIGH_THRESHOLD = 600;  // 상한 (LED 켜짐)
const int LOW_THRESHOLD = 400;   // 하한 (LED 꺼짐)

// 상태 변수
bool ledState = false;  // LED 상태 추적 (false: 꺼짐, true: 켜짐)

void setup() {
  pinMode(LED_PIN, OUTPUT);    // LED 핀 출력 설정
  digitalWrite(LED_PIN, LOW);  // 초기 상태: 꺼짐
  Serial.begin(9600);          // 시리얼 통신 시작 (디버깅용)
}

void loop() {
  // 빛 세기 읽기
  int lightLevel = analogRead(PHOTO_PIN);

  // 히스테리시스 로직
  if (lightLevel > HIGH_THRESHOLD && !ledState) {
    // 빛 세기가 상한을 넘으면 LED 켜기
    ledState = true;
    digitalWrite(LED_PIN, HIGH);
  } 
  else if (lightLevel < LOW_THRESHOLD && ledState) {
    // 빛 세기가 하한 아래로 내려가면 LED 끄기
    ledState = false;
    digitalWrite(LED_PIN, LOW);
  }
  // 중간 범위(LOW_THRESHOLD ~ HIGH_THRESHOLD)에서는 상태 유지

  // 디버깅용 출력
  Serial.print("Light Level: ");
  Serial.print(lightLevel);
  Serial.print(" | LED State: ");
  Serial.println(ledState ? "ON" : "OFF");

  delay(100);  // 100ms 대기
}

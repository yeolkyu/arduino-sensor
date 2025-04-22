// RGB LED 핀 정의
const int redPin = 9;    // D9에 Red 연결
const int greenPin = 10; // D10에 Green 연결
const int bluePin = 11;  // D11에 Blue 연결

void setup() {
  // 핀을 출력 모드로 설정
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // 무지개 색상 순서대로 표시
  setColor(255, 0, 0);    // 빨강
  delay(1000);
  
  setColor(255, 127, 0);  // 주황
  delay(1000);
  
  setColor(255, 255, 0);  // 노랑
  delay(1000);
  
  setColor(0, 255, 0);    // 초록
  delay(1000);
  
  setColor(0, 0, 255);    // 파랑
  delay(1000);
  
  setColor(75, 0, 130);   // 남색
  delay(1000);
  
  setColor(148, 0, 211);  // 보라
  delay(1000);
}

// RGB 색상을 설정하는 함수
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

int counter = 0;  // 전역 변수

void setup() {
  Serial.begin(9600);
}

void loop() {
  counter++;  // 전역 변수 값 변경
  Serial.println(counter);
  delay(1000);
}

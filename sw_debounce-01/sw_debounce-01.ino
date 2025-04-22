unsigned long debounceDelay = 50;
int prevState = LOW; //이전 버튼 상태
int count = 0; //버튼 누름 횟수

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(2);
  if (reading != prevState) { //상태 변화 감지
    delay(debounceDelay); //디바운스 타임 동안 기다림
      if (reading == HIGH) {
        count++;
        Serial.print("Switch released: ");
        Serial.println(count);
      }
    else { Serial.println("Switch pressed");}
    prevState = reading; //상태 업데이트
  }
}

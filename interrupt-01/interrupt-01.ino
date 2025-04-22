volatile unsigned long last_interrupt_time = 0;
volatile int button_press_count = 0;
volatile bool flag = false;
volatile int debounceTime = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), handleButtonPress, FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  noInterrupts();//안전하게 버튼 누름횟수를 읽기 위해 인터럽트를 잠시 비활성화
  int count = button_press_count;
  interrupts();
  
  //누름이 발생했을 때만 출력
  if (flag) {
    Serial.println(count);
    flag = false; //누름 처리 완료
  }
}

void handleButtonPress() {
  unsigned long interrupt_time = millis(); //현재 시간(ms)

  // 이전 인터럽트 발생 시간과의 차이가 50ms 이상이면 실행
  if (interrupt_time - last_interrupt_time > debounceTime) {
    button_press_count++;
    flag = true; //누름 발생
    last_interrupt_time = millis();
    }
}

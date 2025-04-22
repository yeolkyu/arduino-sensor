int sensor = 7;
int LED = 12;
boolean PIRstatus = false;
boolean state_LED = false;
int interval = 4000; // after 4 sec, turn off LED
unsigned long previousMillis = 0; //PIR 센서로 인체 감지한 마지막 시간
unsigned long startMillis = 0; //LED가 켜진 시간

void setup() {
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, state_LED);
  
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  boolean state_current = digitalRead(sensor);

  //이전에 감지됮 않은 상태에서 감지 상태로 변한 경우
  if (state_current == true && PIRstatus == false) {
    previousMillis = millis(); // PIR 센서로 인체를 감지한 시간

    Serial.print("인체가 감지되었습니다 : ");
    if (state_LED) {
      Serial.println("LED ON 상태 유지");
    } else {
      Serial.println("LED OFF -> ON 상태 변경");
      startMillis = previousMillis; // LED가 켜진 시간
    }

    state_LED = true;
    digitalWrite(LED, state_LED);
  }
  PIRstatus = state_current;

  unsigned long currentMillis = millis();
  if (state_LED == true && currentMillis - previousMillis >= interval) {
    Serial.print("시간 경과(");
    Serial.print((currentMillis - startMillis ) / 1000.0, 1);
    Serial.println("초)로 LED를 끕니다");

    state_LED = false;
    digitalWrite(LED, state_LED);
  }
}

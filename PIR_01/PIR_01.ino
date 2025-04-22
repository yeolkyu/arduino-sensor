int LED = 12; //LED2 연결 핀
int sensor = 7; //PIR 센서
int value = 0;
int PIRstatus = LOW; //초기 상태

void setup() {
  pinMode (LED, OUTPUT);
  pinMode (sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = digitalRead(sensor); //센서 읽기

  if(value == HIGH){
    digitalWrite(LED, HIGH);
    if (PIRstatus == LOW) {
      Serial.println("Welcome!");
      PIRstatus = HIGH;
    }
  }
  if (value == LOW){
    digitalWrite(LED, LOW);
    if (PIRstatus == HIGH) {
      Serial.println("Good Bye~");
      PIRstatus = LOW;
    }
  }
}

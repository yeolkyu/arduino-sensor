const int cdsPin = A1; // CdS 센서 연결 핀
const int ledPin = 13; // LED 연결 핀

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int cdsValue = analogRead(cdsPin); // CdS 센서 값 읽기
  Serial.println(cdsValue);

  if (cdsValue < 500) { // 밝을 때
    digitalWrite(ledPin, HIGH); // LED 끄기
  } else { // 어두울 때
    digitalWrite(ledPin, LOW); // LED 켜기
  }

  delay(1000);
}

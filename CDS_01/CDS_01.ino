int VCC = 5;              // 아두이노의 공급 전압 (5V)
float R_divide = 10.0;    // 분압 회로에 사용된 고정 저항 값 (10kΩ)

void setup() {
  Serial.begin(9600);     // 시리얼 통신 시작 (9600 baud)
  while (!Serial);        // 시리얼 포트가 연결될 때까지 대기
}

void loop() {
  int reading = analogRead(A1);  // A1 핀에서 아날로그 값 읽기
  Serial.print("ADC: ");
  Serial.print(String(reading) + ",\t");  // ADC 값 출력

  float voltage = reading * VCC / 1023.0;  // 전압으로 변환
  Serial.print("전압: ");
  Serial.print(voltage, 2);  // 전압 출력 (소수점 2자리)
  Serial.print(",\t");

  float r_cds = R_divide * VCC / voltage - R_divide;  // CdS 저항 계산
  Serial.print("저항: ");
  Serial.print(r_cds, 2);  // 저항 출력 (소수점 2자리, 단위: kΩ)
  Serial.println("K");

  delay(1000);  // 1초 대기
}

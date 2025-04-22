// 핀 정의
const int lm35Pin = A2;  // LM35가 연결된 아날로그 핀

void setup() {
  // 시리얼 통신 시작 (baud rate: 9600)
  Serial.begin(9600);
}

void loop() {
  // 아날로그 값 읽기 (0-1023)
  int sensorValue = analogRead(lm35Pin);
  
  // 아날로그 값을 전압으로 변환 (5V 기준)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // 전압을 온도로 변환 (LM35: 10mV/°C)
  float temperatureC = voltage * 100;
  
  // 섭씨 온도 출력
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  // 화씨 온도 계산 및 출력 (선택사항)
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print("Temperature: ");
  Serial.print(temperatureF);
  Serial.println(" °F");
  
  // 1초 대기
  delay(1000);
}

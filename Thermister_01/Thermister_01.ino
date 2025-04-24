// 상수 정의
const int thermistorPin = A0;  // NTC-10K 써미스터가 연결된 아날로그 핀
const float R1 = 10000.0;        // 분압 저항 값 (10kΩ)
const float nominalResistance = 10000;  // 25°C에서의 써미스터 저항 값 (10kΩ)
const float nominalTemp = 25.0;         // 기준 온도 (25°C)
const float B = 3976;          // NTC-10K의 B 상수 (데이터시트 참조)

// Steinhart-Hart 방정식 계수 (일반적인 NTC-10K 기준, 필요 시 조정 가능)
const float A = 1.009249522e-3;  
const float B_coef = 2.378405444e-4;
const float C = 2.019202697e-7;

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop() {
  // 아날로그 값 읽기 (0-1023)
  int sensorValue = analogRead(thermistorPin);
  
  // 저항값 계산
  float voltage = sensorValue * (5.0 / 1023.0);  // 전압으로 변환 (5V 기준)
  //float resistance = R1 * (5.0 / voltage - 1.0); // 분압 회로를 이용한 써미스터 저항
  float resistance = voltage * R1 / (5.0 – voltage);
  
  // Steinhart-Hart 방정식을 이용한 온도 계산
  float steinhart;
  //steinhart = log(resistance / nominalResistance);  // ln(R/R0)
  steinhart = log(resistance);
  steinhart = 1.0 / (A + B_coef * steinhart + C * steinhart * steinhart * steinhart); // 1/T
  float temperatureK = steinhart;  // 켈빈 온도
  float temperatureC = temperatureK - 273.15;  // 섭씨로 변환
  
  // 시리얼 모니터에 출력
  Serial.print("Resistance: ");
  Serial.print(resistance);
  Serial.println(" Ω");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  // 1초 대기
  delay(1000);
}

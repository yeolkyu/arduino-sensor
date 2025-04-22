// 핀 정의
const int THERMISTOR_PIN = A0;  // NTC-10K 써미스터가 연결된 아날로그 핀

// NTC-10K 써미스터 상수
const float R1 = 10000;         // 분압 저항 값 (10kΩ)
const float NOMINAL_RES = 10000;// 25°C에서의 공칭 저항 값 (10kΩ)
const float NOMINAL_TEMP = 25;  // 공칭 온도 (°C)
const float BETA = 3976;        // 써미스터의 베타 값

void setup() {
  Serial.begin(9600);           // 시리얼 통신 시작
}

void loop() {
  // 아날로그 값 읽기 (0-1023)
  int sensorValue = analogRead(THERMISTOR_PIN);
  
  // 저항값 계산
  float resistance = R1 * (1023.0 / sensorValue - 1.0);
  
  // Steinhart-Hart 방정식을 사용한 온도 계산
  float temperature;
  temperature = resistance / NOMINAL_RES;           // (R/Ro)
  temperature = log(temperature);                   // ln(R/Ro)
  temperature = 1 / (temperature / BETA + 1.0 / (NOMINAL_TEMP + 273.15)); // 1/T = 1/To + (1/B)*ln(R/Ro)
  temperature = temperature - 273.15;              // 켈빈을 섭씨로 변환
  
  // 결과 출력
  Serial.print("Resistance: ");
  Serial.print(resistance);
  Serial.println(" ° Ω");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  delay(1000);  // 1초 대기
}

#include <DHT.h>

// 핀 정의
#define DHTPIN 4        // DHT11이 연결된 핀
#define DHTTYPE DHT11   // DHT11 센서 타입
const int IN1 = 7;      // L298N IN1 (모터 방향 제어)
const int IN2 = 8;      // L298N IN2 (모터 방향 제어)

// DHT 객체 생성
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);
  
  // L298N 핀 설정
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  // DHT11 초기화
  dht.begin();
  
  // 초기 모터 정지
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  // DHT11에서 온도 읽기
  float temperature = dht.readTemperature();
  
  // 온도값이 오류(NaN)인지 확인
  while (isnan(temperature)) {
    Serial.println("DHT11 읽기 오류, 재측정 중...");
    delay(2000);  // 2초 대기 후 재측정
    temperature = dht.readTemperature();
  }
  
  // 온도 출력
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  // 온도에 따라 모터 제어
  if (temperature >= 30.0) {
    // 모터 정방향 회전
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Serial.println("Motor ON (Forward)");
  } else {
    // 모터 정지
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    Serial.println("Motor OFF");
  }
  
  // 2초 대기 (DHT11의 샘플링 주기를 고려)
  delay(2000);
}

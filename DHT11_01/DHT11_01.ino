#include <DHT.h>

#define DHTPIN 4       // DHT11 데이터 핀을 아두이노 D4에 연결
#define DHTTYPE DHT11  // 사용 센서 종류: DHT11

DHT dht(DHTPIN, DHTTYPE);  // DHT11 센서 객체 생성

void setup() {
  Serial.begin(9600);
  dht.begin();  // DHT 센서 초기화
}

void loop() {
  float temperature = dht.readTemperature(); // 온도 읽기 (섭씨)
  float humidity = dht.readHumidity(); // 습도 읽기

  // 측정 실패 시 오류 메시지 출력
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("센서에서 데이터를 읽을 수 없습니다.");
    return;
  }

  Serial.print("온도: ");
  Serial.print(temperature);
  Serial.print(" °C, 습도: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);  // 2초마다 측정
}

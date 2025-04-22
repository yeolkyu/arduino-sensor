#include <DHT.h>

#define DHTPIN 2     // 데이터 핀 설정
#define DHTTYPE DHT11 // DHT 타입 지정

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Test!");
  dht.begin();
}

void loop() {
  delay(2000);  // 측정 간 2초 대기

  float humidity = dht.readHumidity();     // 습도 측정
  float temperature = dht.readTemperature(); // 온도 측정 (섭씨)

  // 측정 실패 시 체크
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // 결과 출력
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}

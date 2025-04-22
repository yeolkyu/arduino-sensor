#include <DHT.h>

#define DHTPIN 2     // 데이터 핀 설정
#define DHTTYPE DHT11 // DHT 타입 지정
#define LEDPIN 7

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  Serial.println("Temp Humidity");
  dht.begin(); //센서 초기화
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
  if (humidity >= 60) {
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
  //Serial.print("Humidity: ");
  Serial.print(humidity);
  //Serial.print("%\t");
  Serial.print(", ");
  //Serial.print("Temperature: ");
  Serial.println(temperature);
  //Serial.println("°C");
}

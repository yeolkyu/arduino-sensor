#include <DHT.h>

#define DHTPIN 4 // DHT11이 연결된 핀
#define DHTTYPE DHT11 // DHT11 센서 타입

// DHT 객체 생성
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("센서 오류");
    return;
  }

  Serial.print(temperature);
  Serial.print(",");
  Serial.println(humidity);

  delay(2000);
}

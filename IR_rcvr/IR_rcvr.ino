#include <IRremote.h> //version = 2.2.3

const int RECV_PIN = 6;
const int LED_PIN = 7; // 아두이노 내장 LED 핀
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  irrecv.enableIRIn();
  //Serial.println("IR Receiver Started...");
  Serial.println("적외선 수신 시작...");
}

void loop() {
  while (irrecv.decode(&results) == 0){
  }
    Serial.println(results.value, HEX);
    if (results.value == 0x20DF8877) { // 예: 리모컨의 "1" 버튼 코드 (실제 값은 다를 수 있음)
      digitalWrite(LED_PIN, HIGH);   // LED 켜기
      Serial.println("LED ON");
    } else if (results.value == 0x20DF48B7) { // 예: "2" 버튼 코드, 0x7F613A3B
      digitalWrite(LED_PIN, LOW);    // LED 끄기
      Serial.println("LED OFF");
    }
    irrecv.resume();
    delay(100);
}

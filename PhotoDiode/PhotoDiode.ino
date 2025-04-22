const byte interruptPin = 2;
volatile int pre_count, count;
unsigned long skip_milli_time = 100; 
unsigned long cur_time = 0;
unsigned long pre_time = 0;

void setup() {
  // put your setup code here, to run once:
  count = 0;
  pre_count = 0;
  attachInterrupt(digitalPinToInterrupt(interruptPin), CountServoRotation, FALLING);
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  // put your main code here, to run repeatedly:
}

void CountServoRotation() {
  cur_time = millis();
  if ( (cur_time - pre_time) > skip_milli_time ) {
    count++;
  }
  pre_time = millis();
  if (pre_count != count) {
      Serial.print("Rotation #:\t");
      Serial.println(count);
      pre_count = count;
  }
}

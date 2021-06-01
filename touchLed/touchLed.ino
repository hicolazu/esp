#define pinLed 2

void setup() {
  pinMode(T0, INPUT);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  if (touchRead(T0) < 20) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
  delay(100);
}

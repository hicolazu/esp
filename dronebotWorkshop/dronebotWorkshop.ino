#define pin 2

void setup() {
  pinMode(pin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  Serial.print("Hello");
  digitalWrite(pin, HIGH);

  delay(500);

  Serial.println(" world!");
  digitalWrite(pin, LOW);

  delay(500);
}

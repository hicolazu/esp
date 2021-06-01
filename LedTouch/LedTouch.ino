#define inputPin 17
#define ledPin 2

int value = 0;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  value = digitalRead(inputPin);
  digitalWrite(ledPin, value);
}

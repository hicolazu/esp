#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define pin 2

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("RedeESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(pin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    SerialBT.println(Serial.read());
  }
  if (SerialBT.available()) {
    char recebido = SerialBT.read();
    Serial.println(recebido);

    if (recebido == '1') {
      digitalWrite(pin, HIGH);
    } else if (recebido == '0') {
      digitalWrite(pin, LOW);
    } else {
      Serial.println("Bad command. Try '1' to HIGH or '0' to LOW");
    }
  }
  
  delay(20);
}

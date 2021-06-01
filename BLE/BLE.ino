#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID        "53e49566-1d70-4901-a758-102e81686112"
#define CHARACTERISTIC_UUID "33f64ca1-41c5-41a2-a94d-b582475b7404"
#define pin 2

BLEServer *pServer;
BLEService *pService;
BLECharacteristic *pCharacteristic;

void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("Esp32BluetoothRede");
  pServer = BLEDevice::createServer();
  pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue("Hello World says Esp32");
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  std::string value = pCharacteristic->getValue();
  Serial.print("The new characteristic value is: ");
  Serial.println(value.c_str());
  if (value.c_str()[0] == '1') {
    digitalWrite(pin, HIGH);
  } else if (value.c_str()[0] == '0') {
    digitalWrite(pin, LOW);
  }
  delay(2000);
}

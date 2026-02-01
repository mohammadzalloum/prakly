#include <SPI.h>
#include <MFRC522.h>

// توصيلك
static const uint8_t PIN_SS   = 32; // SDA / SS
static const uint8_t PIN_RST  = 27; // RST
static const uint8_t PIN_SCK  = 33; // SCK
static const uint8_t PIN_MISO = 26; // MISO
static const uint8_t PIN_MOSI = 25; // MOSI

MFRC522 rfid(PIN_SS, PIN_RST);

void printHexByte(byte b) {
  if (b < 0x10) Serial.print('0');
  Serial.print(b, HEX);
}

void setup() {
  Serial.begin(115200);
  delay(200);

  Serial.println("\n=== ESP32 DevKitC V4 + RC522 Test ===");
  Serial.println("SPI Pins:");
  Serial.printf("SCK=%d  MISO=%d  MOSI=%d  SS=%d  RST=%d\n",
                PIN_SCK, PIN_MISO, PIN_MOSI, PIN_SS, PIN_RST);

  SPI.begin(PIN_SCK, PIN_MISO, PIN_MOSI, PIN_SS);
  rfid.PCD_Init();

  // فحص القارئ
  byte v = rfid.PCD_ReadRegister(rfid.VersionReg);
  Serial.print("RC522 VersionReg: 0x");
  Serial.println(v, HEX);

  if (v == 0x00 || v == 0xFF) {
    Serial.println("⚠️ غالباً في مشكلة توصيل/تغذية/SS أو SPI.");
    Serial.println("تأكد: 3.3V فقط + GND مشترك + SDA(SS)=GPIO32.");
  } else {
    Serial.println("✅ القارئ ظاهر. قرّب الكرت/التاق...");
  }
}

void loop() {
  // انتظار كرت جديد
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial())   return;

  Serial.print("\nUID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    printHexByte(rfid.uid.uidByte[i]);
    if (i < rfid.uid.size - 1) Serial.print(':');
  }
  Serial.println();

  MFRC522::PICC_Type type = rfid.PICC_GetType(rfid.uid.sak);
  Serial.print("Type: ");
  Serial.println(rfid.PICC_GetTypeName(type));

  // تنظيف
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(300);
}


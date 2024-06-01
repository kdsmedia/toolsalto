#include <SPI.h>
#include <SSD1306Ascii.h>
#include <CC1101.h>

SSD1306Ascii oled;
CC1101 cc1101;

void setup() {
  oled.begin(&Adafruit128x32, 0x3C); // Inicializácia displeja SSD1306
  oled.setFont(System5x7);
  
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Initializing CC1101...");

  if (!cc1101.begin()) {
    Serial.println("CC1101 initialization failed!");
    while (1);
  }

  Serial.println("CC1101 initialized.");
  Serial.println("Starting jamming...");
  
  oled.clear();
  oled.println("HACK WORLD"); // Vypíše text "HACK WORLD" na displej
  
  cc1101.setCarrierFreq(433.92); // Nastavenie frekvencie na 433,92 MHz
}

void loop() {
  cc1101.transmit(0xAA); // Odoslanie jammingového signálu
  
  // Ďalšia logika kódu, ktorá sa vykonáva neustále v slučke loop()
}

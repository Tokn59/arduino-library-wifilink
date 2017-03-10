/*
 * This example check if the WiFi Link firmware is updated.
 *
 * Circuit:
 * - Arduino Primo or STAR OTTO, or (Uno WiFi Developer Edition with WiFiLink firmware running)
 *
 * Created 29 July 2015 by Cristian Maglie
 * This code is in the public domain.
 *
 * Modified and adapted 10 March 2017 by Sergio Tomasello
 *
 */
#include <SPI.h>
#include <WiFiLink.h>

void setup() {
  // Initialize serial
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Print a welcome message
  Serial.println("WiFi Link firmware check.");
  Serial.println();

  // Check for the presence of the shield
  // Serial.print("WiFi101 shield: ");
  // if (WiFi.status() == WL_NO_SHIELD) {
  //   Serial.println("NOT PRESENT");
  //   return; // don't continue
  // }
  // Serial.println("DETECTED");

  // Print firmware version on the shield
  String fv = WiFi.firmwareVersion();
  Serial.print("Firmware version installed: ");
  Serial.println(fv);

  // Print required firmware version
  Serial.print("Firmware version required : ");
  Serial.println(WIFI_FIRMWARE_REQUIRED);

  // Check if the required version is installed
  Serial.println();
  if (fv == WIFI_FIRMWARE_REQUIRED) {
    Serial.println("Check result: PASSED");
  } else {
    Serial.println("Check result: NOT PASSED");
    Serial.println(" - The firmware version installed do not match the");
    Serial.println("   version required by the library, you may experience");
    Serial.println("   issues or failures.");
  }
}

void loop() {
  // do nothing
}

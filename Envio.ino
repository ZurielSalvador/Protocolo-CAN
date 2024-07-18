// Copyright (c) Sandeep Mistry. All rights reserved.//5
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <CAN.h>
void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("CAN Sender");

 
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
}
void loop() {
  Serial.print("Sending packet ... ");

  CAN.beginPacket(0x12);
  CAN.write('Z');
  CAN.write('u');
  CAN.write('r');
  CAN.write('i');
  CAN.write('e');
  CAN.write('l');
  CAN.write('2');
  CAN.write('2');
  CAN.endPacket();

  Serial.println("done");

  delay(1000);

 
  Serial.print("Sending extended packet ... ");

  CAN.beginExtendedPacket(0xabcdef);
  CAN.write('V');
  CAN.write('i');
  CAN.write('c');
  CAN.write('t');
  CAN.write('o');
  CAN.write('r');
  CAN.write('r');
  CAN.write('r');
  CAN.endPacket();

  Serial.println("done");

  delay(1000);
}


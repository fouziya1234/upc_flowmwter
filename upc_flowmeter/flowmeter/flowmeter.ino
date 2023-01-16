#include <ModbusMaster.h>
#include "DataConversion.h"
#include <Wire.h>

ModbusMaster Master;
DataConversion DC;

uint16_t au16data[10];

unsigned long lt = 0;
String flowRate, totaliser;

void setup() {
  Serial2.begin(9600);
  Serial.begin(9600);
  Master.begin(1, Serial2);
  

  //  slave.start();

}
void loop() {
  if (millis() - lt > 3000) {
    readRS485();
    lt = millis();
  }
}

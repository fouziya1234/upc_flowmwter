void readRS485() {
  uint8_t j, result;
  uint16_t data[2];

  result = Master.readHoldingRegisters(12292, 10); //starting address=12292,lngth=10
  Serial.println("Reading UPC's flowmeter...");
  for (int i = 0; i < 10; i++) {
    Serial.print(Master.getResponseBuffer(i), HEX);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println("Reading UPC's totaliser...");
  for (int i = 0; i < 10; i++) {
    Serial.print(Master.getResponseBuffer(i), HEX);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println();

  if (result == Master.ku8MBSuccess)
  {
    for (j = 0; j < 10; j++)
    {
      data[j] = Master.getResponseBuffer(j);
      Serial.print(j); 
      Serial.print(":\t"); 
      Serial.println(data[j], HEX);
    }
    flowRate = DC.hexToFloat(data[3], data[4]);
    totaliser = hexToInt(data[0], data[1]) / 1000.0;
    Serial.print("Flow rate: ");
    Serial.println(flowRate);
    Serial.print("Totaliser: ");
    Serial.println(totaliser);
  }
}

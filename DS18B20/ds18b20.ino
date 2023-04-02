//from https://www.youtube.com/watch?v=lSVOtoMqtrI

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);
//from https://github.com/PaulStoffregen/OneWire
DallasTemperature sensors(&oneWire);
//from https://github.com/milesburton/Arduino-Temperature-Control-Library
int numberOfDevices;
DeviceAddress tempDeviceAddress;

/*
 * 
 */

void setup(void) {
  Serial.begin(9600);
  sensors.begin();
  numberOfDevices = sensors.getDeviceCount();
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices.");
  for(int i=0; i<numberOfDevices; i++) {
    if(sensors.getAddress(tempDeviceAddress, i)) {
      Serial.print("Device: ");
      Serial.print(i, DEC);
      Serial.print(" Address: ");
      printAddress(tempDeviceAddress);
      Serial.println();
    } else {
      Serial.print("Ghost at ");
      Serial.print(i, DEC);
      Serial.print(" but could not detect address. Check power and cabling");
    }
  }
}

/*
 * 
 */

void loop(void) { 
  sensors.requestTemperatures();
  for(int i=0; i<numberOfDevices; i++) {
    if(sensors.getAddress(tempDeviceAddress, i)){
      Serial.print("Sensor: ");
      Serial.print(i,DEC);
      float temp = sensors.getTempC(tempDeviceAddress);
      Serial.print(" Temp (C): "); //in celcius
      Serial.println(temp);
    }  
  }
  delay(2000); // Delay 2 sec
}

/*
 * 
 */

void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16) 
      Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
  } 
}

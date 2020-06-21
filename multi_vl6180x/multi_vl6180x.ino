#include <Wire.h>
#include "Adafruit_VL6180X.h"

// set the pins to shutdown
#define SHT_SNS1 14
#define SHT_SNS2 12

//Sensor I2C addresses
#define SNS1_ADDR 0x30
#define SNS2_ADDR 0x31

Adafruit_VL6180X vl = Adafruit_VL6180X();
Adafruit_VL6180X v2 = Adafruit_VL6180X();

/////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);

  // wait for serial port to open on native usb devices
  while (!Serial) {
    delay(1);
  }

  pinMode(SHT_SNS1, OUTPUT);
  pinMode(SHT_SNS2, OUTPUT);

  Serial.println("Shutdown pins inited...");

  digitalWrite(SHT_SNS1, LOW);
  digitalWrite(SHT_SNS2, LOW);

  Serial.println("Both in reset mode...(pins are low)");
  delay(50);
  
  digitalWrite(SHT_SNS1, HIGH);
  //Setup sensor 1
  if (! vl.begin(SNS1_ADDR)) {
    Serial.println("Failed to find sensor1");
    while (1);
  }
  Serial.println("Sensor1 found!");

  digitalWrite(SHT_SNS2, HIGH);
  //Setup sensor 2
  if (! v2.begin(SNS2_ADDR)) {
    Serial.println("Failed to find sensor2");
    while (1);
  }
  Serial.println("Sensor2 found!");
  
  Serial.println("Starting...");

}

/////////////////////////////////////////////////////////////////////////////////////

void checkSensorError(uint8_t status){
  if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
    Serial.println("System error");
  }
  else if (status == VL6180X_ERROR_ECEFAIL) {
    Serial.println("ECE failure");
  }
  else if (status == VL6180X_ERROR_NOCONVERGE) {
    Serial.println("No convergence");
  }
  else if (status == VL6180X_ERROR_RANGEIGNORE) {
    Serial.println("Ignoring range");
  }
  else if (status == VL6180X_ERROR_SNR) {
    Serial.println("Signal/Noise error");
  }
  else if (status == VL6180X_ERROR_RAWUFLOW) {
    Serial.println("Raw reading underflow");
  }
  else if (status == VL6180X_ERROR_RAWOFLOW) {
    Serial.println("Raw reading overflow");
  }
  else if (status == VL6180X_ERROR_RANGEUFLOW) {
    Serial.println("Range reading underflow");
  }
  else if (status == VL6180X_ERROR_RANGEOFLOW) {
    Serial.println("Range reading overflow");
  }
}

/////////////////////////////////////////////////////////////////////////////////////

void loop() {  
  Serial.println("SENSOR1 "); 

  float lux1 = vl.readLux(VL6180X_ALS_GAIN_5);
  uint8_t range1 = vl.readRange();
  uint8_t status1 = vl.readRangeStatus();
  
  if (status1 == VL6180X_ERROR_NONE) {
    Serial.print("Sensor1 Lux: "); Serial.println(lux1);
    Serial.print("Sensor1 Range: "); Serial.println(range1);
  }
  checkSensorError(status1);
  
  Serial.println("SENSOR2 "); 
  
  float lux2 = v2.readLux(VL6180X_ALS_GAIN_5);
  uint8_t range2 = v2.readRange();
  uint8_t status2 = v2.readRangeStatus();

  if (status2 == VL6180X_ERROR_NONE) {
    Serial.print("Sensor2 Lux: "); Serial.println(lux2);
    Serial.print("Sensor2 Range: "); Serial.println(range2);
  }

  checkSensorError(status2);

  Serial.println(" "); 
  Serial.println("---------------------------------------------------------------------------"); 
  Serial.println(" "); 
  
  delay(750);
}

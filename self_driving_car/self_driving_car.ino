#include <Wire.h>
#include "Adafruit_VL6180X.h"

// Assign addresses to all the sensors
#define FWD_LO_ADDRESS 0x30
#define FWD_HI_ADDRESS 0x31
#define RIGHT_ADDRESS 0x32
#define LEFT_ADDRESS 0x33
#define BACK_ADDRESS 0x34

Adafruit_VL6180X sens_fwd_lo = Adafruit_VL6180X();
Adafruit_VL6180X sens_fwd_hi = Adafruit_VL6180X();
Adafruit_VL6180X sens_right = Adafruit_VL6180X();
Adafruit_VL6180X sens_left = Adafruit_VL6180X();
Adafruit_VL6180X sens_back = Adafruit_VL6180X();

uint8_t range_fwd_lo;
uint8_t range_fwd_hi;
uint8_t range_right;
uint8_t range_left;
uint8_t range_back;


void setup_all_sensors() {
  
}

void setup_servo() {
  
}

void setup_motor_driver() {
  
}

void get_all_distance_data() {
  
}

void get_accelerometer_data() {
  
}

void drive_servo() {
  
}

void drive_motor() {
  
}

void calc_outputs() {
  
}



void setup() {
  setup_servo();
  setup_motor_driver();
  setup_all_sensors();
}

void loop() {
    //Get all distance data

    //Get accelerometer data

    //Calculate the servo and motor drives

    //Drive servo and motor
}

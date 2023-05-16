#include "gesture_sensor.h"

#include <Arduino.h>
#include <Wire.h>

#define GESTURE_ADDRESS (0x01)

GestureSensor::GestureSensor(const uint8_t device_i2c_address) : device_i2c_address_(device_i2c_address) {
  Wire.begin();
}

GestureSensor::Gesture GestureSensor::GetGesture() {
  Wire.beginTransmission(device_i2c_address_);
  Wire.write(GESTURE_ADDRESS);
  auto ret = Wire.endTransmission();
  if (ret != 0) {
    Serial.print("Error occurred when i2c writing: ");
    Serial.println(ret);
    return kGestureNone;
  }

  Wire.requestFrom(device_i2c_address_, (uint8_t)1);
  if (Wire.available()) {
    return static_cast<GestureSensor::Gesture>(Wire.read());
  }
  return kGestureNone;
}

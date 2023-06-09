/**
 * @example get_gesture.ino
 */
#include <Arduino.h>

// 包含gesture_recognizer.h头文件
#include "gesture_recognizer.h"

// 创建 GestureRecognizer 实例, I2C地址为0x39 (GestureRecognizer::kDeviceI2cAddressDefault)
GestureRecognizer gesture_sensor(GestureRecognizer::kDeviceI2cAddressDefault);

void setup() {
  Serial.begin(115200);
  Serial.println("setup");

  gesture_sensor.Setup();  // 初始化
}

void loop() {
  // 通过GetGesture获取手势
  const auto gesture = gesture_sensor.GetGesture();

  // 如果手势的不为空，则打印出手势的值
  if (gesture != GestureRecognizer::Gesture::kGestureNone) {
    Serial.print("gesture:");
    Serial.println(gesture);
  }
}
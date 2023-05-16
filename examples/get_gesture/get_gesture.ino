#include <Arduino.h>

// 包含gesture_sensor.h头文件
#include "gesture_sensor.h"

// 创建 GestureSensor 实例
GestureSensor gesture_sensor;

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
}

void loop() {
  // 通过GetGesture获取手势
  const auto gesture = gesture_sensor.GetGesture();

  // 如果捕获到手势（手势不为空）则打印出手势的值
  if (gesture != GestureSensor::Gesture::kGestureNone) {
    Serial.print("gesture:");
    Serial.println(gesture);
  }
}
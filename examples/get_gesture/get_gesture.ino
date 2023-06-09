/*
MIT License

Copyright (c) 2023 emakefun

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
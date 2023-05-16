# GestureSensor使用文档

`GestureSensor`是用于从**emakefun**的手势传感器获取识别到的手势值，具体可识别到的手势类型参考[手势类型](#手势类型)

## API使用文档

### 枚举定义

#### 扩展板默认I2C地址：0x39

|| 值 | 描述 |
| --- | --- | --- |
| GestureSensor::kDeviceI2cAddressDefault | 0x39 | 扩展板默认I2C地址 |

#### 手势类型

| GestureSensor::Gesture | 值 | 描述 |
| --- | --- | --- |
| GestureSensor::Gesture::kGestureNone | 0x00 | 无手势动作 |
| GestureSensor::Gesture::kGestureRightSwipe | 0x01 | 右移动作 |
| GestureSensor::Gesture::kGestureLeftSwipe | 0x02 | 左移动作 |
| GestureSensor::Gesture::kGestureBackwardSwipe | 0x03 | 后移动作 |
| GestureSensor::Gesture::kGestureForwardSwipe | 0x04 | 前移动作 |
| GestureSensor::Gesture::kGestureUpward | 0x05 | 上拉动作 |
| GestureSensor::Gesture::kGestureDownward | 0x06 | 下压动作 |
| GestureSensor::Gesture::kGestureOutOfRange | 0x07 | 离开感应区 |
| GestureSensor::Gesture::kGestureHover | 0x08 | 悬停 |

### 构造函数

#### `GestureSensor(const uint8_t device_i2c_address = kDeviceI2cAddressDefault)`

- 描述：构造函数。
- 参数：
  - `device_i2c_address`：扩展板I2C地址，默认值为0x39。
- 返回值：无。

### 获取手势相关函数

#### `Gesture GetGesture()`

- 描述：获取识别到的手势。
- 返回值：手势类型值，每个值对应不同手势类型，参考[手势类型](#手势类型)

## 示例程序

### 获取手势

```c++
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
```

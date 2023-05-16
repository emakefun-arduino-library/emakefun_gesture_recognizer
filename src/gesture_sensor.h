#pragma once

#include <stdint.h>

/**
 * @class GestureSensor
 * @brief 手势识别传感器主类
 */
class GestureSensor {
 public:
  /**
   * @brief 扩展板默认I2C地址
   */
  enum : uint8_t { kDeviceI2cAddressDefault = 0x39 };

  /**
   * @enum Gesture
   * @brief 手势类型
   */
  enum Gesture : uint8_t {
    kGestureNone = 0x0,           /**< 无手势动作*/
    kGestureRightSwipe = 0x01,    /**< 右移动作*/
    kGestureLeftSwipe = 0x02,     /**< 左移动作*/
    kGestureBackwardSwipe = 0x03, /**< 后移动作*/
    kGestureForwardSwipe = 0x04,  /**< 前移动作*/
    kGestureUpward = 0x05,        /**< 上拉动作*/
    kGestureDownward = 0x06,      /**< 下压动作*/
    kGestureOutOfRange = 0x07,    /**< 离开感应区*/
    kGestureHover = 0x08,         /**< 悬停*/
  };

  /**
   * @brief 构造函数
   * @param [in] device_i2c_address 扩展板I2C地址，默认值为0x39, @see kDeviceI2cAddressDefault
   */
  GestureSensor(const uint8_t device_i2c_address = kDeviceI2cAddressDefault);

  /**
   * @brief 获取识别到的手势
   * @return Gesture 手势类型， @see GestureSensor::Gesture
   */
  Gesture GetGesture();

 private:
  const uint8_t device_i2c_address_ = 0;
};
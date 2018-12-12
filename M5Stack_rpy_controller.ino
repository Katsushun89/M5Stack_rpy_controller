#include <M5Stack.h>
#include "utility/MPU9250.h"
#include "imu.h"

// Devices
MPU9250 IMU;

void setup()
{
  Serial.begin(115200);
  // Power ON Stabilizing...
  delay(500);
  M5.begin();
  Wire.begin();
  
  initIMU(&IMU);
  M5.Lcd.setBrightness(30);
  M5.Lcd.clear();
}

void loop() {
  if(calcIMU(&IMU)){
      {
        Serial.print("Yaw, Pitch, Roll: ");
        Serial.print(IMU.yaw, 2);
        Serial.print(", ");
        Serial.print(IMU.pitch, 2);
        Serial.print(", ");
        Serial.println(IMU.roll, 2);
      }
  }

  M5.update();
}


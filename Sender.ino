#include <Wire.h>
#include <WifiEspNow.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
Adafruit_MPU6050 mpu;

int xValue;
void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(A0, INPUT);
  WiFi.mode(WIFI_STA);
  WifiEspNow.begin(); 
  while (!Serial)
    delay(10); 

  Serial.println("Adafruit MPU6050 test!");
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");

}
void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  //Serial.println(a.acceleration.x);
  if(a.acceleration.y<-7) //back
  {
    sendESPNowData(1);
  }
  else if(a.acceleration.y>7) //front
  {
    sendESPNowData(2);
  }
  else if(a.acceleration.x<-7)//left
  {
    sendESPNowData(3);
  }
  else if(a.acceleration.x>7)//right
  {
    sendESPNowData(4);
  }
  else
  {
    sendESPNowData(8);
    Serial.println("im  here");
  }
  Serial.println(a.acceleration.y);
  delay(100);
}
void sendESPNowData(int data) {
  uint8_t recipientMac[] = {0x3C,0x61,0x05,0xE9,0x67,0x14};
  uint8_t sendData[sizeof(int)];
  memcpy(sendData, &data, sizeof(int));
  if (WifiEspNow.send(recipientMac, sendData, sizeof(sendData))) {
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Error sending data");
  }
}

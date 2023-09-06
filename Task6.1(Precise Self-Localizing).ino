#include <Wire.h>

const int MPU6050_ADDR = 0x68; // MPU6050 I2C address
const float gyroScale = 131.0; // Gyroscope sensitivity (LSB/°/s)
const float dt = 0.01;         // Sample time in seconds
const float alpha = 0.98;      // Complementary filter coefficient

int16_t accX, accY, accZ;
int16_t gyroX, gyroY, gyroZ;
float roll = 0.0;   // Roll angle (around x-axis)
float pitch = 0.0;  // Pitch angle (around y-axis)
float yaw = 0.0;    // Yaw angle (around z-axis)

void setup() {
  Wire.begin();
  Serial.begin(9600);
  MPU6050_Init();
}

void loop() {
  MPU6050_ReadData();
  // Calculate angles using complementary filter
  float accAngleX = atan2(accY, accZ) * 180.0 / M_PI;
  float accAngleY = atan2(-accX, accZ) * 180.0 / M_PI;

  gyroX /= gyroScale;
  gyroY /= gyroScale;
  gyroZ /= gyroScale;

  roll = alpha * (roll + gyroX * dt) + (1 - alpha) * accAngleX;
  pitch = alpha * (pitch + gyroY * dt) + (1 - alpha) * accAngleY;
  yaw += gyroZ * dt;

  Serial.print("Yaw Angle: ");
  Serial.println(yaw);
  delay(10); 
}

void MPU6050_Init() {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0x00);    // Set to 0 to wake up the MPU6050
  Wire.endTransmission();
}

void MPU6050_ReadData() {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B); // Starting register for accelerometer data
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDR, 12); // Read 12 bytes of data
  while(Wire.available()<12);
  accX = Wire.read() << 8 | Wire.read();
  accY = Wire.read() << 8 | Wire.read();
  accZ = Wire.read() << 8 | Wire.read();
  gyroX = Wire.read() << 8 | Wire.read();
  gyroY = Wire.read() << 8 | Wire.read();
  gyroZ = Wire.read() << 8 | Wire.read();
}

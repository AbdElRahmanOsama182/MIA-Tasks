# TASK6.1- Precise Self-Localizing

This Arduino code interfaces with the MPU6050 Inertial Measurement Unit (IMU) sensor to retrieve the yaw angle along the z-axis using a complementary filter. The complementary filter combines accelerometer and gyroscope data to obtain more accurate orientation measurements.

## Table of Contents

- [Overview](#overview)
- [Configuration](#configuration)
- [Question](#Question)

## Overview

The code reads data from the MPU6050 sensor and calculates the yaw angle (rotation around the z-axis) using a complementary filter. The filter fuses accelerometer and gyroscope data to obtain stable and drift-corrected orientation information.

Key features of the code:

- Retrieves accelerometer and gyroscope data from the MPU6050 sensor.
- Calculates yaw angle using a complementary filter.
- Provides yaw angle data via the Serial interface.

## Configuration

- **MPU6050_ADDR:** Set the I2C address of your MPU6050 sensor if it differs from the default (0x68).

- **gyroScale:** Adjust the gyroscope sensitivity value (LSB/°/s) as per your sensor's specifications.

- **dt:** Configure the sample time in seconds. The default value is 0.01 seconds (10 milliseconds).

- **alpha:** Set the complementary filter coefficient. The default value is 0.98, but you can adjust it to fine-tune the filter behavior.

- **MPU6050_Init():** Configure the power management settings of the MPU6050 sensor as needed.

## Question

If the Sensor is surrounded by a noisy environment, what type of filter could used and what is the recommended cutoff frequency depending on the sensor datasheet?
- We can use the Digital Low-Pass Filter(DLPF) with a DLPF configuration of `DLPF_CFG = 3` (`44 Hz` cutoff frequency for both accelerometer and gyroscope)
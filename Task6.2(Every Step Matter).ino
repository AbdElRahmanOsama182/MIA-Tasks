#include <Arduino.h>

const int encoderPinA = 2; // Encoder signal A pin
const int encoderPinB = 3; // Encoder signal B pin
long encoderCounts = 0; // Total encoder counts
float filteredCounts = 0; // Filtered encoder counts
float alpha; // LPF smoothing factor (adjust as needed)

// Encoder specifications
const int encoderPPR = 540; // Pulses per revolution
const float wheelCircumference = 0.4; // Wheel circumference in meters
const float maxSpeed = 0.5; // Maximum speed in m/s

void setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  // Calculate cutoff frequency (fc)
  float fc = maxSpeed / (encoderPPR * wheelCircumference);

  // Calculate LPF smoothing factor (alpha) based on fc (adjust as needed)
  alpha = 1.0 / (1.0 + 2.0 * PI * fc);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), updateEncoderB, CHANGE);
  Serial.begin(9600);
}

void loop() {
  // Print the filtered count
  Serial.print("Filtered Count: ");
  Serial.println(filteredCounts);
}

void updateEncoderA() {
  int stateA = digitalRead(encoderPinA);
  int stateB = digitalRead(encoderPinB);

  if (stateA != stateB) {
    encoderCounts++;
  } else {
    encoderCounts--;
  }

  // Apply LPF
  filteredCounts = alpha * encoderCounts + (1 - alpha) * filteredCounts;
}

void updateEncoderB() {
  int stateA = digitalRead(encoderPinA);
  int stateB = digitalRead(encoderPinB);

  if (stateA == stateB) {
    encoderCounts--;
  } else {
    encoderCounts++;
  }

  // Apply LPF
  filteredCounts = alpha * encoderCounts + (1 - alpha) * filteredCounts;
}

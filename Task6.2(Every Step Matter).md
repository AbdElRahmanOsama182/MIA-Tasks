# TASK6.2-Every Step Matter

This Arduino code interfaces with a rotary encoder to calculate the number of counts from the A and B signals. It also implements a Software Practical Low Pass Filter (LPF) with a proper cutoff frequency (fc) based on specifications.

## Specifications
- Encoder has 540 pulses per revolution
- Track has three wheels, with one motorized (the one with the encoder)
- Maximum speed of the system (WALL-E) is 0.5 m/s

## Code Description
- The code uses interrupts to handle changes in the encoder's A and B signals.
- It calculates the total encoder counts based on the A and B signals.
- The LPF cutoff frequency (fc) is calculated based on the specifications.
- LPF smoothing factor (alpha) is determined using the calculated fc.
- Filtered counts are continuously printed over serial communication.

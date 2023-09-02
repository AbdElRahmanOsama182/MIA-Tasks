#include <Wire.h>

#define b1 2
#define b2 3

void setup() {
    Wire.begin();  
    pinMode(b1, INPUT_PULLUP);
    pinMode(b2, INPUT_PULLUP);
}   

void loop() {
    int st1 = digitalRead(b1);
    int st2 = digitalRead(b2);
    Wire.beginTransmission(9);
    Wire.write(st1);
    Wire.write(st2);
    Wire.endTransmission();
    delay(1000);
}
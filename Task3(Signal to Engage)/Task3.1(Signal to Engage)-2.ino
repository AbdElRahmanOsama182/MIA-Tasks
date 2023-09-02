
#include <Wire.h>

#define led 9
int st1 = 0;
int st2 = 0;

void setup() {
    Wire.begin(9);
    Wire.onReceive(getSt);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int intensity = Intensity(st1, st2);
    if (intensity == 50)
        Serial.println("Vector focused");
    else if (intensity == 75)
        Serial.println("Vector distracted");
    else if (intensity == 100)
        Serial.println("Glitch");
    analogWrite(led, map(intensity, 0, 100, 0, 255));
    delay(1000);
}

void getSt(int byteCount) {
    if (byteCount >= 2) {
        st1 = Wire.read();
        st2 = Wire.read();
    }
}

int Intensity(int state1, int state2) {
    if (state1 == 0 && state2 == 0) 
        return 0;
    else if (state1 == 1 && state2 == 0) 
        return 50;
    else if (state1 == 0 && state2 == 1) 
        return 75;
    return 100;
}

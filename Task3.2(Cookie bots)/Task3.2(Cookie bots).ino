#include <NewPing.h>

NewPing sensors[4];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) 
    sensors[i] = NewPing(i+2, i+6, 800);
}
//Directions
//    1
//    ↑
// 2 ← → 0
//    ↓
//    3

void loop() {

  float x = 1.0*sensors[2].ping_cm()/100.0;
  float y = 1.0*sensors[3].ping_cm()/100.0;
  Serial.print("(");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.println(")");
  delay(1000);
}

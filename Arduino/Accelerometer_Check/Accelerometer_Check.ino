#include <Servo.h>
#include <MPU6050.h>
#include <Arduino.h>
Servo servol;


void setup() {
  // put your setup code here, to run once:

  
}

void loop() {
  // put your main code here, to run repeatedly:
  servol.attach(9);
  char c = 0;
      if(c=='z'){ return (_az/accel_sensitivity) - _az_bias;}
      else { return -999999; }
      servol.write ('z' + 180);
}

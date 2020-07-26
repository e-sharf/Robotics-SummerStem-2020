// This will demonstrate the motor_control library.
// There is code below for each type of driving - uncomment a line and then upload.

#include <motor_control.h>;

void setup() {
  // put your setup code here, to run once:
  motor_setup();
}

void loop() {
  //raw_motor_control (217, 200);
  //raw_motor_control (123, 100);
  //raw_motor_control (175 ,150);
  //raw_motor_control (104, 88 );
    // Minimum power needed to spin both wheels not touching the ground
  //raw_motor_control (114, 97);
    //Minimum power needed to spin both wheels while touching the ground
  //Requires more power when previously under-powered
}

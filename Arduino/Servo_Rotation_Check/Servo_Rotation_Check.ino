#include <Servo.h>
Servo servol;


void setup() {
  // put your setup code here, to run once:
  servol.attach(9);
  servol.write (90);
}

void loop() {
  // put your main code here, to run repeatedly:

}

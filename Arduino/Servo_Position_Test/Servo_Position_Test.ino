// This will demonstrate the MPU6050
# include <MPU6050.h>
# include <Servo.h>

Servo servol;

MPU6050 IMU(4,5);

float pos = 90;

void setup() {
  // Initializes and calibrates the MPU6050
  IMU.initialize();
  IMU.calibrate();
  
  Serial.begin(9600);

  servol.attach (9);

  
}

void loop() {
  // Gets new readings from sensor
  IMU.update();

  float a = (IMU.get_ang_vel('z'));
  pos = pos - (.01*a);
  servol.write(pos);
  Serial.println(pos);

  //Finding z axis angle velocity and adding "90" straight forward
  //servol.write(IMU.get_ang_vel('z')+90);
  //Serial.println(IMU.get_ang_vel('z')+90);
  
  //^^ Broken down into more parts
  //float a = (IMU.get_ang_vel('z'));
  //a = a + 90;
  //servol.write(a);
  //Serial.println(a);
  
}

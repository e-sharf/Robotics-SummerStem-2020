//libraries for motor control, accelerometer, and PID
#include <PID_v1.h>
#include <motor_control.h>
#include <MPU6050.h>
#include <State.h>

//setting variables for PID controller
double setpoint = 0;
double input;
double output;
double kp = 2;
double ki = 0;
double kd = 0;
double motor_bias = 26;
double setLinearState(150);
double setRotationState(0);

//setting up MPU6050
#define SDA 4
#define SCL 5
MPU6050 sensor (SDA, SCL);

//creates varibale which stores base power value for motors
int base_motor_speed =  150;
PID controller (&input, &output, &setpoint, kp, ki, kd, base_motor_speed, REVERSE);

void setup() {
  // put your setup code here, to run once:
  motor_setup();

  //PID parameters
  controller.SetOutputLimits(-100,100);
  controller.SetSampleTime(25);
  controller.SetMode(1);

  //begins accelorometer readings
  sensor.initialize();
  sensor.calibrate();
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.get_ang_vel('z');
  input = sensor.get_ang_vel('z');
  Serial.println("input: "); Serial.print(input );
  sensor.update();
  //compute PID value
  controller.Compute();
  //set values based on output and pring them
  raw_motor_control(base_motor_speed + output + motor_bias + getLinearState(), base_motor_speed - output);

  Serial.print("output: "); Serial.print(output);
}

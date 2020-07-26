#include <HC_SR04.h>
#include <PID_v1.h>
#include <motor_control.h>
#include <Servo.h>

#define TRIG_PIN 10
#define ECHO_PIN 2
#define ECHO_INT 0

HC_SR04 sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);
Servo actuator;

double setpoint = 25;
double input;
double output;
double kp = 150;
double ki = 100;
double kd = 12.5;
PID controller (&input, &output, &setpoint, kp, ki, kd, REVERSE);

void setup() {
  // put your setup code here, to run once:
  //setup motors
  motor_setup();

  //initialize distance sensor
  actuator.attach(9);
  actuator.write(90);

  sensor.begin();
  sensor.start();

  //Set PID parameters
  controller.SetOutputLimits(-150,150);
  controller.SetSampleTime(25);
  controller.SetMode(1);

  //begin serial for debuggin
  Serial.begin (9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //get distance value from sensor, update input to be distance value
  if(sensor.isFinished())
  {
    input = sensor.getRange();
    sensor.start(); //restart sensor
  }

  //compute PID controller once input has been updated
  controller.Compute();

  //set motor power based on output from PID controller
  raw_motor_control(output,1.1*output);

  Serial.print("output: "); Serial.print(output); Serial.print(" distance: "); Serial.println(input);
}

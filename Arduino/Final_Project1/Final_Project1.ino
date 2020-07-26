#include <HC_SR04.h>
#include <PID_v1.h>
#include <motor_control.h>
#include <Servo.h>

#define TRIG_PIN 10
#define ECHO_PIN 2
#define ECHO_INT 0
int trigger_distance = 50;

HC_SR04 sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);
Servo actuator;

double setpoint = 10;
double input;
double output;
double kp = 10;
double ki = .1;
double kd = .1;
PID controller(&input, &output, &setpoint, kp, ki, kd, REVERSE);
void setup() {
  // put your setup code here, to run once:
  motor_setup();

  actuator.attach(9);
  actuator.write(90);

  sensor.begin();
  sensor.start();

  controller.SetOutputLimits(-200,200);
  controller.SetSampleTime(25);
  controller.SetMode(1);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(sensor.isFinished())
  {
    input = sensor.getRange();
    if (input < trigger_distance)
    {
      raw_motor_control(0, 0);
      obstacle_avoidance();
    }
    sensor.start();
  }
  
  raw_motor_control (200*1.075, 200);

  Serial.print("output: "); Serial.print(output); Serial.print(" distance: "); Serial.println(input);
}

void obstacle_avoidance(){
  float left_distance;
  float right_distance;
  actuator.write(0);
  delay(250);
  sensor.start();
  while (!sensor.isFinished()){
    
  }
  right_distance = sensor.getRange();
  actuator.write(180);
  delay(500);
  sensor.start();
  while (!sensor.isFinished()){
    
  }
  left_distance = sensor.getRange();
  actuator.write(90);
  delay(200);
  if (left_distance>right_distance)
  {
    raw_motor_control (0, 0);
    diff_left(255);
  }
  else
  {
    raw_motor_control (0, 0);
    diff_right(255);
  }
  while (input < trigger_distance) {
    sensor.start();
    while (!sensor.isFinished()){
    
    }
    input = sensor.getRange();

  }
  return;
}

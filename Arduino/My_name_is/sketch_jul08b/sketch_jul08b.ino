int num;
void setup() {
  // put your setup code here, to run once:




}

void loop() {
  // put your main code here, to run repeatedly:

  int a = random (1,100);
  int b = random (1,100);
  int c = (a - b);
  Serial.println(c);
  delay (100);
}

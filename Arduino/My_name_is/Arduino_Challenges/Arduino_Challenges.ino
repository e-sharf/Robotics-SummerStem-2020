int num;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); //notes after the slashes

  for(int a=5; a >= 0; a--){
    for(int b=5; a<b; b--){
    Serial.print(1+b);
    }
    Serial.println("");


}

void loop() {
  // put your main code here, to run repeatedly:
}

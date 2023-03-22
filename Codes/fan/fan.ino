const int motorPin = 3;


const int tempPin = A0;
const float thresholdTemp = 30.0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  float tempVoltage = analogRead(tempPin) * 5.0/1023.0;
  float tempCelsius = (tempVoltage - 0.5) * 100.0;


  if (tempCelsius > thresholdTemp){
    digitalWrite(motorPin, HIGH);
    while (tempCelsius > thresholdTemp){
      delay(1000);

    tempVoltage = analogRead(tempPin) * 5.0/ 1023.0;
    tempCelsius = (tempVoltage - 0.5)  * 100.0;
    }
  }
  digitalWrite(motorPin, LOW);

  Serial.print("Temperature: ");
  Serial.println(tempCelsius);
  Serial.println("C");
}

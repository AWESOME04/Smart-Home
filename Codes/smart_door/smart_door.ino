// C++ code
//
#include <Servo.h>

float V_Distanced ;
int timed;
int speedd = 0.0034;

Servo servo_7;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  timed = pulseIn(echoPin, HIGH);
  Serial.println(timed);
  return timed;
}

void setup()
{
  servo_7.attach(7);
  Serial.begin(9600);
}

void loop()
{
  servo_7.write(0);
  delay(2000);
  V_Distanced = 0.034 * readUltrasonicDistance(9, 8);
  Serial.println(V_Distanced);
  
  
  if (V_Distanced < 10) {
    servo_7.write(180);
    delay(1000); // Wait for 2000 millisecond(s)
    servo_7.write(90);
  }
  ;
 
}

// Digital pin for each room
int pRoom1 = 12;
int pRoom2 = 8;
int pRoom3 = 7;
int pRoom4 = 4;
int pRoom5 = 2;
// Analog pin for each room
int sRoom1 = A0;
int sRoom2 = A1;
int sRoom3 = A2;
int sRoom4 = A3;
int sRoom5 = A4;

// The setup routine runs once when you press reset
void setup() {
  // Initialize the digital pins as output for each room
  pinMode(pRoom1, OUTPUT);
  pinMode(pRoom2, OUTPUT);
  pinMode(pRoom3, OUTPUT);
  pinMode(pRoom4, OUTPUT);
  pinMode(pRoom5, OUTPUT);
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

void isGas(int sensor, int pin){
  int sensorValue = analogRead(sensor);
  Serial.println(sensorValue, DEC);
  if (sensorValue > 500) {
    // Activate roomLight
    digitalWrite(pin, HIGH);
  }
  else {
    // Deactivate roomLight
    digitalWrite(pin, LOW);
  }
}

// The loop routine runs over and over again forever
void loop() {
  isGas(sRoom1, pRoom1);
  isGas(sRoom2, pRoom2);
  isGas(sRoom3, pRoom3);
  isGas(sRoom4, pRoom4);
  isGas(sRoom5, pRoom5);
}

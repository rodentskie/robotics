// digital pins
const int rightSensorPin = 8;
const int leftSensorPin = 7;
const int centerSensorPin = 4;

void setup() {
  pinMode(rightSensorPin, INPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(centerSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int rightSensorValue = digitalRead(rightSensorPin);
  int leftSensorValue = digitalRead(leftSensorPin);
  int centerSensorValue = digitalRead(centerSensorPin);

  if (rightSensorValue == 0 || leftSensorValue == 0 || centerSensorValue == 0) {
    Serial.println("No Object / Black Surface");
  } else {
    Serial.println("Object / White Surface Detected");
  }

  delay(100);  // Small delay for stability
}
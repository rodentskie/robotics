// digital pins
const int rightSensorPin = 10;
const int leftSensorPin = 11;

void setup() {
  pinMode(rightSensorPin, INPUT);
  pinMode(leftSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int rightSensorValue = digitalRead(rightSensorPin);
  int leftSensorValue = digitalRead(leftSensorPin);

  if (rightSensorValue == 0 || leftSensorValue == 0) {
    Serial.println("No Object / Black Surface");
  } else {
    Serial.println("Object / White Surface Detected");
  }

  delay(100);  // Small delay for stability
}
// digital pins
const int rightSensorPin = 8;
const int leftSensorPin = 7;
const int centerSensorPin = 6;

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

  Serial.print("left: ");
  Serial.println(leftSensorValue);

  Serial.print("right: ");
  Serial.println(rightSensorValue);

  Serial.print("center: ");
  Serial.println(centerSensorValue);

  if (rightSensorValue == 0 || leftSensorValue == 0 || centerSensorValue == 0) {
    Serial.println("No Object / Black Surface");
  } else {
    Serial.println("Object / White Surface Detected");
  }

  delay(100);  // Small delay for stability
}
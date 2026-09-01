const int rightSensorPin = 8;
const int leftSensorPin = 7;

void setup() {
  pinMode(rightSensorPin, INPUT);
  pinMode(leftSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int rightSensorValue = digitalRead(rightSensorPin);
  int leftSensorValue = digitalRead(leftSensorPin);
  Serial.print("left: ");
  Serial.println(leftSensorValue);

  Serial.print("right: ");
  Serial.println(rightSensorValue);


  if (rightSensorValue == 0 || leftSensorValue == 0) {
    Serial.println("No Object / Black Surface");

  } else {
    Serial.println("Object / White Surface Detected");
  }

  delay(100);  // Small delay for stability
}
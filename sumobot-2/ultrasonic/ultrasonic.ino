const int trigPin = 8;
const int echoPin = 4;
long duration = 0;
int distance = 0;

const int safeDistance = 15;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= safeDistance) {
    Serial.println("Abante!");
  } else {
    Serial.println("Just go!");
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}
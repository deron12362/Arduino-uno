//https://www.tinkercad.com/things/iTyJYS0YJv2-ping/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits

const int R_ledPin = 12;    // LED pin
const int Y_ledPin = 11;    // LED pin
const int B_ledPin = 10;    // LED pin
const int G_ledPin = 8;    // LED pin
const int pingPin = 7;    // Ultrasonic sensor pin
const int threshold = 10; // Distance threshold in cm

void setup() {
  Serial.begin(9600);       // Initialize Serial communication
  pinMode(R_ledPin, OUTPUT);  // Set LED pin as OUTPUT
  pinMode(Y_ledPin, OUTPUT);  // Set LED pin as OUTPUT
  pinMode(B_ledPin, OUTPUT);  // Set LED pin as OUTPUT
  pinMode(G_ledPin, OUTPUT);  // Set LED pin as OUTPUT
  
}

void loop() {
  long duration, cm, inch;

  // Send trigger pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10); // Trigger pulse should be 10µs
  digitalWrite(pingPin, LOW);

  // Read echo pulse
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // Convert duration to distance
  cm = microToCm(duration);
  inch = microToInch(duration);

  // LED logic based on threshold
  if (cm < threshold) {
    lighton();
  } else {
    digitalWrite(R_ledPin, LOW);  // Turn off LED
    digitalWrite(Y_ledPin, LOW);  // Turn off LED
    digitalWrite(B_ledPin, LOW);  // Turn off LED
    digitalWrite(G_ledPin, LOW);  // Turn off LED
  }

  // Print results
  Serial.print("Inches: ");
  Serial.print(inch);
  Serial.print(" Centimeters: ");
  Serial.println(cm);

  delay(100); // Short delay between readings
}

long microToCm(long micro) {
  return micro / 29 / 2; // Convert microseconds to centimeters
}

long microToInch(long micro) {
  return micro / 74 / 2; // Convert microseconds to inches
}
void lighton(){
	digitalWrite(R_ledPin, HIGH); // Turn on LED
    delay(100);
    digitalWrite(Y_ledPin, HIGH); // Turn on LED
    delay(100);
    digitalWrite(B_ledPin, HIGH); // Turn on LED
    delay(100);
    digitalWrite(G_ledPin, HIGH); // Turn on LED
    delay(100);
}

#define MQ2_PIN 34     // Define GPIO pin for MQ2 sensor
#define LED_PIN 2      // Define digital pin for LED (can be changed to any suitable pin)

const int SMOKE_THRESHOLD = 300; // Define threshold value for smoke detection

void setup() {
  Serial.begin(9600);   // Start serial communication at 9600 bps
  pinMode(LED_PIN, OUTPUT); // Set LED pin as output
}

void loop() {
  int sensorValue = analogRead(MQ2_PIN); // Read analog value from MQ2 sensor

  // Send the sensor value to the serial plotter
  Serial.println(sensorValue);

  // Check if smoke is detected
  if (sensorValue > SMOKE_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // Turn on LED
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED
  }

  delay(100); // Delay for 1 second before taking the next reading
}
//GND -> GND
//VCC -> 5V
//AO -> 34
//DO -> 2

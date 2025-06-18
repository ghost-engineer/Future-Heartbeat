const int moisturePin = A0;   // Soil moisture sensor pin
const int ledPin = 9;         // PWM pin for LED

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(moisturePin, INPUT);
}

void loop() {
  int moisture = analogRead(moisturePin); // 0 (dry) ... 1023 (wet)
  // Convert moisture to delay: the drier, the faster the pulse
  int minDelay = 10;   // minimum delay (maximum speed)
  int maxDelay = 30;   // maximum delay (minimum speed)
  int pulseDelay = map(moisture, 1023, 0, minDelay, maxDelay);

  // Smoothly increase brightness
  for (int brightness = 0; brightness <= 255; brightness += 5) {
    analogWrite(ledPin, brightness);
    delay(pulseDelay);
  }
  // Smoothly decrease brightness
  for (int brightness = 255; brightness >= 0; brightness -= 5) {
    analogWrite(ledPin, brightness);
    delay(pulseDelay);
  }
}

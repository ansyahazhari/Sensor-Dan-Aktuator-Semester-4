#include <Servo.h>

int tempPin = A0;
int tempValue = 0;

Servo myServo;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  pinMode (13, OUTPUT);
}

void loop() {
  tempValue = analogRead(tempPin);
  float voltage = (tempValue / 1023.0) * 5000.0;
  float temperatureC = voltage / 10.0;
  Serial.print("Suhu: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  if (temperatureC > 50) {
    myServo.write(90);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(10);
  } else {
    myServo.write(0);
    digitalWrite(13, LOW);
  }

  delay(200);
}

#include <Servo.h>
#include <SoftwareSerial.h>

// Define Bluetooth module pins (adjust based on your connection)
// #define rxPin   19
// #define txPin   18

#define rxPin   0
#define txPin   1

// Define servo motor control pin
#define servoPin    9
// Minimum and maximum valid angles for MG996R servo (adjust if needed)
#define minAngle    0
#define maxAngle    180

// Create a Servo object
Servo myservo;
SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  // Initialize serial communication with Bluetooth module (baud rate may vary)
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Serial Start.");
  bluetooth.println("Serial Start.");

  // Attach the servo to the pin and set initial position (optional)
  myservo.attach(servoPin);
  myservo.write(180); // Set servo to center position (adjust as needed)

}

void loop() {
  // Check if data is available from Bluetooth
  if (bluetooth.available()) {
    // Read the received data as an integer
    int received_data = bluetooth.read() - '0';
    // bluetooth.println(received_data);
    // Serial.println(received_data);

    if (received_data == 0) {
      myservo.write(0);
      Serial.println("Close");
    } else if (received_data == 1) {
      myservo.write(180);
      Serial.println("Open");
    }
  }
}

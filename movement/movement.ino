// #include <HCSR04.h>

// Define the trigger and echo pin of the HC-SR04 sensor
// #define TRIGGER_PIN  9
// #define ECHO_PIN     10

// Create an instance of the HCSR04 class
// HCSR04 hcsr04(TRIGGER_PIN, ECHO_PIN);

#define ENR 2 //enable for right hbridges
#define ENL 3 //enable for left hbridges
#define IN1_right 21 //input 1 for right side
#define IN2_right 20 //input 2 for right side
#define IN1_left 18 //input 1 for left side
#define IN2_left 19 //input 2 for left side

// max distance to detect obstacles for ultrasonic sensor
#define MAX_DISTANCE 1 // Maximum distance (in cm) to detect obstacles
bool end = false;
bool firstObstacle = true; // Flag to track the first obstacle encounter

// trial and error
int turn_duration = 875;         // duration for turning (trial and error)
int turn_forward_duration = 2000; // duration for moving forward after turning (trial and error)

// one h_bridge for each side of the robot (left/right)

void setup()
{
    Serial.begin(9600);

    pinMode(IN1_right, OUTPUT);
    pinMode(IN2_right, OUTPUT);
    pinMode(IN1_left, OUTPUT);
    pinMode(IN2_left, OUTPUT);
    pinMode(ENR, OUTPUT);
    pinMode(ENL, OUTPUT);

}

void moveForward(int duration = 0, int speed = 128)
{
    // Move forward all the 4 motors
    analogWrite(ENR, speed);
    analogWrite(ENL, speed);

    digitalWrite(IN1_right, HIGH);
    digitalWrite(IN2_right, LOW);
    digitalWrite(IN1_left, HIGH);
    digitalWrite(IN2_left, LOW);

    if (duration > 0)
    { // stops the robot after the input delay
        delay(duration);
        stopMotors();
    }
}

void stopMotors()
{
    // Stop all the 4 motors
    digitalWrite(IN1_right, LOW);
    digitalWrite(IN2_right, LOW);
    digitalWrite(IN1_left, LOW);
    digitalWrite(IN2_left, LOW);
    
}

void turnRight(int duration, int speed = 128)
{
    analogWrite(ENR, speed);
    analogWrite(ENL, speed);
    digitalWrite(IN1_right, LOW);
    digitalWrite(IN2_right, HIGH);
    digitalWrite(IN1_left, HIGH);
    digitalWrite(IN2_left, LOW);


    delay(duration);
    stopMotors();
    // if (obstacleDetected())
    // {
    //     end = true;
    // } // if theres an obstacle after turning assume end is reached
}

void turnLeft(int duration, int speed = 128)
{
    analogWrite(ENR, speed);
    analogWrite(ENL, speed);
    digitalWrite(IN1_right, HIGH);
    digitalWrite(IN2_right, LOW);
    digitalWrite(IN1_left, LOW);
    digitalWrite(IN2_left, HIGH);

    delay(duration);
    stopMotors();

    // if (obstacleDetected())
    // {
    //     end = true;
    // } // if theres an obstacle after turning assume end is reached
}

// bool obstacleDetected()
// {
//     // Check if obstacle is detected using ultrasonic sensor
//     return sonar.ping_cm() < MAX_DISTANCE;
// }

void loop()
{
    int speed = 240;

    // move forward for 1 seconds
    moveForward(1000, speed);
    delay(1000);

    // turn right
    turnRight(turn_duration, speed);

    // stop the motors for 1 seconds
    delay(1000);

    // turn left
    turnLeft(turn_duration, speed);
    // stop the motors for 1 seconds
    delay(1000);
}

// void loop() {
//     // Get the distance in centimeters
//     float distance = hcsr04.distanceInCm();

//     // Print the distance to the Serial Monitor
//     Serial.print("Distance: ");
//     Serial.print(distance);
//     Serial.println(" cm");

//     delay(1000);
// }

// void loop()
// {
//     while (!end)
//     {

//         moveForward(); // Move forward until obstacle detected

//         //check after every 100ms if there is an obstacle
//         while (!obstacleDetected())
//         {
//             moveForward(100);
//         }

//         // Obstacle detected
//         if (firstObstacle)
//         {
//             // First obstacle encountered, turn right, move forward slightly, and turn right again
//             turnRight(turn_duration);
//             delay(1000);     // Delay to ensure robot stops before turning
//             moveForward(turn_forward_duration); // Move forward slightly - 50 can be adjusted while testing accordingly
//             turnRight(turn_duration);
//             delay(1000); // Delay to ensure robot stops before resuming normal movement
//             firstObstacle = false;
//         }
//         else if (!firstObstacle)
//         {
//             // Second obstacle encountered, turn left, move forward slightly, and turn left again
//             turnLeft(turn_duration);
//             delay(1000);
//             moveForward(turn_forward_duration);
//             turnLeft(turn_duration);
//             delay(1000);
//             firstObstacle = true;
//         }
//     }
// }

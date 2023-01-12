#include <Servo.h>

Servo myservo;  // create servo object to control the servo
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9
  pinMode(2, INPUT);  // sets the digital pin 2 as input for a moisture sensor
}

void loop() {
  int moisture = analogRead(2);  // read the value from the moisture sensor
  if (moisture < 700) {          // if the moisture level is low
    for (pos = 0; pos <= 180; pos += 1) {  // move servo to open valve
      myservo.write(pos);
      delay(15);
    }
    delay(3000);   // wait for 3 seconds to allow water to flow
    for (pos = 180; pos >= 0; pos -= 1) {  // move servo to close valve
      myservo.write(pos);
      delay(15);
    }
  }
  delay(60000);  // wait for 1 minute before checking moisture again
}

This code uses a moisture sensor connected to digital pin 2 to read the moisture level of the soil. If the moisture level is below a certain threshold (in this case, 700), the code uses a servo motor connected to digital pin 9 to open and close a valve to allow water to flow to the plant.

This is just an example and you may need to adjust the threshold and delay values based on the specific requirements of your project.

Additionally, for a more complete solution, you may want to consider adding a real-time clock, a LCD display and a button to set the watering intervals, and also add a flow sensor to check how much water is being dispensed.

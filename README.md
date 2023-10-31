#Arduino Link:
https://www.arduino.cc/en/donate/

# smart_street_light_system

Here are some short code examples that highlight the key functionalities of the implemented system:

1) Reading IR Sensor Inputs:

`x = digitalRead(ir);`

`y = digitalRead(ir1);`

`z = digitalRead(ir2);`

These lines of code read the state of the IR sensors and store the values in variables x, y, and z, respectively.

2) Turning On LED Segments:
   
`if (x == 0)
{
  // Check if LED segment 1 is already on
  if (!led1On) {
    led1On = true;  // Turn on LED segment 1
    previousMillis1 = currentMillis;  // Record start time
  }
}`


This code snippet checks if the IR sensor associated with LED segment 1 detects an object. If the segment is not already on (!led1On), it sets the flag led1On to true and records the current time in previousMillis1.

3) Turning Off LED Segments after Duration:
`if (led1On && (currentMillis - previousMillis1 >= interval)) {
  led1On = false;  // Turn off LED segment 1
}`

This code checks if LED segment 1 is currently on (led1On) and if the elapsed time since it was turned on is greater than or equal to the specified duration (interval). If so, it sets led1On to false, turning off the segment.

4) Controlling LED Segments:
`digitalWrite(led1, led1On);
digitalWrite(led2, led2On);
digitalWrite(led3, led3On);`

These lines of code update the state of the LED segments based on the flags (led1On, led2On, led3On). digitalWrite() is used to turn the LED segments on or off based on the flags' values.

These code examples demonstrate the core functionalities of reading sensor inputs, controlling the LED segments, and managing their on/off states based on object detection and time intervals.





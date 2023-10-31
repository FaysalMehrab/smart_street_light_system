//Declaring the pin numbers for IR sensor and LED lights
int ir = 2;
int led1 = 3; 
int ir1 = 4;
int led2 = 5;
int ir2 = 6; 
int led3 = 7;
//variables to store IR sensor return values 
int x; 
int y; 
int z; 
//unsigned long variables to store the time for when the LED lights are turned on
unsigned long previousMillis1 = 0; 
unsigned long previousMillis2 = 0; 
unsigned long previousMillis3 = 0; 

//variable to turn off the LED lights after 2000 milliseconds or 2 seconds
const unsigned long interval = 2000; 

//boolean value for checking whether LED lights are on or off
bool led1On = false;
bool led2On = false; 
bool led3On = false; 

void setup() 
{ 
 //The number 9600 is the baud rate in bits per second (bps). This means that the 
 //Arduino is ready to exchange messages with the Serial Monitor at a data rate of 9600 bits per second.
Serial.begin(9600); 
 //setting up IR sensor pinMode as INPUT and LED lights as INPUT
pinMode(ir, INPUT); 
pinMode(led1, OUTPUT); 
pinMode(ir1, INPUT); 
pinMode(led2, OUTPUT); 
pinMode(ir2, INPUT); 
pinMode(led3, OUTPUT);
 } 

//Starting the loop
void loop()
{ 
 //reading the return values from IR sensors("1" if nothing is detected and "0" if detect anything)
x = digitalRead(ir); 
y = digitalRead(ir1);
z = digitalRead(ir2);


unsigned long currentMillis = millis();  //millis() function for continuously counting


if (x == 0) // checking if the First IR sensor has detected something or not
{ 
  if (!led1On) //if detects something then it will check if the third light is already on or not
  { 
    led1On = true; //if lights are not on then the boolean value will be true and will return true to turn on the first LED light
    previousMillis1 = currentMillis; //the "previousMillis1" variable will store the time when the first LED light is turned on
  } 
} 

if (y == 0) // checking if the second IR sensor has detected something or not
{ 
  if (!led2On) //if detects something then it will check if the third light is already on or not
  { 
    led2On = true; //if lights are not on then the boolean value will be true and will return true to turn on the second LED light
    previousMillis2 = currentMillis;   //the "previousMillis2" variable will store the time when the second LED light is turned on
  }
} 
if (z == 0) // checking if the third IR sensor has detected something or not
{ 
  if (!led3On)  //if detects something then it will check if the third light is already on or not
  { 
    led3On = true;  //if lights are not on then the boolean value will be true and will return true to turn on the third LED light
   previousMillis3 = currentMillis;  //the "previousMillis3" variable will third the time when the second LED light is turned on
  } 
}
if (led1On && (currentMillis - previousMillis1 >= interval)) // checking if the first LED is on and "currentMillis - previousMillis1" is equal or greater than interval[2000 millisecond or 2second]
{ 
  led1On = false; // if the condition is true the boolean variable will return false to turn off the first LED light
} 
if (led2On && (currentMillis - previousMillis2 >= interval)) // checking if the second LED is on and "currentMillis - previousMillis1" is equal or greater than interval[2000 millisecond or 2second]
{
  led2On = false; // if the condition is true the boolean variable will return false to turn off the second LED light
} 
if (led3On && (currentMillis - previousMillis3 >= interval)) // checking if the third LED is on and "currentMillis - previousMillis1" is equal or greater than interval[2000 millisecond or 2second]
{ 
  led3On = false;  // if the condition is true the boolean variable will return false to turn off the third LED light 
} 
digitalWrite(led1, led1On);  //output based of led1[pin] and ledon[boolean]
digitalWrite(led2, led2On);  //output based of led1[pin] and ledon[boolean]
digitalWrite(led3, led3On);  //output based of led1[pin] and ledon[boolean]
}

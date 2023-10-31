int ir = 2;
int led1 = 3; 
int ir1 = 4;
int led2 = 5;
int ir2 = 6; 
int led3 = 7; 
int x; 
int y; 
int z; 

unsigned long previousMillis1 = 0; 
unsigned long previousMillis2 = 0; 
unsigned long previousMillis3 = 0; 

const unsigned long interval = 2000; 

bool led1On = false;
bool led2On = false; 
bool led3On = false; 

void setup() 
{ 
Serial.begin(9600); 
pinMode(ir, INPUT); 
pinMode(led1, OUTPUT); 
pinMode(ir1, INPUT); 
pinMode(led2, OUTPUT); 
pinMode(ir2, INPUT); 
pinMode(led3, OUTPUT);
 } 

void loop()
{ 
x = digitalRead(ir); 
y = digitalRead(ir1);
z = digitalRead(ir2);


unsigned long currentMillis = millis(); 

if (x == 0) 
{ 
  if (!led1On) 
  { 
    led1On = true; 
    previousMillis1 = currentMillis; 
  } 
} 
if (y == 0) 
{ 
  if (!led2On)
  { 
    led2On = true;
    previousMillis2 = currentMillis;
  }
} 
if (z == 0) 
{ 
  if (!led3On)
  { 
    led3On = true; 
   previousMillis3 = currentMillis; 
  } 
}
if (led1On && (currentMillis - previousMillis1 >= interval)) 
{ 
  led1On = false;
} 
if (led2On && (currentMillis - previousMillis2 >= interval))
{
  led2On = false; 
} 
if (led3On && (currentMillis - previousMillis3 >= interval))
{ 
  led3On = false; 
} 
digitalWrite(led1, led1On); 
digitalWrite(led2, led2On); 
digitalWrite(led3, led3On); 
}

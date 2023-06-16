


int ir = 7;
int led1 = 8;
int led2 = 6;
int x;
void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:

x = digitalRead(ir);
Serial.println(x);
delay(10);

if(x == 1)
{
  digitalWrite(8,LOW);
  digitalWrite(6, HIGH);
}

else 
{
  digitalWrite(8, HIGH);
  digitalWrite(6,LOW);
}
}
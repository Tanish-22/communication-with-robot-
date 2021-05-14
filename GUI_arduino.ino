
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
int order;
int sec = 1;

void setup()
{
  pinMode(in1, OUTPUT);  // Digital pin 08 set as output Pin
  pinMode(in2, OUTPUT);  // Digital pin 09 set as output Pin
  pinMode(in3, OUTPUT);  // Digital pin 10 set as output Pin
  pinMode(in4, OUTPUT);  // Digital pin 11 set as output Pin

  Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
    order = Serial.parseInt();
    if (order <= 10)
    {
      sec = order;
    }
  }

  if ( order == 13) // Forward
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(sec * 1000);
    order = 15;
  }
  else if (order == 14) // Backward
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(sec * 1000);
    order = 15;
  }


  else if (order == 15) //Stop
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(sec * 1000);
    order = 15;

  }


  else if (order == 11) //Left
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(sec * 1000);
    order = 15;
  }

  else if (order == 12) //Right
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(sec * 1000);
    order = 15;
  }

}

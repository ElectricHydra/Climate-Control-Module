const int tempPin = A3;
const int motorPin = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage * 100.0;

  int PWM;

  if (temperature < 27)
    PWM = 0;
  else if (temperature >= 40)
    PWM = 255;
  else
    PWM = (temperature - 27) * 255 / 13;

  analogWrite(motorPin, PWM);

  Serial.print("Temp: ");
  Serial.print(temperature, 1);
  Serial.print("C, PWM: ");
  Serial.println(PWM);

  delay(500);   // Wait 500 ms
}
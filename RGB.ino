int bluePin = 6;
int redPin = 9;
int greenPin = 5;
int counter = 0;//狀態切換


int R1 = 0;
int outputR1 = 0;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int G = 0;
int gO = 0;

void setup() {
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  sensorValue = analogRead(A1);
  // map it to the range of the analog out:
  if (sensorValue < 672) sensorValue = 672;
  if (sensorValue > 930) sensorValue = 930;
  outputValue = map(sensorValue, 672, 930, 0, 255);
  
  G = analogRead(A2);
  if (sensorValue < 672) sensorValue = 672;
  if (sensorValue > 930) sensorValue = 930;
  gO = map(G, 672, 930, 0, 255);


  R1 = analogRead(A0);
  outputR1 = map(R1, 0, 1023, 0, 255);
    analogWrite(greenPin,gO);
    analogWrite(redPin, outputValue);
    analogWrite(bluePin,outputR1);

}



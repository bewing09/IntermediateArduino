Ultrasonic sensor Pins:
  VCC:+ 5VDC
  Trig:Trigger(INPUT) - Pin11
  Echo:Echo(OUTPUT) - Pin 12
  GND:GND
  * /
  int trigpin = 11;
  int echopin = 12;
  long duration, cm, inches;
  void setup()
  {
    // Serial 
    Serial.begin(9600);
    pinMode(trigpin, OUTPUT);
    pinMode(echoPin, INPUT);
  }

  void loop()
  {
    digitalWrite(trigpin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = (duration/2) / 29.1; 
    inches = (duration/2) / 74; 
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(250);
  }

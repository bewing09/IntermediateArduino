//_0.ino

int led = 3;
int brightness = 0;
int fadeValue = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3, brightness);
  delay(50);               // wait for a second
  brightness = brightness + fadeValue;
  if (brightness >= 255 || brightness <=0){
  	  fadeValue = -fadeValue;
  }
Serial.println(brightness);
}
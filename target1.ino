#include <Servo.h>

Servo serX;
Servo serY;

// ok cool, so now you need to add some delta to the y, and make sure it never goes below 90? (or whatever it is supposed to be)

// ok, now test it out, make sure it works
// then, finalize the design, make it more stable, use better tape
// then, see if you can get something going with the audio (using gcc-phat to find the direction, do some research on wingbeat frequencies)
// then see if you can add that too

String tempModify;

int laserPin = 13;
int prevY = 40;
int prevX = 90;

float lastTime = 0;
float timeDelay = 2000;

void setup() {

  pinMode(laserPin, OUTPUT);  // Define the digital output interface pin 13 
  serX.attach(11);
  serY.attach(8);
  Serial.begin(9600);
  Serial.setTimeout(10);
  initServo();
}

void initServo(){
  serX.write(prevX);
  serY.write(prevY);
}

void loop() {
  if(digitalRead(laserPin) == HIGH){
      turnOffLaser();
  }
}

void turnOnLaser(){
    digitalWrite(laserPin, HIGH);
    lastTime = millis();
}

void turnOffLaser(){
  if((millis() - lastTime) > timeDelay){
    digitalWrite(laserPin, LOW);
  }  
}

void serialEvent() {
tempModify = Serial.readString();
int nextX = parseDataX(tempModify);
int nextY = parseDataY(tempModify);

turnOnLaser();

if(isValid(nextX)){
  serX.write(nextX);
}

if(isValid(nextY)){ // && abs(prevY - nextY) > 10){
  serY.write(nextY);
  prevY = nextY;
}

delay(15);    
}

bool isValid(int deg){
  return deg > 0 && deg < 180;
}

int parseDataX(String data){
  data.remove(data.indexOf(","));
  return data.toInt();
}

int parseDataY(String data){
  data.remove(0,data.indexOf(",") + 1);
  return data.toInt();  
}

#include <CapacitiveSensor.h>
#include <Servo.h>

CapacitiveSensor wave = CapacitiveSensor(4, 6);  // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

//servo vars
Servo myServo;
int pos = 0;
boolean open = false;
boolean readSensor =true;
long sensorStart=0;
long sensorInterval=5000;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
    if (readSensor=true){
  long magic = wave.capacitiveSensor(30);
  if (magic > 500) {
    sensorStart=millis();
    readSensor=false;
    open = !open;
  }
    }
    if (millis()-sensorStart>sensorInterval){
      readSensor=true;
    }
  if (open == true) {
    pos = 110;
    myServo.write(pos);
  }
  if (open == false) {
    pos = 0;
    myServo.write(pos);
  }
  //Serial.println(magic);  // print sensor output 1
}

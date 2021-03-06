  // INOLINE 1
  // INOLINE 1 // INOLINE 2
  // INOLINE 1 // INOLINE 2 // INOLINE 3
  // INOLINE 1 // INOLINE 2 // INOLINE 3 // INOLINE 4
#include <Stepper.h> // INOLINE  // INOLINE 3 // INOLINE 4 // INOLINE 5
 // INOLINE 4 // INOLINE 5 // INOLINE 6
#define SR04_TRIG 3 // INOLINE 5 // INOLINE 6 // INOLINE 7
#define SR04_ECHO 2 // INOLINE 6 // INOLINE 7 // INOLINE 8
 // INOLINE 7 // INOLINE 8 // INOLINE 9
#define stPin1 8 // INOLINE 8 // INOLINE 9 // INOLINE 10
#define stPin2 9 // INOLINE 9 // INOLINE 10 // INOLINE 11
#define stPin3 10 // INOLINE 10 // INOLINE 11 // INOLINE 12
#define stPin4 11 // INOLINE 11 // INOLINE 12 // INOLINE 13
 // INOLINE 12 // INOLINE 13 // INOLINE 14
#define STEPS_PER_REV 32 // INOLINE 13 // INOLINE 14 // INOLINE 15
 // INOLINE 14 // INOLINE 15 // INOLINE 16
float duration; // INOLINE 15 // INOLINE 16 // INOLINE 17
Stepper stpMtr(STEPS_PER_REV,8,10,9,11); // INOLINE 16 // INOLINE 17 // INOLINE 18
 // INOLINE 17 // INOLINE 18 // INOLINE 19
void turnclockwise(int nspeed, int steps) // INOLINE 18 // INOLINE 19 // INOLINE 20
{ // INOLINE 19 // INOLINE 20 // INOLINE 21
  stpMtr.setSpeed(nspeed); // INOLINE 21 // INOLINE 22
  stpMtr.step(steps); // INOLINE 22 // INOLINE 23
} // INOLINE 21 // INOLINE 23 // INOLINE 24
 // INOLINE 22 // INOLINE 24 // INOLINE 25
void sonarSend() // INOLINE 23 // INOLINE 25 // INOLINE 26
{ // INOLINE 24 // INOLINE 26 // INOLINE 27
  digitalWrite(SR04_TRIG, LOW); // INOLINE 25 // INOLINE 27 // INOLINE 28
  delayMicroseconds(2); // INOLINE 26 // INOLINE 28 // INOLINE 29
  digitalWrite(SR04_TRIG, HIGH); // INOLINE 27 // INOLINE 29 // INOLINE 30
  delayMicroseconds(10); // INOLINE 28 // INOLINE 30 // INOLINE 31
  digitalWrite(SR04_TRIG, LOW); // INOLINE 29 // INOLINE 31 // INOLINE 32
} // INOLINE 30 // INOLINE 32 // INOLINE 33
 // INOLINE 31 // INOLINE 33 // INOLINE 34
float getDistance() // INOLINE 32 // INOLINE 34 // INOLINE 35
{ // INOLINE 33 // INOLINE 35 // INOLINE 36
   duration = pulseIn(SR04_ECHO, HIGH); // INOLINE 34 // INOLINE 36 // INOLINE 37
   return (duration/2)*0.0343; // INOLINE 35 // INOLINE 37 // INOLINE 38
} // INOLINE 36 // INOLINE 38 // INOLINE 39
 // INOLINE 37 // INOLINE 39 // INOLINE 40
void setup() // INOLINE 38 // INOLINE 40 // INOLINE 41
{ // INOLINE 39 // INOLINE 41 // INOLINE 42
  pinMode(SR04_TRIG, OUTPUT); // INOLINE 40 // INOLINE 42 // INOLINE 43
  pinMode(SR04_ECHO, INPUT); // INOLINE 41 // INOLINE 43 // INOLINE 44
  Serial.begin(9600);   // INOLINE 42 // INOLINE 44 // INOLINE 45
} // INOLINE 43 // INOLINE 45 // INOLINE 46
void loop() // INOLINE 44 // INOLINE 46 // INOLINE 47
{ // INOLINE 45 // INOLINE 47 // INOLINE 48
  sonarSend(); // INOLINE 46 // INOLINE 48 // INOLINE 49
  int dist = getDistance(); // INOLINE 47 // INOLINE 49 // INOLINE 50
  Serial.write(dist); // INOLINE 48 // INOLINE 50 // INOLINE 51
  if(dist < 40) // INOLINE 51 // INOLINE 52
  { // INOLINE 52 // INOLINE 53
    turnclockwise(700,16); // INOLINE 53 // INOLINE 54
  } // INOLINE 54 // INOLINE 55
  //turnclockwise(700,16);
  //delay(1000);
} // INOLINE 49 // INOLINE 55 // INOLINE 56

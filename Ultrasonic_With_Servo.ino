#include <Servo.h>
Servo servo;

int RF = 6;
int LF = 5;
int RB = 10;
int LB = 9;
int Trig = A4;
int Echo = A5;
float dist;
int degree = 0;
bool a = true;
bool c = true;


void setup() {
  // put your setup code here, to run once:
  pinMode(RF, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(3, OUTPUT);

  servo.attach(3);

  Serial.begin(9600);

}
void forward (int TIME) {
  analogWrite(RF, 130);
  analogWrite(LF, 130);
  analogWrite(RB, 0);
  analogWrite(LB, 0);
  delay(TIME * 100);

}
void spinRight (int TIME) {
  analogWrite(RF, 0);
  analogWrite(LF, 100);
  analogWrite(RB, 100);
  analogWrite(LB, 0);
  delay(TIME * 100);

}
void spinLeft (int TIME) {
  analogWrite(RF, 100);
  analogWrite(LF, 0);
  analogWrite(RB, 0);
  analogWrite(LB, 100);
  delay(TIME * 100);

}
void back2(int TIME) {
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LB, HIGH);
  delay(TIME * 100);

}

float distance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float fdistance = pulseIn(Echo, HIGH);
  fdistance = fdistance / 58;
  return fdistance;
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(dist);
  if (c) {
    degree = 90;
    servo.write(degree);
    c = false;
  }
  dist = distance();
  while (dist > 30) {
    forward(1);
    dist = distance();
    if (degree < 180 && a) {
      degree = degree + 10;
      servo.write(degree);
    }
    else if (degree > 0) {
      a = false;
      degree = degree - 10;
      servo.write(degree);
    }
    if (degree == 0) {
      a = true;
    }
  }
  while (dist < 30) {
    if (degree > 90) {
      Serial.println("hi");
      // spinLeft(10);
      back2(2);
      // spinRight(10);
      dist = distance();
    }
    else if (degree < 90) {
      Serial.println("hi");
      // spinRight(10);
      back2(2);
      // spinLeft(10);
      dist = distance();
    }
  }

}

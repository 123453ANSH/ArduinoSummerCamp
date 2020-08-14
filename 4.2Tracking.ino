const int sensorRight = A2;
const int sensorLeft = A3;


int leftMotor = 5;
int rightMotor = 6;
int leftBack = 9;
int rightBack = 10;


void setup() {
  
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(leftBack, OUTPUT);
  pinMode(rightBack, OUTPUT);
  pinMode(sensorRight, INPUT); //Right Sensor
  pinMode(sensorLeft, INPUT); //Left Sensor

}

void turnLeft(){

  analogWrite(rightMotor, 127);
  analogWrite(rightBack, 0);
  analogWrite(leftMotor, 0);
  analogWrite(leftBack, 127);
}

void turnRight(){

  analogWrite(rightMotor, 0);
  analogWrite(rightBack, 127);
  analogWrite(leftMotor, 127);
  analogWrite(leftBack, 0);
}

void moveForward(){

  analogWrite(rightMotor, 255);
  analogWrite(rightBack, 0);
  analogWrite(leftMotor, 255);
  analogWrite(leftBack, 0);
}

void moveBackward(){

  analogWrite(rightMotor, 0);
  analogWrite(rightBack, 255);
  analogWrite(leftMotor, 0);
  analogWrite(leftBack, 255);
}

void idle(){
  
  analogWrite(rightBack, 0);
  analogWrite(leftBack, 0);
  analogWrite(rightMotor, 0);
  analogWrite(leftMotor, 0);
}

void loop() {

 int leftInput = digitalRead(sensorLeft);
 int rightInput = digitalRead(sensorRight);

 if(leftInput == HIGH && rightInput == HIGH)
    moveForward();
 else if(leftInput == LOW && rightInput == LOW)
    moveBackward();
 else if(leftInput == LOW && rightInput == HIGH)
    turnRight();
 else if(leftInput == HIGH && rightInput == LOW)
    turnLeft();
 else 
    idle();

}

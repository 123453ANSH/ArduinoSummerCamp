#include <IRremote.h>

int LF = 5;
int RF = 6;
int RB = 10;
int LB = 9;
int recPin = A0;
//const int SensorRight = A2;
//const int SensorLeft = A3;
IRrecv irrecv(recPin);
decode_results result;
//test - 16720605
//16761405 - back
/* 1 = 16724175
 * 2 = 16718055
 * 3 = 16743045
 * 4 = 16716015
 * 5 = 16726215
 * 6 = 16734885
 * 7 = 16728765
 * 8 = 16730805
 */
#define Turn_Left 16720605
#define Turn_Right 16761405
#define Up_Arrow 16712445 //4294967295 - plus   
#define Down_Arrow 16750695 //4294967295 - minus
#define Left_Arrow 16769055 //4294967295  - skip back
#define Right_Arrow 16748655 //4294967295 - skip forward
#define Stop_Arrow 16754775 //4294967295 - play
void setup() {
  // put your setup code here, to run once:
pinMode(LF, OUTPUT);
pinMode(RF, OUTPUT);
pinMode(LB, OUTPUT);
pinMode(RB, OUTPUT);
pinMode(A0, INPUT); // switch
//pinMode(SensorRight, INPUT);// right sensor
//pinMode(SensorLeft, INPUT);// left sensor
Serial.begin(9600);
irrecv.enableIRIn();

}

void forward(){
  digitalWrite(RF,HIGH);
  digitalWrite(RB,LOW);
  digitalWrite(LF,HIGH);
  digitalWrite(LB,LOW);
  //delay(1000);
}
void left (){
  digitalWrite(RF,HIGH);
  digitalWrite(RB,LOW);
  digitalWrite(LF,LOW);
  digitalWrite(LB,LOW);
  //delay(1000);
}
void right (){
  digitalWrite(RF,LOW);
  digitalWrite(RB,LOW);
  digitalWrite(LF,HIGH);
  digitalWrite(LB,LOW);
  delay(1000);
}
void brake(){
  digitalWrite(RF,LOW);
  digitalWrite(RB,LOW);
  digitalWrite(LF,LOW);
  digitalWrite(LB,LOW);
}
void back (){
 digitalWrite(RF,LOW);
 digitalWrite(RB,HIGH);
 digitalWrite(LF,LOW);
 digitalWrite(LB,HIGH); 
}
void spinLeft(){
 digitalWrite(RF,HIGH);
 digitalWrite(RB,LOW);
 digitalWrite(LF,LOW);
 digitalWrite(LB,HIGH); 
}
void spinRight(){
 digitalWrite(RF,LOW);
 digitalWrite(RB,HIGH);
 digitalWrite(LF,HIGH);
 digitalWrite(LB,LOW); 
}
void loop() {
  // put your main code here, to run repeatedly:
if(irrecv.decode(&result)){
  switch(result.value){
    case Up_Arrow:
      forward ();
      break;
     case Down_Arrow:
       back();
       break;
     case Left_Arrow:
       left();
       break;
      case Right_Arrow:
        right();
        break;
      case Stop_Arrow:
        brake();
        break;
      case Turn_Right:
        spinRight();
        break;
      case Turn_Left:
        spinLeft();
        break;    
    }
    irrecv.resume();
  }
  //delay(10);
}

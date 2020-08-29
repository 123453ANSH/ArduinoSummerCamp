#include <IRremote.h>

int LF = 5;
int RF = 6;
int RB = 11;
int LB = 3;
int recPin = A0;
//const int SensorRight = A2;
//const int SensorLeft = A3;
IRrecv irrecv(recPin);
decode_results result;

#define Up_Arrow 16712445 //4294967295   
#define Down_Arrow 16750695 //4294967295
#define Left_Arrow 16769055 //4294967295 
#define Right_Arrow 16748655 //4294967295 
#define Stop_Arrow 16754775 //4294967295 
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
  digitalWrite(RF,LOW);
  digitalWrite(RB,HIGH);
  digitalWrite(LF,LOW);
  digitalWrite(LB,HIGH);
  //delay(1000);
}
void left (){
  digitalWrite(RF,LOW);
  digitalWrite(RB,HIGH);
  digitalWrite(LF,LOW);
  digitalWrite(LB,LOW);
  //delay(1000);
}
void right (){
  digitalWrite(RF,LOW);
  digitalWrite(RB,LOW);
  digitalWrite(LF,LOW);
  digitalWrite(LB,HIGH);
  //delay(1000);
}
void brake(){
  digitalWrite(RF,LOW);
  digitalWrite(RB,LOW);
  digitalWrite(LF,LOW);
  digitalWrite(LB,LOW);
}
void back (){
 digitalWrite(RF,HIGH);
 digitalWrite(RB,LOW);
 digitalWrite(LF,HIGH);
 digitalWrite(LB,LOW); 
}
void left2(){
  left();
  delay(200);
  brake();
}
void right2(){
  right();
  delay(200);
  brake();
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
       left2();
       break;
      case Right_Arrow:
        right2();
        break;
      case Stop_Arrow:
        brake();
        break;
          
    }
    irrecv.resume();
  }
  //delay(10);
}

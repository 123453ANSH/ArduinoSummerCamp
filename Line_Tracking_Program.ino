#include <Servo.h>
//Low means its recieving no light - ie,black
//high means recieving all light = ie.white
// ultrasonic and line tracking
int LF = 10; 
int RF = 9; 
int LB = 6;
int RB = 5; 
const int SR = A2; //analog input pins can be treated as ints 
const int SL = A3;
int SLVal;
int SRVal; 
int echo = A5;
int trigger = A4;
int y  = 0;
bool r = false; 
Servo servo; 
void Run(int TIME) {
  analogWrite(LF, 255); 
  analogWrite(RF, 255); 
  analogWrite(LB, 0); 
  analogWrite(RB, 0); 
  delay(TIME*100); 
}
void Brake(int TIME ){ 
  digitalWrite(RF,LOW); // if  a PWM port, can switch from analog to digital
  digitalWrite(LF,LOW);
  digitalWrite(RB,LOW);
  digitalWrite(LB,LOW);
  delay(TIME * 100);    //execution TIME, can be adjusted
}
void left(int TIME){ 
  analogWrite(RF, 70);
  analogWrite(RB,0);     //PWM ratio 0~255 speed control
  analogWrite(LF,0);
  analogWrite(RB,0);     //PWM ratio 0~255 speed control
  delay(TIME * 100);       //execution TIME, can be adjust
}
void right(int TIME)   //turn right (right wheel stop,left wheel go)

{

  
  analogWrite(RF,0);
  analogWrite(RB,0); //PWM ratio 0~255 speed control
  analogWrite(LF,70);
  analogWrite(LB,0);  //PWM ratio 0~255 speed control

  delay(TIME * 100);       //execution TIME, can be adjusted 
}
void spin_left(int TIME)         //left rotation(left wheel back，right wheel go)

{
  analogWrite(RF,200);
  analogWrite(RB,0);      //PWM ratio 0~255 speed control
  analogWrite(LF,0);
  analogWrite(LB,200);//PWM ratio 0~255 speed control
  delay(TIME * 100);   //execution TIME, can be adjusted  
}
void spin_right(int TIME)        //right rotation(right wheel back,left wheel go)

{
  analogWrite(RF,0);
  analogWrite(RB,250);    //PWM ratio 0~255 speed control
  analogWrite(LF,250);
  analogWrite(LB,0);      //PWM ratio 0~255 speed control
  delay(TIME * 100);   //execution TIME, can be adjusted   

}
void back(int TIME)

{
  analogWrite(RF,0);
  analogWrite(RB,150);//PWM ratio 0~255 speed control
  analogWrite(LF,0);
  analogWrite(LB,150);//PWM ratio 0~255 speed control
  delay(TIME * 100);     //execution TIME, can be adjusted 

}
int distanceCheck(){ 
  digitalWrite(trigger, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW); 

  double pulseDuration = pulseIn(echo, HIGH); //syntax - if put low, measures how long no signal apparently
  double distance = (pulseDuration/2) *0.0344; 
  return (int)distance; 
}
void avoidance(){ 
  int b = distanceCheck(); 
 // Serial.println(b); 
 // Serial.println(b);
  bool L = (b >= (30));
 Serial.println(L); 
  SRVal = digitalRead(SR);

  //There is a signal that in the white area the L3 is bright on the car floor;

  // no signal indicates that on the black line and the L3 is extinguishing on the car floor.

 

  SLVal = digitalRead(SL);

  //There is a signal that in the white area the L2 is bright on the car floor;

  // no signal indicates that on the black line and the L2 is extinguishing on the car floor.

 
  if(!L){ 
    //back(1);
    spin_right(1); //test val
  }
  else if (SRVal == HIGH&& SLVal==HIGH ){ // HIGH follows black, SO ONLY RUN WHEN LOW, high stops
//needs to be really really sunny/light! - put flashlight on the zone!
    Run(1);   //Call run function
    Serial.println(2);
  }
  else if (SRVal ==LOW && SLVal==LOW){

  //Right tracking infrared sensor signal is detected,the car deviates from  track, turn right   

    back(1);
  }
  else if (SRVal == LOW&& SLVal== HIGH  ){

  //Left tracking infrared sensor signal is detected,the car deviates from  track, turn left

    spin_left(1); //see speed, adjust accordingly
  }
  else if (SRVal ==HIGH && SLVal==LOW ){

  //Right tracking infrared sensor signal is detected,the car deviates from  track, turn right   

    spin_right(1);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo, INPUT); 
  pinMode(trigger, OUTPUT); 
  pinMode(LF,OUTPUT);   // PIN 5 (PWM)
  pinMode(RF,OUTPUT); // PIN 9 (PWM)
  pinMode(LB,OUTPUT);  // PIN 6 (PWM)
  pinMode(RB,OUTPUT);// PIN 10 (PWM)
   pinMode(SR, INPUT); //Define Right tracking infrared sensor for the input interface
  pinMode(SL, INPUT);  //Define left tracking infrared sensor for the input interface
  servo.attach(3); 
}


void loop() {
  // put your main code here, to run repeatedly:
  //There is a signal is LOW, no signal is HIGH
  Serial.println(y);
 // Serial.println(y); 
  if( y <180 && !r){ 
    y+= 90; 
    servo.write(y); 
    avoidance();
 }
 else{ 
  if(y <=0){
    r = false; 
  }
  else{
  r = true; 
  y -= 90; 
  servo.write(y); 
  avoidance();
 }
 }
 delay(1000); //decreases ability to detect changes
 }

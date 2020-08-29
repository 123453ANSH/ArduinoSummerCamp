int RF = 10; 
int LF = 9; 
int RB = 6;
int LB = 5; 

const int SR = A4; 
const int SL = A5; 



void setup() {
  pinMode(11,OUTPUT);
  //dont be a retard
  // put your setup code here, to run once:
}
void run(){ 
  analogWrite(RF, 100);
   analogWrite(RB, 0); // u will never need these 
 analogWrite(LF, 100); 
   analogWrite(LB, 0); // u will never need these 
}
void left() {
analogWrite(RF, 200); 
  analogWrite(RB, 0); // u will never need these 
  analogWrite(LF, 0); 
   analogWrite(LB, 0); // u will never need these 
}
void right() { 
analogWrite(RF,0);
analogWrite(RB, 0); // u will never need these 
  analogWrite(LF,200); 
 analogWrite(LB, 0); // u will never need these 
}
void back() { 
  analogWrite(RF,0);
analogWrite(RB, 100); // u will never need these 
  analogWrite(LF,0); 
 analogWrite(LB, 100); // u will never need these 
}
void turn() { 
  analogWrite(RF,100);
analogWrite(RB,0 ); // u will never need these 
  analogWrite(LF,0); 
 analogWrite(LB, 100); // u will never need these 
}


void loop() { // CAN ADJUST SENSITIVITY IF USE ANALOGREAD - GO BACK AND FIX 
  digitalWrite(11,LOW);
  // put your main code here, to run repeatedly:
 if( digitalRead(SR) == HIGH  &&  digitalRead(SL) == HIGH){ 
  digitalWrite(11,HIGH);
  run();
  delay(100); 
 }
 else if(digitalRead(SR) == LOW  &&  digitalRead(SL) == HIGH){// when would u need to turn left
  digitalWrite(11,HIGH);
  left() ; // change cuz it was opposite before
  delay(100); 
 } 
 else if(digitalRead(SR) == LOW  &&  digitalRead(SL) == LOW)  {
digitalWrite(11,HIGH);
back(); 
  delay(1000); 
turn(); 
delay(2000)
 }
 else{ 
  digitalWrite(11,HIGH);
  right() ;
  delay(100);
 }
 
}

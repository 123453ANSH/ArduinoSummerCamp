#include <IRremote.h>   //including infrared remote header file
const int RECV_PIN = 3;        // the pin where you connect the output pin of IR sensor 
IRrecv irrecv(RECV_PIN);
decode_results results;

const int motorLF = 5;
const int motorLB = 6;
const int motorRF = 9;
const int motorRB = 10;

#define plus 16718055
#define left 16730805
#define right 16716015      //change if necessary
#define play 16734885
#define minus 16726215

void setup() {
  pinMode(5, OUTPUT); 
   pinMode(6, OUTPUT); 
    pinMode(9, OUTPUT); 
     pinMode(10, OUTPUT); 
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) 
  {
    unsigned long value = results.value;
  switch(value){
    case plus:
      forward(200);
      break;
    case left:
      spinLeft(100);
      break;
    case right:
      spinRight(100);
      break;
    case play:
      Stop();
      break;
    case minus:
      backward(200);
      break;      
  }
    irrecv.resume();      
  }
}

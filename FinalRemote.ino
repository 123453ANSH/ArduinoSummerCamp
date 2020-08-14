#include <IRremote.h>

int IRsensorPin = A0;
IRrecv irrecv(IRsensorPin);
decode_results results;

int rightForward = 6;
int leftForward = 5;
int rightReverse = 10;
int leftReverse = 9;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(rightForward, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(rightReverse, OUTPUT);
  pinMode(leftReverse, OUTPUT);
}

  void Forward() {
    digitalWrite(rightForward,HIGH);
    digitalWrite(leftForward, HIGH);
    digitalWrite(rightReverse, LOW);
    digitalWrite(leftReverse, LOW);
 
  
  }

  void Reverse() {
    digitalWrite(rightForward,LOW);
    digitalWrite(leftForward, LOW);
    digitalWrite(rightReverse, HIGH);
    digitalWrite(leftReverse, HIGH);
   
  }
  
  void Right() {
    digitalWrite(rightForward,LOW);
    digitalWrite(leftForward, HIGH);
    digitalWrite(rightReverse, HIGH);
    digitalWrite(leftReverse, LOW);
  
  }

   void Left() {
    digitalWrite(rightForward,HIGH);
    digitalWrite(leftForward, LOW);
    digitalWrite(rightReverse, LOW);
    digitalWrite(leftReverse, HIGH);
  
  }

   void Stop() {
    digitalWrite(rightForward,LOW);
    digitalWrite(leftForward, LOW);
    digitalWrite(rightReverse, LOW);
    digitalWrite(leftReverse, LOW);
  }

  
void loop() {
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    delay(100000);
    irrecv.resume();
  }

  if(results.value == 16712445) Forward();
  if(results.value == 16750695) Reverse();
  if(results.value == 16748655) Right();
  if(results.value == 16769055) Left();
  if(results.value == 16754775) Stop();
  

}
 

int x = 1; 
int y = 2; 

void setup() {
  // put your setup code here, to run once:
  // voltage and current is ALWAYS GIVEN BY THE GROUND PIN, BUT BY PUTTING THE POSITIVE PIN AS OUTPOUT, YOU CAN CHANGE THE VOLTAGE GIVEN TO THE POSITIVE PIN 
  // BY PUTTING AS INPUT, ALL YOU DO IS READ THE VOLTAGE, NO CHANGING 
pinMode(2, OUTPUT); 
pinMode(4, OUTPUT); 
pinMode(6, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
if(x < y){ 
  digitalWrite(2, HIGH); 
  x = x + 2 // varaiable manipulation, this does NOT DECLARE A VARIALBE - declaring decides its scope - this just edits a variable
  delay(1000);
   digitalWrite(2, LOW); 
   delay(1000); 
}
else if(y < x){
   digitalWrite(4, HIGH); 
   y = y + 1; 
   delay(1000);
    digitalWrite(4, LOW);
    delay(1000); 
   // x is now 3, and y is now 3
}
else(){ 
   digitalWrite(6, HIGH); 
   delay(1000);
    digitalWrite(6, LOW); 
      delay(1000);
   y = y +1
   // y is now 4
}

}

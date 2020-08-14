//make a switch ciruit - just a switch in it
//other circuit with a buzzer
// if the button is pressed, turn on the buzzer on the other circuit



//analog and digital reading input - with button sensor! 
//when circuit becomes connected, will be able to read voltage from closed circuit, when reads voltage from controlled circuit, buzzer turns on 
void setup() {
  // put your setup code here, to run once:
pinMode(4, OUTPUT); //output controls electricty going into circuit
pinMode(A0, INPUT); // ONLY measures voltage in circuit
//A0 - A5 specially designed to be analog INPUT pins - read any value between 0-1023
// 1023 - 5 V
/*
 * A0 - A5 can do digitalRead or AnalogRead
 * any port with a line next to it (PWM ports) - can do same as AO-A5
 * all others must use digitalRead
 */
}

void loop() {
  // put your main code here, to run repeatedly:
//if button is not pressed, then circuit is open - no voltage or current is running through circuit
//if is pressed, then we will read voltage/current
while( analogRead(A0) > 80){ // 50 is a value that corresponds to a voltage value, 50 is inbetween 0-1023
  digitalWrite(4, HIGH); 
}

}

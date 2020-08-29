//analog and digital reading input - with button sensor
//when circut becomes connceted, will be able to read voltage from clsed circit, and buzzer turns on


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(A0,INPUT);
  //A0 - A5 specifically designed to be analog input pins - read values between 0 -1023
  //0 - 0 V
  //1023 - 5 V
  /*
   * A0 - A5 can do digitalRead or AnalogRead
   * and port with a lin can do it to
   * all others use digital read
   */

}

void loop() {
  // put your main code here, to run repeatedly:
  //button not pressed, circut open
  //if pressed, can read voltage
  Serial.println;
  while(analogRead(A0) > 200){ //50 is a value, correspond to voltage
    digitalWrite(4, HIGH);
    delay(4000);
  }

}

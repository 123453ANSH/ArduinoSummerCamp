
// exactly what your previous program did - turning on the motor gradually
int g = 5; 
//for loop = control structure-  similar to while loop
// will keep running until the condition is proven false 


void setup() {
  // put your setup code here, to run once:
pinMode(g, OUTPUT); 
}

  // put your main code here, to run repeatedly:void loop() {

for(int i = 0; i < 255 ; i = i + 5){
  // i is a local varaible, is made and manipulated in the for loop, after the for loop boolean condition is proven false and the compiler exits the for loop, the i variable disappears
  //when compiler reaches for loop again, i varaible remade as 0, and then for loop reruns
  //because of this, we do not need to worry about resetting varaibles at end of code
  analogWrite(g, i);
  //code goes in herre
 /*
  * (making a variable, making the boolean condition, how you manipulate the variable)
  * way a for loop runs 
  * declares variable 
  * runs code 
  * manipulates variable 
  * checks boolean condition
  * runs code
  * manipulates varaible
  * checks boolean condition
  * runs code
  * manipulates varaible
  * checks boolean condition 
  * keeps doing this until boolean condition is proven false
  */
}
delay(3000);
analogWrite(g, 0); 
delay (3000);
}

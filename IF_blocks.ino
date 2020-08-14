int x = 5 ; 
int e = 7;
int g = 9; 
// if blocks only run ONE condition at a time
// regular if statements right next to eachother, as long as the boolean condition is correct, will ALL run EVERY single
void setup() {
  Serial.begin(9600); 
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
/* syntax for if blocks
 *  always - first control structure is this - if (boolean condition) {run code} 
 *  have 1 if statement in a if block
 *  next - else if statement - syntax - else if (another boolean condition) {run code} 
 *  else if statements - infinite amount of else if statementa
 *  last statement - else control steructure - runs any other possible conidtion that what was already tested in previous if or else if control structures in the block 
 *  if all the previous control structure statements are FALSE, then the else statemnt will run 
 *  only 1 else statement in the block 
 */
 // example
 if ( g < e){ 
  Serial.print("condition 1 is not true");
 }
 else if( g > e){ 
   Serial.print("condition 2 is  true");
 }
 else if(g > x){ 
  Serial.print("condition 3 is also true");
 }
 // else statement has NO CONDITION, will only run if the previous boolean conditions were all FALSE
}

void forward(int velocity, int TIME) {
  analogWrite(motorLB, 0);
  analogWrite(motorRB, 0);
  analogWrite(motorLF, velocity);
  analogWrite(motorRF, velocity);
  delay(TIME *100);
}
void backward(int velocity, int TIME) {
  analogWrite(motorLF, 0);
  analogWrite(motorRF, 0);
  analogWrite(motorLB, velocity);
  analogWrite(motorRB, velocity);
    delay(TIME *100);
}
void spinLeft(int velocity, int TIME) {
  analogWrite(motorLF, 0);
  analogWrite(motorRF, velocity);
  analogWrite(motorLB, velocity);
  analogWrite(motorRB,0);
    delay(TIME *100);
}
void spinRight(int velocity, int TIME) {
  analogWrite(motorLF, velocity);
  analogWrite(motorRF, 0);
  analogWrite(motorLB, 0);
  analogWrite(motorRB, velocity);
    delay(TIME *100);
}
void Stop(int velocity, int TIME) {
  analogWrite(motorLF, 0);
  analogWrite(motorRF, 0);
  analogWrite(motorLB, 0);
  analogWrite(motorRB, 0);
    delay(TIME *100);
}

/* Blink Program
 * 
 * Turns the LED on the Arduino on and off in one second intervals...
 * 
 */

int led = 13; //Pin 13 has a light attached to it on most arduinos

//Runs once when the reset button is pressed
void setup() {
  //Initialize the digital pin as output
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(100);
}

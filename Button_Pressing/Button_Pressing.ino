/*
 * Button Press for turning on an LED
 * 
 * 
 */

const int LED = 9;
const int BUTTON = 2;

//Variables to handle bouncing button (Since the button may bounce when pressed)
boolean lastButtonState = LOW;
boolean currentButtonState = LOW;
boolean ledOn = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {

  currentButtonState = getButtonState(lastButtonState);
  if(lastButtonState == LOW && currentButtonState == HIGH){
    ledOn = !ledOn;
  }
  lastButtonState = currentButtonState;
  digitalWrite(LED, ledOn);
}

/*
 * Debouncing Function!
 * Param: last button state
 * Returns: Current Debounced Button State
 */

boolean getButtonState(boolean lastState){
  boolean current = digitalRead(BUTTON);
  if(lastState != current) {//If the button state is different wait 5ms to make sure it doesn't bounce
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

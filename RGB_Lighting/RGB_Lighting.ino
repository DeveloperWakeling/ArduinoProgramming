/*
 * Button Press for turning on an LED
 * 
 * 
 */

const int RED_LED = 9;
const int GREEN_LED = 10;
const int BLUE_LED = 11;
const int BUTTON = 2;

//Variables to handle bouncing button (Since the button may bounce when pressed)
boolean lastButtonState = LOW;
boolean currentButtonState = LOW;
int ledMode = 0;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {

  currentButtonState = getButtonState(lastButtonState);
  if(lastButtonState == LOW && currentButtonState == HIGH){
    ledMode++;
  }
  lastButtonState = currentButtonState;
  if(ledMode == 8){ 
    ledMode = 0;
  }
  setMode(ledMode);
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

void setMode(int mode){
  switch(mode){
    case 1:
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
      break;
    case 2:
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(BLUE_LED, LOW);
      break;
    case 3:
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, HIGH);
      break;
    case 4:
      analogWrite(RED_LED, 127);
      analogWrite(GREEN_LED, 0);
      analogWrite(BLUE_LED, 127);
      break;
    case 5:
      analogWrite(RED_LED, 0);
      analogWrite(GREEN_LED, 127);
      analogWrite(BLUE_LED, 127);
      break;
    case 6:
      analogWrite(RED_LED, 127);
      analogWrite(GREEN_LED, 127);
      analogWrite(BLUE_LED, 0);
      break;
    case 7:
      analogWrite(RED_LED, 85);
      analogWrite(GREEN_LED, 85);
      analogWrite(BLUE_LED, 85);
      break;
    default:
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
      break;
  }
}

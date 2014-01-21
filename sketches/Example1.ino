/*
   Based on the DigitalReadSerial example provided by Arduino.
   This is a slight modification. If the button state is changed from LOW to HIGH
   then the text 'BUTTON PRESSED' is emitted over Serial connection.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int previousState = LOW;
int currentState = LOW;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  currentState = digitalRead(pushButton);
  if (currentState != previousState){
    if (currentState == HIGH)
        Serial.println("BUTTON PRESSED");
    previousState = currentState;
  }
  // print out the state of the button:
  
  delay(20);        // delay in between reads for stability
}



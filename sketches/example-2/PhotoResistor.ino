/*
  Based on the AnalogReadSerial Example
  Reads an analog input on pin 0, prints the result to the serial monitor.
 */
int prevValue = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  if (sensorValue != prevValue){
      prevValue = sensorValue;
      String mesg = "LIGHT " + sensorValue;
      Serial.println(sensorValue);
  }
  // print out the value you read:
  
  delay(20);        // delay in between reads for stability
}

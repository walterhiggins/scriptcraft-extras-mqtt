/*
   Based on the DigitalReadSerial example provided by Arduino.
   This is a slight modification. If the button state is changed from LOW to HIGH
   then the text 'BUTTON PRESSED' is emitted over Serial connection.
   
   Use the schematic/circuit suggested here http://arduino.cc/en/Tutorial/DigitalReadSerial
   
   You'll need to install mosquitto or another MQTT broker.
   
   1. Start the mosquitto broker (using default host/port localhost:1883)
   2. Pipe the serial output through mqtt like this...
   
      tail -f /dev/tty.usbmodemfd131 | mosquitto_pub -t arduino -l

   3. Start up Craftbukkit like this...
       
      java -cp sc-mqtt.jar:craftbukkit.jar org.bukkit.craftbukkit.Main

   4. At the server console prompt type
   
      js var mqtt = require('sc-mqtt'), client = mqtt.client();
      js client.connect();
      js client.subscribe('arduino');
      js world = server.getWorld('world');
      js client.onMessageArrived(function(topic,message){ var time = world.time+12000; world.time=time });
      
   5. Launch the minecraft client and join the server in multi-player mode.
   
   6. Press the pushbutton to advance time by 1/2 a day.
   
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



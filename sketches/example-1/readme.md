# Basic Arduino to Minecraft Interaction

## What you'll need...

### Hardware
This example uses very basic components, a push-button, resistor and
some jumper leads. See
<http://arduino.cc/en/Tutorial/DigitalReadSerial> for the full list of
components needed. Use the same circuit and schematic on your
breadboard.

### Software
Use the source file above. It's a slightly modified version of the
code from the [DigitalReadSerial][arddr] example provided by
Arduino. The sketch above writes 'BUTTON PRESSED' to the serial port
if the button has been pressed. The serial port output needs to be
piped through another process (an MQTT publisher) so it can be passed
on to ScriptCraft via an MQTT broker. MQTT is a pub/sub messaging
protocol for machine-to-machine communication. It relies on the
presence of a 'broker' - a process that passes on messages to
others. [Mosquitto][mosq] is an open-source freely available MQTT
broker for Windows, Mac and Linux. To install it on Mac OS you'll need
to first install [HomeBrew][hb] then `brew install mosquitto` (if
mosquitto isn't in your PATH, add /usr/local/sbin to your PATH
environment variable or follow the instructions given by `brew
doctor`) .

The flow of data from Arduino to Minecraft is...

    +---------+    +---------------+   +-----------+    +----------------------------+
    | Arduino | => | mosquitto_pub |=> | mosquitto | => | scriptcraft => craftbukkit |
    +---------+    +---------------+   +-----------+    +----------------------------+
              (serial)             (mqtt)          (mqtt)

... Serial output from the Arduino is piped into a MQTT message queue. Scriptcraft can listen for incomming MQTT messages.

 1. Start `mosquitto` at a command prompt.
 2. Launch the Arduino IDE then open the above sketch and upload it to the arduino.
 3. Open the serial monitor (this is important - on a Mac at least, I can't tail -f without the Serial monitor window being open - I don't know why that is)
 4. Find out what serial port your arduino is connected to then at another command prompt type...

        tail -f /dev/{serial-port-id} | mosquitto_pub -t arduino1 -l
    
    ... to pipe the serial port input into the mosquitto_pub
    command. This causes any output from the arduino's serial port to
    be published as messages for the MQTT broker to pass on.

 5. At this point you should probably verify that the arduino output
    will be sent to the broker, run the following command in another
    command prompt and press the pushbutton a couple of times to verify
    that messages are coming in each time the button is pressed...

        mosquitto_sub -t arduino1

    ... once verified you can quit the `mosquitto_sub` process.

 6. Copy the above arduino-example1.js file to the scriptcraft/plugins/ directory.

 7. Start up the Craftbukkit minecraft server like this...

        java -classpath sc-mqtt.jar:craftbukkit.jar org.bukkit.craftbukkit.Main

 8. Press the pushbutton to switch from day to night, dusk to dawn and vice versa.

[mosq]: http://mosquitto.org/download/
[arddr]: http://arduino.cc/en/Tutorial/DigitalReadSerial





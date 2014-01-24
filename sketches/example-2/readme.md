# Using a Photo-Resistor (LDR) to change the time of day in Minecraft

## Video demo
<http://www.youtube.com/watch?v=ypbFBXCOg_k>

## Schematic
![Schematic Diagram][sd]

This example uses a photo-resistor, Arduino, MQTT and Scriptcraft to change the time of day in Minecraft.

As with the previous example, you'll need...

 1. An Arduino with Resistor, Wires, Photo-Resistor and USB Cable.
 2. A Running MQTT Broker - I recommend [mosquitto][mq].
 3. An operating system with the `tail` command - ( You can get this with [CgyWin][cw] for Windows).
 4. An MQTT publish command - I recommend `mosquitto_pub` as it supports piping from STDIN.
 5. [CraftBukkit][cb] and [ScriptCraft][sc] 
 6. The ScriptCraft [mqtt add-on jar][sc] - See instructions in top-level README.md for running CraftBukkit with this add-on.

## Instructions

 1. Load the above .ino file into your Arduino using the Arduino IDE and open the Serial Monitor.
 2. At a command prompt start the mosquitto broker `mosquitto &` .
 3. At another prompt start piping the Arduino ouput into mosquitto `tail -f /dev/tty.usbmodemfd131 | mosquitto_pub -t arduino-light -l` .
 4. Drop the arduino-light.js file into your scriptcraft/plugins/ directory and start CraftBukkit. `java -cp sc-mqtt.jar:craftbukkit.jar org.bukkit.craftbukkit.Main` .
 5. Change the light (cover with hand or for best effect use an indoor dimmer) to see changed time in the game.

[sd]: ArduinoJumperSketch.jpg
[cw]: http://cywin.org/
[cb]: http://dl.bukkit.org/
[sc]: https://github.com/walterhiggins/ScriptCraft/releases
[mq]: http://mosquitto.org/

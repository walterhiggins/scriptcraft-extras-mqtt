scriptcraft-extras-mqtt
=======================

Supplemental stuff for using ScriptCraft with MQTT (protocol for
network-connected arduinos).

This repository adds MQTT support to ScriptCraft. It should be used in
conjunction with ScriptCraft and is not a replacement for ScriptCraft.

To Use
------

The sc-mqtt.jar file which this project builds must be included in the
classpath when starting up bukkit. Copy the sc-mqtt.jar file into the
craftbukkit directory. The craftbukkit server must be started like
this (on Linux)...

    java -cp scmqtt.jar:craftbukkit.jar org.bukkit.craftbukkit.Main

... on Windows, use the following command...

    java -cp scmqtt.jar:craftbukkit.jar org.bukkit.craftbukkit.Main

... (the path separator character is different on each operating system, it's `:` on linux and `;` on windows )

Once started in this way, you can connect to an MQTT broker using the following code...

    var mqtt = require('sc-mqtt');
    var client = mqtt.connect('localhost:1883', {
      clientid: 'sc-mqtt',
      keepalive: 10000
    });
    client.publish('scriptcraft','loaded');
    client.subscribe('arduino');

    client.on('connectionLost', function(cause){
       // optional callback to handle connection loss
    });

    client.on('messageArrived', function(topic, message){
       // handle incoming messages here.
       var bytes = message.payload;
       // see <http://git.eclipse.org/c/paho/org.eclipse.paho.mqtt.java.git/tree/org.eclipse.paho.client.mqttv3/src/main/java/org/eclipse/paho/client/mqttv3/MqttMessage.java>
    });

    client.on('deliveryComplete', function(deliveryToken){
       // optional callback to handle completion of outgoing messages
       // (message ACK'd by receiver)
    });

sc-mqtt uses the [Eclipse Paho MQTTV3 Client][paho] library. 

Example - publishing a MQTT message when a minecraft block is broken...

    var mqtt = require('sc-mqtt');
    var client = mqtt.connect();
    events.on('block.BlockBreakEvent', function (listener, event){
        client.publish('blockbreak',  // topic
                       [1],           // payload
                       1);             // QoS (1 is send at least once)
    });

[paho]: http://git.eclipse.org/c/paho/org.eclipse.paho.mqtt.java.git/

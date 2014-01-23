var mqtt = require('sc-mqtt'),
  foreach = require('utils').foreach,
  client = mqtt.client('tcp://localhost:1883','sc-ard-light'),
  preDawn = 22000,
  JavaString = java.lang.String;
  
client.connect();
client.subscribe('arduino-light');

client.onMessageArrived(function(topic,message){
    var val = +(new JavaString(message.payload));
    foreach(server.worlds, function(world){
        world.time = preDawn + (val * 200);
    });
});

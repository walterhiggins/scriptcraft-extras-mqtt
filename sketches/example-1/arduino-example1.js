var mqtt = require('sc-mqtt'),
  foreach = require('utils').foreach,
  client = mqtt.client(),
  JavaString = java.lang.String;
         
client.connect();
client.subscribe('arduino1');

client.onMessageArrived( function(topic,message){
    if (topic == 'arduino1' && message == 'BUTTON PRESSED\r') ){
        /*
          change the time in each of the server's worlds.
          Day becomes night, night becomes day.
         */
        foreach( server.worlds, function(world){
            var time = world.time + 12000; // adds 1/2 day to time
            world.time = time;
        });                 
    }
});

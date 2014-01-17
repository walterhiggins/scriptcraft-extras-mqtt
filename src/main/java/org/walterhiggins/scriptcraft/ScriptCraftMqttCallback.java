/*
  Copyright Walter Higgins 2014
  The Javascript engine provided out-of-the-box with both JDK 6 and 7 only supports SAM type interfaces
  (interfaces with a single abstract method). To get around this, I create 3 distinct interface classes,
  one for each of MqttCallback's 3 methods.
 */
package org.walterhiggins.scriptcraft;

import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;

public class ScriptCraftMqttCallback implements MqttCallback 
{
    public static interface IConnectionLost {
        public void connectionLost(Throwable cause);
    }
    public static interface IMessageArrived {
        public void messageArrived(String topic, MqttMessage message) throws Exception ;
    }
    public static interface IDeliveryComplete {
        public void deliveryComplete(IMqttDeliveryToken token);
    }
    
    protected IConnectionLost connLost = null;
    protected IMessageArrived mesgArrived = null;
    protected IDeliveryComplete deliveryComplete = null;
    
    public ScriptCraftMqttCallback(IConnectionLost connLost, 
                                   IMessageArrived mesgArrived, 
                                   IDeliveryComplete deliveryComplete){
        this.setConnLost(connLost);
        this.setMesgArrived(mesgArrived);
        this.setDeliveryComplete(deliveryComplete);
    }
    
    public void setConnLost(IConnectionLost connLost){
        this.connLost = connLost;
    }
    public void setMesgArrived(IMessageArrived mesgArrived){
        this.mesgArrived = mesgArrived;
    }
    public void setDeliveryComplete(IDeliveryComplete deliveryComplete){
        this.deliveryComplete = deliveryComplete;
    }
    public IConnectionLost getConnLost(){
        return this.connLost;
    }
    public IMessageArrived getMesgArrived(){
        return this.mesgArrived;
    }
    public IDeliveryComplete getDeliveryComplete(){
        return this.deliveryComplete;
    }
    /*
      Implementation
     */
    public void connectionLost(Throwable cause){
        this.connLost.connectionLost(cause);
    }
    public void messageArrived(String topic, MqttMessage message) throws Exception {
        this.mesgArrived.messageArrived(topic, message);
    }
    public void deliveryComplete(IMqttDeliveryToken token){
        this.deliveryComplete.deliveryComplete(token);
    }
}



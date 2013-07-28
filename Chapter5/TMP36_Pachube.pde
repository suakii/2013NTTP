/*
*/

import eeml.*;
DataOut dOut;
float lastUpdate;

void setup(){
    // set up DataOut object; requires URL of the EEML you are updating, and your Pachube API key   
    dOut = new DataOut(this, "http://api.xively.com/v2/feeds/1141023117.xml", "HKTxdMmy7rJhYP2stGZfLALqT6ScDmCPf1kbG3LNH53L22jk");
     //  and add and tag a datastream    
    dOut.addData(0,"humdity");
   // dOut.addData(1,"temperature");
  
}

void draw()
{
    // update once every 5 seconds (could also be e.g. every mouseClick)
    if ((millis() - lastUpdate) > 5000){
        println("ready to POST: ");
        dOut.update(0, random(1000)); // update the datastream
        //dOut.update(1, random(100)); // update the datastream
    
        int response = dOut.updatePachube(); // updatePachube() updates by an authenticated PUT HTTP request
        println(response); // should be 200 if successful; 401 if unauthorized; 404 if feed doesn't exist
        lastUpdate = millis();
    }   
}
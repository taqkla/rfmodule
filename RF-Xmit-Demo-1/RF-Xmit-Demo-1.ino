

/*
  433 MHz RF Module Transmitter Demonstration 1
  RF-Xmit-Demo-1.ino
  Demonstrates 433 MHz RF Transmitter Module
  Use with Receiver Demonstration 1

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

uint8_t msg[2];
void setup()
{
   Serial.begin(9600);
    //Initialize ASK Object
    rf_driver.init();
    
}

void loop()
{

     //Serial.println("random numbers");
     int M = random(10,99);
     uint16_t N = (uint16_t)M;
     Serial.println(N);
     //Serial.println(String(msg));
     uint8_t msg[2]={N,(N >> 8)};
      //dtostrf(N,2,0,msg);
      
     //Serial.println(msg);
//     if(Serial.available()>0)
//     {
//      int letter=Serial.read();
//      Serial.println(letter);
//     }
    rf_driver.send((uint8_t *)msg, 2);
    //Serial.println(N);
    //digitalWrite(13,HIGH);
    //rf_driver.waitPacketSent();
    Serial.println("sent");
    //Serial.println(N);
//    Serial.println(msg);
    delay(100);

}

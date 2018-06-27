

/*
  433 MHz RF Module Receiver Demonstration 1
  RF-Rcv-Demo-1.ino
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

  Demonstrates 433 MHz RF Receiver Module
  Use with Transmitter Demonstration 1

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h>

 RH_ASK rf_driver (2000, 11, 12);
char msg[2];

void setup()
{

     // pinMode(13, OUTPUT);
    
    // Initialize ASK Object
    rf_driver.init();
    
    // Setup Serial Monitor
    Serial.begin(9600);
}

void loop()
{

      
  
     
   // Set buffer to size of expected message
    uint8_t buf[2];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
    uint16_t merged = (buf[1] >> 8) | buf[0];
      // Message received with valid checksum
     // long buf=buf*1L;
      Serial.print("Message Received: ");
     // write( uint8_t *buffer, size_t size);
      Serial.println(*  (int*)buf );      
         
      //digitalWrite(13,HIGH);
    }
       
    
    
   
   
}

/*
 * Author: B J lambert
 * 
 * Reads and decodes data from a BN-880 or similar GPS module
 * Connect BN-880 TX to Arduino RX (pin0)***REMOVE WHEN PROGRAMMING THE ARDUINO***
 *                GND to Arduino GND
 *                VCC to Arduino 5V
 * decoder.begin(); and decoder.readRawData() must be run to collect GPS data
 * The baud rate is fixed at 9600
 * Note the sentences from the BN-880 start with GN and not GP as per the NMEA standard
 * To save variable memory the DATA_BUFFER_SIZE in the BN880Decoder.h file could be reduced in size from 250 bytes.
 * Reducing this may slow or stop the aquisition of the NMEA sentence.
 * With DATA_BUFFER_SIZE set to 250 bytes the aquistion of a GNGGA sentence is every 1-2 seconds.
*/

/*-----( Import needed libraries )-----*/

#include <BN880Decoder.h>

/*-----( Declare Constants and Pin Numbers )-----*/


/*-----( Declare objects )-----*/


BN880Decoder decoder;

/*-----( Declare Variables )-----*/


void setup()   /****** SETUP: RUNS ONCE ******/
{
 decoder.begin();
 delay(1000);
}
//----end setup----

void loop()   /****** LOOP: RUNS CONSTANTLY ******/

{  
  decoder.readRawData();//read data from GPS module 
  
 //**remove remarks to print the raw GNGGA sentence**
  //String result = (decoder.getSentence("GNGGA"));
    //if(result != "")
      //{
        //Serial.println(result);
      //} 
   
    if(decoder.getContentsGNGGA())
      {
        //Serial.println(decoder.sentence);
        Serial.print(F("Time "));
        Serial.print(decoder.hours);
        Serial.print(F(":"));
        Serial.print(decoder.minutes);
        Serial.print(F(":"));
        Serial.print(decoder.seconds);
        Serial.println();
        Serial.print(F("Latitude "));
        if(decoder.hemisphereNS == "N")
          {
            Serial.print(decoder.latitude,6);
          }
        else
          {
            Serial.print(-decoder.latitude,6);
          }
        Serial.println(" " + decoder.hemisphereNS);
        Serial.print(F("Longitude "));
        if(decoder.hemisphereEW == "E")
          {
            Serial.print(decoder.longitude,7);
          }
        else
          {
            Serial.print(-decoder.longitude,7);
          }
        Serial.println(" " + decoder.hemisphereEW);
        Serial.print(F("GPS fix "));
        if(decoder.gpsFix == "0")
          {
            Serial.println(F("Bad"));
          }
        else
          {
            Serial.println(F("Good"));
          }
        Serial.print(F("Satellites "));
        Serial.println(decoder.satellites,0);
        Serial.print(F("Horizontal dilution of precision "));
        Serial.println(decoder.hdop,2);
        Serial.print(F("Altitude "));
        Serial.print(decoder.altitude, 1);
        Serial.println(F(" metres"));
        Serial.print(F("Height of geoid above WGS84 ellipsoid "));
        Serial.print(-decoder.geoidHeight, 1);
        Serial.println(F(" metres"));
        Serial.println(F("***********************"));
        
      }
     
}
//--Loop Ends---



//*********Functions************************


 

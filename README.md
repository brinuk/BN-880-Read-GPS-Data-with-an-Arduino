# BN-880-Read-GPS-Data-with-an-Arduino

Using a BN-880 GPS module or similar and an Arduino Uno, the library and Arduino sketch will parse the incoming NMEA GNGGA sentence and print:

Time, 
Latitude, 
Longitude, 
GPS fix status, 
Number of satellites,
Horizontal dilution of position, 
Altitude, Height of geoid above WGS84 elipsoid. 

Each NMEA sentence is parity checked. 

The library is simple to modify and well documented for adapting to your own purpose.

Example of output from Arduino.





![GPS](https://user-images.githubusercontent.com/13920701/154806626-d43615bd-d7a0-4e02-b24a-613234ac62bc.jpg)

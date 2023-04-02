# Digital-Temperature-Sensor

In this project I purchased 2 DS18B20 digital temperature sensors.
My goal was the get a working library that others in the class could utilize if they wanted.


I made some minor adjustments to the Arduino code provided from this video https://www.youtube.com/watch?v=lSVOtoMqtrI.

There are also two linked githubs that had the libraries for the OneWire communication and code for multiple devices.

After making the minor adjustments to the arduino code, I tried to understand the different components that I would need for the C implementation of it.

![image](https://user-images.githubusercontent.com/95442814/229375109-04f74d54-d500-40b4-9efc-6fd53d1627ff.png)

This printAddress section didn't seem too complicated with using code from included libraries with "DeviceAddress".  

![image](https://user-images.githubusercontent.com/95442814/229375896-31785a0c-dd0f-45e2-80b7-ffe8b00239bf.png)

The setup section also didn't seem too complicated as long as I got the "getDeviceCount" and "getAddress" commands.

![image](https://user-images.githubusercontent.com/95442814/229376118-070290d9-27db-4ab9-ae7a-30fab47467d7.png)

In the loop section it seems to need the "requestTemperatures" "getAddress" and "getTempC" commands.
In total my library needed to be able to do these 5 commands that were displayed in this Arduino code.


First thing was that I needed to breakdown these two libraries to try and replicate it.

![image](https://user-images.githubusercontent.com/95442814/229374981-46fb83f5-81c8-47ca-8071-1c72ead2e957.png)

I also found this code that I tried to compare with to create the libraries https://github.com/nimaltd/ds18b20.

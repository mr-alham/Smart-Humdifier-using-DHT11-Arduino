# Smart_Humidifier_Using_DHT11_-_Arduino-Nano_by-ALHAM
This smart humidifier will help you to control humidifier using a Humidifier driver, Arduino Nano as well as a DHT11 sensor.

When humidity is below 40% humidifier will work on continous mode, And if humidity is between 40% to 65% humidifier will work on with pauses mode, As well as if humidity exceeded 65% humidifier will turn off as too much humidity is not good. _(*if this humidity range is not satisfying for you you can adjust maximum humidity and low humidity levels from the code)_

[_Why It’s Important to Manage the Humidity in Your House_](https://www.entekhvac.com/manage-the-humidity-in-house/)

##### follow on: 
> [twitter](https://twitter.com/alham__aa)
> [github](https://github.com/MrAlham)
##### contact on: 
> [alham@duck.com](alham@duck.com) 

###### parts:
* Arduino Nano/uno
* DHT11 sensor
* Humidifier Driver board
* 5V Relay

#.
first you should add 'DHTLib.zip' .zip library to your Arduino IDE.
then open the code from Arduino IDE and upload the code to your Arduino board.


_see circuit diagram to see clearly_
> Connect Arduino pin **2** to relay signal in pin. 

> Connect Arduino pin **A2** to DHT11 sensor's sata out pin.

> connect all **Gnd**[*] pins

> connect all **Vcc** pins

[*]: arduino_board's_gnd_pin, 

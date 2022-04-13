# Smart_Humidifier_Using_DHT11_-_Arduino_by-ALHAM
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

first you should add 'DHTLib.zip' .zip library to your Arduino IDE.
then open the code from Arduino IDE and upload the code to your Arduino board.


_see circuit diagram to see clearly_
> Connect Arduino pin **2** to relay signal in pin. 

> Connect Arduino pin **A2** to DHT11 sensor's sata out pin.

> connect all **Gnd** pins

> connect all **Vcc** pins

#### CODE:
```c++
// Smart_Humidifier_Using_DHT11_-_Arduino
// code written by alham,
// last modified date 2022.4.13
// follow on,
                // twitter :-https://twitter.com/alham__aa
                // github :-https://github.com/MrAlham
//contact from: alham@duck.com

#include<Arduino.h>
#include<dht.h>  // include library for working with dht11

#define humidifier 2        //humidifier's switch(relay) connects to
#define sensepin  A2        //dht 11 sensor's data out pin connects to

dht dht11;
int temp, humidity, state;
float val;
int previous_state = 0;
int max_humidity = 65;
int low_humidity = 40;

void setup() {

  Serial.begin(9600);     //openning Serial monitor with baud rate of 9600
  pinMode (humidifier, OUTPUT);       //setting relay's pin as output (humidifier's switch)

}

void loop() {
  val = dht11.read11(sensepin);       //getiing values from sensor
  delay(200);
  humidity = (dht11.humidity);                   //assigning humidity readings to variables
  humidity = (humidity - (humidity * 20 / 100)); //-20% to keep accuracy
  temp = (dht11.temperature);                    //assigning temperature readings to variabl
  temp = temp - 2;                               //-2 to keep accuracy
  delay(200);

  Serial.print("Humidity=  ");             //printing humidity on
  Serial.println(humidity);                //the serial monitor
  Serial.print("Temperature=  ");          //printing temperature on
  Serial.println(temp);                    //the serial monitor
  delay(200);

  if (humidity >= max_humidity) {
    if (previous_state != 0) {
      state_zero();
    }
  }

  if (humidity <= low_humidity) {
    if (previous_state != 1) {
      state_one();
    }
  }

  if (low_humidity + 1 <= humidity & max_humidity - 1 > humidity) {
    if (previous_state = 2) {
      state_two();
    }
  }
  Serial.println("### _starting delay period_ ###");
  delay (15000);
}
void state_zero() {
  if (state == 0) {
    Serial.println("switch state is '0' ");
    previous_state = 0;
  } else if (state == 1)
  {
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =2
    delay(500);
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =0
    delay(500);

    Serial.println("switch state is '0' ");
    state = 0;
    previous_state = 0;
  } else if (state == 2)
  {
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =0
    delay(500);
    Serial.println("switch state is '0' ");
    state = 0;
    previous_state = 0;
  }

}

void state_one() {
  if (state == 1) {
    Serial.println("switch state is '1' ");
    previous_state = 1;
  } else if (state == 2)
  {
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =0
    delay(500);
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =1
    delay(500);

    Serial.println("switch state is '1' ");
    state = 1;
    previous_state = 1;

  } else if (state == 0)
  {
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =1
    delay(500);
    Serial.println("switch state is '1' ");
    state = 1;
    previous_state = 1;
  }

}

void state_two() {
  if (state == 2) {
    Serial.println("switch state is '2' ");
    previous_state = 2;
  } else if (state == 0)
  {
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =1
    delay(500);
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =2
    delay(500);

    Serial.println("switch state is '2' ");
    state = 2;
    previous_state = 2;
  } else if (state == 1)
  {
    digitalWrite(humidifier, HIGH);
    delay(500);
    digitalWrite(humidifier, LOW);      //state =2
    delay(500);
    Serial.println("switch state is '2' ");
    state = 2;
    previous_state = 2;
  }

}

```
If yoy have any problem feel free to contact me.
Thank you, 

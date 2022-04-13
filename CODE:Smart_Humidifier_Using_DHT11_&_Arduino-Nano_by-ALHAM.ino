// Smart_Humidifier_Using_DHT11_-_Arduino
// code written by alham,
// last modified date 2022.4.13
// follow on,
                // twitter :-https://twitter.com/alham__aa
                // github :-https://github.com/MrAlham
//contact from: alham@duck.com

#include<Arduino.h>
#include<dht.h>  // include library for working with dht11

#define humidifier 2        //humidifier's switch connects to
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

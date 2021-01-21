/*
//键盘测试
// Visual Micro is in vMicro>General>Tutorial Mode
// 

    Name:       test1.ino
    Created:	2021/1/15 21:08:10
    Author:     WUJIGR\Administrator


// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
#include <Key.h>
#include <Keypad.h>

// Define Functions below here or use other .ino or cpp files
//



int ledList[9];
const byte rows = 4; //four rows
const byte cols = 4; //three columns
char keys[rows][cols] = {
  {1,2,3,1},
  {4,5,6.1},
  {7,8,9,1},
  {1,1,1,1},
};
byte rowPins[rows] = { 14, 15, 16, 12 }; //connect to the row pinouts of the keypad
byte colPins[cols] = { 17, 18, 19, 13 };
// The setup() function runs once each time the micro-controller starts
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
void setup()
{
	for (int i = 2; i < 11; i++) {
		ledList[i - 2] = i;
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	Serial.begin(9600);
}

// Add the main program code into the continuous loop() function
void loop()
{
	int key = keypad.getKey();

	Serial.println(key);
	if (key != NO_KEY) {
		digitalWrite(ledList[key-1], HIGH);
	}
	else {
		for(int i=0;i<9;i++)
			digitalWrite(ledList[i], LOW);
	}
	delay(50);
}
*/



/*
//bh1750fvi
// Visual Micro is in vMicro>General>Tutorial Mode
// 

	//Name:       test1.ino
	//Created:	2021/1/20 21:08:10
	//Author:     WUJIGR\Administrator


// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
#include "BH1750FVI.h"
#include <Wire.h> //IIC
#include <math.h>

BH1750FVIClass a = BH1750FVIClass(0X10);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.println(a.read());
	Serial.println("[lx]");
	delay(1000);
}
*/



//DH11
//记得装上拉电阻
// Visual Micro is in vMicro>General>Tutorial Mode
// 

	//Name:       test1.ino
	//Created:	2021/1/20 21:08:10
	//Author:     WUJIGR\Administrator


// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file

#define DHTIN 2
#include <TroykaDHT.h>

DHT dht(DHTIN, DHT11);
void setup()
{
	Serial.begin(9600);
	dht.begin();
}

void loop()
{
	dht.read();
	switch (dht.getState()) {
	case DHT_OK:
		Serial.print("Temperature = ");
		Serial.print(dht.getTemperatureC());
		Serial.println(" C \t");
		Serial.print("Temperature = ");
		Serial.print(dht.getTemperatureK());
		Serial.println(" K \t");
		Serial.print("Temperature = ");
		Serial.print(dht.getTemperatureF());
		Serial.println(" F \t");
		Serial.print("Humidity = ");
		Serial.print(dht.getHumidity());
		Serial.println(" %");
		break;
	case DHT_ERROR_CHECKSUM:
		Serial.println("Checksum error");
		break;
	case DHT_ERROR_TIMEOUT:
		Serial.println("Time out error");
		break;
	case DHT_ERROR_NO_REPLY:
		Serial.println("Sensor not connected");
		break;
	}
	delay(2000);
}

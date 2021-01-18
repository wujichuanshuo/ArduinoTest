// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       test1.ino
    Created:	2021/1/15 21:08:10
    Author:     WUJIGR\Administrator
*/

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

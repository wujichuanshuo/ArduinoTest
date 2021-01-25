// 
// 
// 

#include "YS_IRTM.h"




YS_IRTMClass::YS_IRTMClass(int RX, int TX)
{
	RXD = RX;
	TXD = TX;
	SoftwareSerial a = SoftwareSerial(8, 9);
	mySerial = &a;
	mySerial->begin(9600);
}

size_t YS_IRTMClass::write(uint8_t byte[], int len)
{
	mySerial->write(0XA1);
	mySerial->write(0XF1);
	for (int i = 0; i < len; i++) {
		mySerial->write(byte[i]);
	}
	return size_t(len);
}

int YS_IRTMClass::available()
{
	return mySerial->available();
}

int YS_IRTMClass::read()
{
	return mySerial->read();
}

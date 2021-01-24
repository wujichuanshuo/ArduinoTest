// YS_IRTM.h

#ifndef _YS_IRTM_h
#define _YS_IRTM_h

#include<SoftwareSerial.h>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class YS_IRTMClass
{
 protected:
	 int RXD, TXD;
	 SoftwareSerial *mySerial;


 public:
	 YS_IRTMClass(int RX, int TX);
	 virtual size_t write(uint8_t byte[],int len);
	 int available();
	 int read();
};

extern YS_IRTMClass YS_IRTM;

#endif


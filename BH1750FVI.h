// BH1750FVI.h

#ifndef _BH1750FVI_h
#define _BH1750FVI_h
#include <Wire.h> //IIC
#include <math.h>
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class BH1750FVIClass
{
 protected:
	 int BH1750address = 0x23;
	 byte buff[2];
	 int mode;

 public:
	void init();
	int read();
	BH1750FVIClass(int modes);
};

extern BH1750FVIClass BH1750FVI;

#endif


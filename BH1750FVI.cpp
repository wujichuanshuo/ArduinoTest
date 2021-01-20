// 
// 
// 

#include "BH1750FVI.h"

BH1750FVIClass::BH1750FVIClass(int modes) {
	mode = modes;
	Wire.begin();
}



void BH1750FVIClass::init()
{
	Wire.beginTransmission(BH1750address);
	Wire.write(mode);//1lx reolution 120ms
	Wire.endTransmission();

}

int BH1750FVIClass::read() {
	init();
	int i = 0;
	int num;
	Wire.beginTransmission(BH1750address);
	Wire.requestFrom(BH1750address, 2);
	while (Wire.available()) //
	{
		buff[i] = Wire.read();  // receive one byte
		i++;
	}
	Wire.endTransmission();
	if (2 == i)
	{
		num = ((buff[0] << 8) | buff[1]) / 1.2;
	}
	return num;
}



#include <math.h>
#include "converters.h"

int widthAmps[] = {10, 30};
int noBits[] = {12,10};
int offset[] = {0, 15};

int currentConvereterD2A(int digitalValue, enum sensorTypes sensorType)
{
	digitalValue = (digitalValue) % (int)(pow(2,noBits[sensorType])-1);
	return round(widthAmps[sensorType] * digitalValue / (pow(2,noBits[sensorType])-2.0f)) - offset[sensorType];
}

void currentArrayConvertersD2A(const void * values, int numberOfValues, enum sensorTypes sensorType)
{
	for(int i=0;i<numberOfValues;i++)
	{
		if(((int*)values)[i] != (pow(2,noBits[sensorType])-1))
		{
			((int*)values)[i] = currentConvereterD2A(((int*)values)[i], sensorType);	
		}
	}
}

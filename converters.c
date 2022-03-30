#include <math.h>

int currentConvereterD2A(int digitalValue)
{
	return round(10.0f * digitalValue / 4094);
}

void currentArrayConvertersD2A(const void * values, int numberOfValues)
{
	for(int i=0;i<numberOfValues;i++)
	{
		if(((int*)values)[i] != 4095)
		{
			((int*)values)[i] = currentConvereterD2A(((int*)values)[i]);	
		}
	}
}

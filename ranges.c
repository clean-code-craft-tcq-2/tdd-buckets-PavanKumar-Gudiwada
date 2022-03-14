#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

struct ranges{
	int lowerLim;
	int upperLim;
	int numberOfElements;
};

struct ranges finalRanges[5];
int numberOfRanges = 0;

struct ranges* findRanges(const void* values, int numberOfValues)
{
	int i;
	
	sort(values, numberOfValues);
	
	finalRanges[numberOfRanges].lowerLim = ((int*)values)[0];
	finalRanges[numberOfRanges].upperLim = ((int*)values)[1];
	finalRanges[numberOfRanges].numberOfElements = 2;
	
	for(i = 2; i < numberOfValues; i++)
	{
		if((((int*)values)[i] >= finalRanges[numberOfRanges].upperLim) && (((((int*)values)[i-1]+1) == ((int*)values)[i]) || ((((int*)values)[i-1]) == ((int*)values)[i])) )
		{
			finalRanges[numberOfRanges].upperLim = ((int*)values)[i];
			finalRanges[numberOfRanges].numberOfElements += 1;
		}else if ((((int*)values)[i-1]+1) != ((int*)values)[i])
		{
			numberOfRanges++;
			finalRanges[numberOfRanges].lowerLim = ((int*)values)[i];
			finalRanges[numberOfRanges].upperLim = ((int*)values)[i+1];
			finalRanges[numberOfRanges].numberOfElements = 2;
			i = i+1;//increment i by 1 here and then immediate increment will be done by for loop
		}
	}
	
	return finalRanges;
}

void printRages(struct ranges* finalRangesToPrint)
{
	printf("\nRange, Readings\n");
    for (int i = 0 ; i <= numberOfRanges ; i++)
    {
    	printf("%d - %d, %d\n", finalRangesToPrint[i].lowerLim, finalRangesToPrint[i].upperLim, finalRangesToPrint[i].numberOfElements);
	}
}

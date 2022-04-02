#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
#include "ranges.h"

struct ranges finalRanges[5] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
static int numberOfRanges = 0;

static void categoriseValue(const void* values, int * controlVariable, int numberOfValues)
{
	if((((int*)values)[*controlVariable] >= finalRanges[numberOfRanges].upperLim) && (((((int*)values)[*controlVariable-1]+1) == ((int*)values)[*controlVariable]) || ((((int*)values)[*controlVariable-1]) == ((int*)values)[*controlVariable])) )
	{
		finalRanges[numberOfRanges].upperLim = ((int*)values)[*controlVariable];
		finalRanges[numberOfRanges].numberOfElements += 1;
	}else if ((((int*)values)[*controlVariable-1]+1) != ((int*)values)[*controlVariable])
	{
		numberOfRanges++;
		finalRanges[numberOfRanges].lowerLim = ((int*)values)[*controlVariable];
		if(*controlVariable+1 < numberOfValues)
		{
			finalRanges[numberOfRanges].upperLim = ((int*)values)[*controlVariable+1];
			finalRanges[numberOfRanges].numberOfElements = 2;
		}else
		{
			finalRanges[numberOfRanges].numberOfElements = 1;
		}
		*controlVariable = *controlVariable+1;//increment i by 1 here and then immediate increment will be done by for loop
	}
}

struct ranges* findRanges(const void* values, int numberOfValues)
{
	int i;
	numberOfRanges = 0;
	
	absoluteArray(values, numberOfValues);
	sort(values, numberOfValues);
	
	finalRanges[numberOfRanges].lowerLim = ((int*)values)[0];
	finalRanges[numberOfRanges].upperLim = ((int*)values)[1];
	finalRanges[numberOfRanges].numberOfElements = 2;
	
	for(i = 2; i < numberOfValues; i++)
	{
		categoriseValue(values,&i, numberOfValues);
	}
	
	return finalRanges;
}

void printRanges(struct ranges* finalRangesToPrint)
{
	printf("\nRange, Readings\n");
    for (int i = 0 ; i <= numberOfRanges ; i++)
    {
    	printf("%d - %d, %d\n", finalRangesToPrint[i].lowerLim, finalRangesToPrint[i].upperLim, finalRangesToPrint[i].numberOfElements);
	}
}

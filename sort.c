#include <stdlib.h>

static int compare (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

void sort(const void* values, int numberOfValues)
{
    qsort ((int*)values, numberOfValues, sizeof(int), compare);
}

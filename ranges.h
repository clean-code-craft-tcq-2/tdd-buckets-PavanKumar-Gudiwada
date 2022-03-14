
struct ranges{
	int lowerLim;
	int upperLim;
	int numberOfElements;
};

extern struct ranges* findRanges(const void* values, int numberOfValues);

extern void printRanges(struct ranges* finalRangesToPrint);

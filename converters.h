
enum sensorTypes{
	bits12 = 0,
	bits10
};

extern int currentConvereterD2A(int, enum sensorTypes);

void currentArrayConvertersD2A(const void * values, int, enum sensorTypes);

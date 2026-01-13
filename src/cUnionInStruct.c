#include <stdio.h>
#include "customTypes.h"

typedef struct _SENSOR_DATA_
{
	union
	{
		uint8 ucTemp;
		uint8 ucPressure;
	} param;

} SENSOR_DATA;

int main()
{
	SENSOR_DATA s1;

	s1.param.ucTemp = 10;
	printf("Sensor Temp data: %hhu\n", s1.param.ucTemp);
	s1.param.ucPressure = 25;
	printf("Sensor Pressure data: %hhu\n", s1.param.ucPressure);

	return 0;
}
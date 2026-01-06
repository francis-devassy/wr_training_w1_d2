#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define TEMP_VAL_MAX		(100)
#define TEMP_VAL_MIN		(0)
#define TEMP_OUT_PIN_MAX	(8)
#define TEMP_OUT_PIN_MIN	(0)
#define TEMP_THRESHOLD		(45)
#define TEMP_CALIBRATE		(101)
#define WAIT_TIME			(3)

// Unsigned integer types
typedef unsigned char uint8;	// 8-bit unsigned
typedef unsigned short uint16;	// 16-bit unsigned
typedef unsigned long uint32;	// 32-bit unsigned

// Signed integer types
typedef signed char int8;	// 8-bit signed
typedef signed short int16;	// 16-bit signed
typedef signed long int32;	// 32-bit signed

bool readTemperature(uint8 ucTempSensorOutPin, uint32 ulTempThreshold,
					uint32 *pulCurrentTemp);

bool readTemperature(uint8 ucTempSensorOutPin, uint32 ulTempThreshold,
					uint32 *pulCurrentTemp)
{
	bool blReturn = false;
	time_t lTime = 0;
	uint32 ulTemperature = 0;

	if((ucTempSensorOutPin >= TEMP_OUT_PIN_MIN) &&
		(ucTempSensorOutPin <= TEMP_OUT_PIN_MAX) &&
		(ulTempThreshold >=0) && (pulCurrentTemp != NULL))
	{
		lTime = time(NULL);
		srand(lTime);
		ulTemperature = rand();
		ulTemperature =  ulTemperature % TEMP_CALIBRATE;

		if((ulTemperature >= TEMP_VAL_MIN) && (ulTemperature <= TEMP_VAL_MAX))
		{
			*pulCurrentTemp = ulTemperature;
			blReturn = true;
		}
	}
	else
	{
		printf("\n Failed to read Temperature: Invalid input");
	}

	return blReturn;
}

int main(void)
{
	uint32 ulTemperature = 0;
	uint8 ucTempSensorOutPin = 2;
	bool blReturn = false;

	while(true)
	{
		blReturn = readTemperature(ucTempSensorOutPin,
									TEMP_THRESHOLD, &ulTemperature);

		if(blReturn == true)
		{
			printf("\nTemp: %lu", ulTemperature);
		}
		else
		{
			printf("\nError in reading temperature");
		}
		sleep(WAIT_TIME);
	}

	return 0;
}

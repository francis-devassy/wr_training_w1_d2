#include <stdio.h>
#include <stdbool.h>
#include "customTypes.h"

typedef struct _CLIMATE_SENSOR_DATA_
{
	int32 lPressure;
	uint32 ulHumidity;
	uint8 ucTemp;
} CLIMATE_SENSOR_DATA;

bool dispalyData(CLIMATE_SENSOR_DATA ClimateData);
bool ReadData(CLIMATE_SENSOR_DATA *pClimateData);

bool ReadData(CLIMATE_SENSOR_DATA *pClimateData)
{
	bool blReturn = false;
	uint8 ucResult = 0;

	if(pClimateData != NULL)
	{
		printf("Enter Temp value:");
		ucResult = scanf("%hhu",&(pClimateData->ucTemp));
		printf("Enter Pressure value:");
		ucResult = scanf("%ld",&(pClimateData->lPressure));
		printf("Enter Humidity value:");
		ucResult = scanf("%lu",&(pClimateData->ulHumidity));

		if(ucResult == 0)
		{
			printf("\n Invalid input");
		}
	}
	
	return blReturn;
}

bool dispalyData(CLIMATE_SENSOR_DATA climateData)
{
	bool blReturn = false;
	printf("Climate data\n");
	printf("Temp: %u\n",climateData.ucTemp);
	printf("Pressure: %ld\n",climateData.lPressure);
	printf("Humidity: %lu\n",climateData.ulHumidity);
	blReturn = true;

	return blReturn;
}

int main(void)
{
	uint32 ulStructSize = 0;
	CLIMATE_SENSOR_DATA ClimateData = {0};
	ulStructSize = sizeof(ClimateData);

	ClimateData.ucTemp = 10;
	ClimateData.lPressure = 100;
	ClimateData.ulHumidity = 110;

	dispalyData(ClimateData);
	ReadData(&ClimateData);
	dispalyData(ClimateData);

	//size_t is an unsigned integer type
	printf("Struct size:%zu\n",sizeof(ClimateData));

	return 0;
}
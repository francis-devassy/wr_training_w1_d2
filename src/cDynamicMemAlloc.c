#include <stdio.h>
#include <stdlib.h>
#include "customTypes.h"

int main()
{
	uint8 ucArraySize = 0;
	uint8 ucIteration = 0;
	uint8 *pucId = NULL;
	printf("Enter total number of Id : ");
	scanf("%hhu",&ucArraySize);
	//pucId = (uint8 *) malloc (((ucArraySize) * (sizeof(uint8))));
	pucId = (uint8 *) calloc (ucArraySize, (sizeof(uint8)));

	if(pucId != NULL)
	{
		printf("Enter %hhu Id :\n",ucArraySize);

		for(ucIteration = 0; ucIteration < ucArraySize; ucIteration++)
		{
			scanf("%hhu",&pucId[ucIteration]);
		}
		printf("The Id entered are :\n");

		for(ucIteration = 0; ucIteration < ucArraySize; ucIteration++)
		{
			printf("%hhu\n",pucId[ucIteration]);
		}
		free(pucId);
	}
	else
	{
		printf("Error : failed to allocate memory\n");
	}

	return 0;
}
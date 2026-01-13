#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "customTypes.h"

#define NAME_STR_MAX_SIZE (50)

typedef struct _USER_DATA_
{
	uint8 ucValue1;
	uint16 unValue2;
	uint32 ulValue3;
} USER_DATA;

// typedef struct _USER_DATA2_
// {
// 	uint32 ulValue3;
// 	uint16 unValue2;
// 	uint8 ucValue1;
// } USER_DATA2;

typedef struct __attribute__((packed)) _USER_DATA2_
{
	uint8 ucValue1;
	uint16 unValue2;
	uint32 ulValue3;
} USER_DATA2;


int main()
{
	uint8 ucArray[50] = {5,10,24 , 0, 0,0,0,0,0,0,0};
	USER_DATA *pData = (USER_DATA *) ucArray;

	USER_DATA data;
	USER_DATA2 data2;
	
	printf("ucValue1 = %hhu\n", pData->ucValue1);
	printf("unValue2 = %hu\n", pData->unValue2);
	printf("ulValue3 = %lu\n", pData->ulValue3);

	uint8 ucArray2[50] = {5,10,24};
	USER_DATA2 *pData2 = (USER_DATA2 *) ucArray2;
	printf("ucValue1 = %hhu\n", pData2->ucValue1);
	printf("unValue2 = %hu\n", pData2->unValue2);
	printf("ulValue3 = %lu\n", pData2->ulValue3);

	printf("sizeof(USER_DATA) : %zu\n",sizeof(USER_DATA));
	printf("sizeof(data) : %zu\n",sizeof(data));

	printf("sizeof(USER_DATA2) : %zu\n",sizeof(USER_DATA2));
	printf("sizeof(data2) : %zu\n",sizeof(data2));

	

	printf("sizeof(uint8) : %zu\n",sizeof(uint8));//1
	printf("sizeof(uint16) : %zu\n",sizeof(uint16));//2
	printf("sizeof(uint32) : %zu\n",sizeof(uint32));//8

	// printf("sizeof(ucArray) : %zu\n",sizeof(ucArray));
	// printf("sizeof(ucArray[0]) : %zu\n",sizeof(ucArray[0]));	

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "customTypes.h"

#define NAME_STR_MAX_SIZE (50)

typedef struct __attribute__((packed)) _USER_DATA_
{
	uint8 ucValue1;
	uint16 unValue2;
	uint32 ulValue3;
} USER_DATA;

// typedef union __attribute__((packed)) _USER_DATA_
// {
// 	uint8 ucValue1;
// 	uint16 unValue2;
// 	uint32 ulValue3;
// } USER_DATA;

// typedef struct _USER_DATA2_
// {
// 	uint32 ulValue3;
// 	uint16 unValue2;
// 	uint8 ucValue1;
// } USER_DATA2;

typedef union _USER_DATA2_
{
	uint8 ucValue1;
	uint16 unValue2;
	uint32 ulValue3;
} USER_DATA2;


int main()
{
	//uint8 ucArray[11] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0xa};
	uint8 ucArray[11] = {0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf1,0x08,0x09,0xa};
	USER_DATA *pData = (USER_DATA *) ucArray;

	USER_DATA data;
	USER_DATA2 data2;
	
	printf("ucValue1 = %02x\n", pData->ucValue1);
	printf("unValue2 = %04x\n", pData->unValue2);
	printf("ulValue3 = %lx\n", pData->ulValue3);

	//uint8 ucArray2[11] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0xa};
	uint8 ucArray2[11] = {0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf1,0x08,0x09,0xa};
	USER_DATA2 *pData2 = (USER_DATA2 *) ucArray2;
	printf("ucValue1 = %02x\n", pData2->ucValue1);
	printf("unValue2 = %04x\n", pData2->unValue2);
	printf("ulValue3 = %lx\n", pData2->ulValue3);

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
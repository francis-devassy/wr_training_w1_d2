#include <stdio.h>
#include "customTypes.h"

union data
{
	uint8 ucVal1;
	int32 lVal2;
};

int main()
{
	union data d1;
	d1.ucVal1 = 10;
	printf("printf d1.ucVal1 :%u\n",d1.ucVal1);
	d1.lVal2 = 1000;
	printf("printf d1.ucVal1 :%ld\n",d1.lVal2);
	printf("Size of union data : %zu\n",sizeof(d1));

	return 0;
}
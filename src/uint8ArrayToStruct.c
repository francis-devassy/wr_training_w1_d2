#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "customTypes.h"

#define NAME_STR_MAX_SIZE (50)

typedef struct _USER_DATA_
{
	uint8 ucName[NAME_STR_MAX_SIZE];
} USER_DATA;

int main()
{
	USER_DATA user1;
	uint8 ucReturn = 0;
	uint32 ulNameLength = 0;
	printf("Enter user name: ");
	ucReturn = fgets(user1.ucName, sizeof(user1.ucName), stdin);

	if(ucReturn != 0)
	{
		ulNameLength = strlen(user1.ucName);

		if((ulNameLength > 0) && 
			user1.ucName[ulNameLength - 1] == '\n')
		{
			user1.ucName[ulNameLength - 1] = '\0';
		}
	}
	printf("Entered name : %s\n", user1.ucName);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

// typedefs here...

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;
typedef signed char    int8;
typedef signed short   int16;
typedef signed long    int32;

typedef struct {
    uint8 id;
    int16 temperature;
    uint32 pressure;
} SensorData;

void printSensor(const SensorData *s) 
{
    printf("Sensor %u: Temp=%d, Pressure=%lu\n",
           s->id, s->temperature, s->pressure);
}

//Cppcheck style warning Parameter 'arr' can be declared as pointer to const
//uint32 sumArray(const uint16 *arr, uint8 size)

uint32 sumArray(uint16 *arr, uint8 size)
 {
    uint32 sum = 0;
    for (uint8 i = 0; i <= size; i++) 
	{   
        sum += arr[i];
    }
    return sum;
}

//style: Parameter 'arr' can be declared as pointer to const [constParameterPointer]
//int8 findMax(const int8 *arr, uint8 size) 
int8 findMax(int8 *arr, uint8 size) 
{
    int8 max; // Uninitialized
    for (uint8 i = 0; i < size; i++)
	 {
		//cppcheckBugCode.c:39:22: warning: Uninitialized variable: max [uninitvar]
        if (arr[i] > max) 
		{
            max = arr[i];
        }
    }
    return max;
}

int main() 
{
    SensorData s1 = {1, 25, 101325};
    SensorData s2 = {2, -5, 100800};

    printSensor(&s1);
    printSensor(&s2);

    uint16 values[5] = {100, 200, 300, 400, 500};
    uint32 total = sumArray(values, 5);
    printf("Total sum: %lu\n", total);

    int8 numbers[4] = {10, -3, 25, 7};
    int8 maxVal = findMax(numbers, 4);
    printf("Max value: %d\n", maxVal);

    //Memory leak: allocated but not freed
	// Cppcheck is a static analyzer: it inspects code paths but doesn’t execute them.
	// If the analyzer sees that the pointer data goes out of scope at program exit, 
	// it often assumes the OS will reclaim memory. That’s why it doesn’t always warn about 
	// missing free() calls in main()
    uint32 *data = (uint32*) malloc(10 * sizeof(uint32));
    for (uint8 i = 0; i < 10; i++) 
	{
        data[i] = i;
    }

    return 0;
}

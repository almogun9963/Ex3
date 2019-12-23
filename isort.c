#include <stdio.h>
#include "isort.h"

void shift_element (int* arr , int i)
{
	int pointer = *(arr + i);
	int temp = i;
	for (int j = 0; j <= i; j ++)
	{
		*(arr + temp) = *(arr + temp-1);
		pointer = pointer - 1;
	}
	*arr = pointer;
}






void insertion_sort (int* arr , int len)
{
	int pointer;
	int temp;
	for (int i = 1; i < len ; i++)
	{
		pointer = *(arr + i);
		temp = i - 1;
		while ( *(arr + temp) > pointer && temp >= 0 )
		{
			*(arr + temp + 1) = *(arr + temp);
			temp = temp -1;
		} 
		*(arr + temp + 1) = pointer;
	}
}





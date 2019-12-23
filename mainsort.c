#include <stdio.h>
#include "isort.h"
#include "isort.c"

int main ()
{
	int arr[size] = {0};
	printf("Enter the array that you want to sort by insertion sort :");
	for (int i = 0; i <= size-1; i++)
	{
		scanf ("%d", (arr + i));
	}
	insertion_sort (arr , size);
	
	for (int i = 0; i <= size - 1; i++)
	{
		printf("%d ", *(arr + i));
	}
	return 0;
}
#include <stdio.h>

int main()
{
	int arr[10];
	printf("The dimension of the array is %d", DIM(arr));
}
int DIM(int array[])
{
	return sizeof(array)/sizeof(int);
}


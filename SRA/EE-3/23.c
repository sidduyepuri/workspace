#define DIM( array, type) sizeof(array)/sizeof(type) 
main()
{
int arr[10];
printf("The dimension of the array is %d", DIM(arr, int));
}


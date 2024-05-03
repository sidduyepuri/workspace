main()
{
int a=10,*j; void *k; j=k=&a; j++;
k++;
printf("\n %u %u ",j,k);
}

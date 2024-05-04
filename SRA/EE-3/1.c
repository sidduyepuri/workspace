int swap(int *a,int *b)
{
	*a=*a+*b;*b=*a-*b;*a=*a-*b;
}
main()
{
	int x=10,y=20; 
	swap(&x,&y);
	printf("x= %d y = %d\n",x,y);
}

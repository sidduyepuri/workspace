void main()
{
	int *mptr, *cptr;
	mptr = (int*)malloc(sizeof(int)); 
	printf("%d",*mptr);
	cptr = (int*)calloc(sizeof(int),1); 
	printf("%d",*cptr);
}


main()
{
	int i;
	char a[]="String"; 
	char *p="New Sring"; 
	char *Temp;
	Temp=a; 
	a=malloc(strlen(p) + 1);
	strcpy(a,p); //Line number:9// p =
	malloc(strlen(Temp) + 1); 
	strcpy(p,Temp);
	printf("(%s, %s)",a,p); 
	free(p);
	free(a);
} //Line number 15//

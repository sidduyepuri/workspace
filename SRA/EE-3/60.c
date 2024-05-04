main()
{
	char *ptr1; char
		*ptr2;
	ptr1=(char *)malloc(25); 
	ptr2=(char *)malloc(25); 
	strcpy(ptr1,"SC"); 
	strcpy(ptr2,"Systems"); 
	strcat(ptr1,ptr2); printf("%s",ptr1);
}

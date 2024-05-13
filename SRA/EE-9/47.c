#include<stdio.h>
main()
{
	char *p1; 
	char *p2;
	p1=(char *) malloc(25); 
	p2=(char *) malloc(25); 
	strcpy(p1,"Ramco"); 
	strcpy(p2,"Systems"); 
	strcat(p1,p2); 
	printf("%s",p1);
}

#include <stdio.h>
#include <string.h>

//char *foo()
{
	char result[100];	
	strcpy(result,"anything is good"); 
	return result;
}
void main()
{
	char *j; 
	j=foo(); 
	printf("%s",j);
}


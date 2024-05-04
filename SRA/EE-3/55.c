#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char *k1="hitechskill.com"; 
	char *k2=(char*)malloc(20); 
	memset (k2, 0, 20); 
	while(*k2++=*k1++)
	       ;//printf("1\n");	
		printf("%s\n",k1);
}

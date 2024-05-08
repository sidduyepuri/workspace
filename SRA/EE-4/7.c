#include <stdio.h>
#include <string.h>
char* duplicate(char *str1);
int main()
{
	char *str1="einfochips";
	char *str2=duplicate(str1);
	printf("%s\n",str2);
	return 0;
}
char* duplicate(char *str1)
{
	int len=strlen(str1)+1,i=0;
	char *str2=(char *)malloc(len);
	if(str1==NULL)
		return NULL;
	else
		while(*(str2+i)=*(str1+i))
			i++;
	return str2;
}

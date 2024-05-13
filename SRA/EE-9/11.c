#include<stdio.h>
main()
{
	struct
	{
		char a; short
			b; int c;
	}temp;
	printf("%d",sizeof(temp));
}

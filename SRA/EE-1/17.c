#include<stdio.h>
main()
{
	struct xx
	{
		int x=3;
		char name[]="hello";
	};
	struct xx *s; printf("%d",s->x);
	printf("%s",s->name);
}


#include <stdio.h> 
main()
{
char * str = "hello"; char 
* ptr = str; char least = 
127; while (*ptr++)
least = (*ptr<least ) ?*ptr :least; 
printf("%d",least);
}

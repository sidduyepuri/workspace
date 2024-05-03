#include <string.h>
main()
{
int i, n;
char *x = "girl"; n = strlen(x);
*x = x[n]; for(i=0; i<n; ++i)
{
printf("%s\n",x); x++;
}
}


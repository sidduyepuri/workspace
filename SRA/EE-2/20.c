# include <stdio.h>
int one_d[]={1,2,3}; 
main()
{
int *ptr; ptr=one_d; ptr+=3; 
printf("%d",*ptr);
}

#include<stdio.h>
main()
{
int a[5],i,*ip; 
for(i=0;i<5;i++) 
a[i]=i;
ip=a; printf("%d",*(ip+3*sizeof(int)));
}

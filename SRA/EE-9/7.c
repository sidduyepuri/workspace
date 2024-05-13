#include<stdio.h>
#define swap(a,b) temp=a,a=b,b=temp; 
main()
{
int a=5,b=6; int
temp; if(a>b) 
swap(a,b);
printf("a=%d,b= %d",a,b);
}


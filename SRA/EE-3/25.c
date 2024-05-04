main()
{
static int a[3][3]={1,2,3,4,5,6,7,8,9};
int i,j;
static *p[]={a,a+1,a+2}; 
for(i=0;i<3;i++)
{
for(j=0;j<3;j++) 
printf("%d\t%d\t%d\t%d\n",*(*(p+i)+j),*(*(j+p)+i),*(*(i+p)+j),*(*(p+j)+i));
}
}

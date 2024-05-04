main()
{
int a=2,*f1,*f2; f1=f2=&a;
*f2+=*f2+=a+=2.5;
printf("\n%d %d %d",a,*f1,*f2);
}

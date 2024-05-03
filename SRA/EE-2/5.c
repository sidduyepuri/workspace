main()
{
int y;
scanf("%d",&y); // input given is 2000
if( (y%4==0 && y%100 != 0) || y%100 == 0)
printf("%d is a leap year",y);
else
printf("%d is not a leap year",y);
}


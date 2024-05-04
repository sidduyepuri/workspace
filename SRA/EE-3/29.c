main()
{
int i=300;
char *ptr = &i;
*++ptr=2; 
printf("%d",i);
}

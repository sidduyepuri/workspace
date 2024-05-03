main()
{
int i=1; while (i<=5)
{
printf("%d",i); if (i>2)
goto here; i++;
}
}
fun()
{
here:
printf("PP");
}


typedef struct error{int warning, error, exception;}error; 
main()
{
error g1; g1.error =1;
printf("%d",g1.error);
}

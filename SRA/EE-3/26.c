main()
{
void swap(); int
x=10,y=8; 
swap(&x,&y);
printf("x=%d y=%d",x,y);
}
void swap(int *a, int *b)
{
*a ^= *b, *b ^= *a, *a ^= *b;
}


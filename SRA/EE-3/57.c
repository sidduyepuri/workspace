#define swap(a,b) a=a+b;b=a-b;a=a-b;
void main()
{
int m=5, n=10;
swap (m,n);
printf("%d %d\n",m,n); 
swap2(m,n); 
printf("%d%d\n",m,n);
}
int swap2(int x, int y)
{
int temp;
temp=x; y=x;
x=temp; return 0;
}


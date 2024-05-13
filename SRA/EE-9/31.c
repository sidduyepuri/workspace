int f();
void main()
{ f(1);
	f(1,2);
	f(1,2,3);
}
f(int i,int j,int k)
{
	printf("%d %d %d\n",i,j,k);
}

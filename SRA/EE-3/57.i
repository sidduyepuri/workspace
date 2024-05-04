# 0 "57.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "57.c"

void main()
{
int m=5, n=10;
m=m+n;n=m-n;m=m-n;;;;
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

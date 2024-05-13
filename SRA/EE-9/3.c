int x;
int modifyvalue()
{
	return(x+=10);
}
int changevalue(int x)
{
	return(x+=1);
}
void main()
{
int x=10; x++;
changevalue(x); x++;
modifyvalue();
printf("First output:%d\n",x); x++;
changevalue(x);
printf("Second output:%d\n",x); 
modifyvalue();
printf("Third output:%d\n",x);
}

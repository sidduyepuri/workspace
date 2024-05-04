int main()
{
int i = 10,*ptr;
ptr= &i;
void *vptr; 
vptr = &ptr;
printf("\nValue of iptr = %d ",*ptr);
return 0;
}


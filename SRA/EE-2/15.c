struct point
{
int x; int y;
};
struct point origin,*pp; main()
{
pp=&origin;
printf("origin is(%d%d)\n",(*pp).x,(*pp).y); 
printf("origin is(%d%d)\n",pp->x,pp->y);
}

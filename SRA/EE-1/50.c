main ( )
{
static char *s[ ] = {"black", "white", "yellow", "violet"}; char **ptr[ ] = {s+3, 
s+2, s+1, s}, ***p;
p = ptr;
**++p;
printf("%s",*--*++p + 3);
}

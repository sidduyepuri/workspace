main()
{
char *p1="Name";
 char *p2;
 p2=(char *)malloc(20); while(*p2++=*p1++); printf("%s\n",p2);
}


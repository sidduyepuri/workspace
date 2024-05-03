main()
{
char c=' ',x,convert(z); getc(c);
if((c>='a') && (c<='z')) x=convert(c); 
printf("%c",x);
}
convert(z)
{
return z-32;
}

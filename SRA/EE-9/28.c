main()
{
	unsigned i=1; /* unsigned char k= -1 => k=255; */ 
	signed j=-1; /* char k= -1 => k=65535 */
	/* unsigned orsigned int k= -1 =>k=65535 */ 
	if(i<j)
		printf("less"); 
	else
		if(i>j) 
			printf("greater"); 
		else
			if(i==j) 
				printf("equal");
}
